// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/xPickUpBase/xPickUpBase.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"


class USkeletalMesh;
class UMaterialInstance;

UCLASS()
class APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							bool bActiveOnTrigger;									//var() bool bActiveOnTrigger;
	UPROPERTY()															bool bDestroyOnMoverEncroach;							//var bool bDestroyOnMoverEncroach;
	UPROPERTY()															UStaticMesh* StaticMeshFull;							//var StaticMesh StaticMeshFull;
	UPROPERTY()															UStaticMesh* StaticMeshEmpty;							//var StaticMesh StaticMeshEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							TSubclassOf<class APickup> EnemyPickupClass;			//var() class<Pickup> EnemyPickupClass;
	UPROPERTY()															TSubclassOf<class APickup> Next;						//var Pickup Next;
	UPROPERTY()															uint8 idTeamOwner;										//var byte idTeamOwner;
	UPROPERTY()															bool bPlacedPickup;										//var bool bPlacedPickup;
	UPROPERTY()															TSubclassOf<class AController> TeamOwner;				//var Controller TeamOwner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							TSubclassOf<class AxPickUpBase> PickUpBase;				//var() xPickUpBase PickUpBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							FString PickupForce;									//var() string PickupForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							USoundBase* PickupSound;								//var() Sound PickupSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							FString PickupMessage;									//var() localized string PickupMessage;
	UPROPERTY()															float RespawnEffectTime;								//var float RespawnEffectTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							float RespawnTime;										//var() float RespawnTime;
	UPROPERTY()															bool bPredictRespawns;									//var bool bPredictRespawns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							bool bDropped;											//var bool bDropped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Display")		bool bAmbientGlow;										//var(Display) bool bAmbientGlow;
	UPROPERTY()															bool bOnlyReplicateHidden;								//var bool bOnlyReplicateHidden;
	UPROPERTY()															bool bInstantRespawn;									//var() bool bInstantRespawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							TSubclassOf<class AInventory> InventoryType;			//var() class<Inventory> InventoryType;
	UPROPERTY()															TSubclassOf<class ABaseScope> PickupCache;				//var NavigationPoint PickupCache;
	//UPROPERTY()														TSubclassOf<class AInventorySpot> myMarker;				//var InventorySpot myMarker;
	UPROPERTY()															float MaxDesireability;									//var float MaxDesireability;

	//FromActor:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							UTexture2D* Texture;
	UPROPERTY()															USkeletalMeshComponent* VisibleSkeletalMesh;
	UPROPERTY()															UStaticMeshComponent* VisibleStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							USkeletalMesh* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							UTexture2D* ActionIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							FRotator Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							FRotator RelativeRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							FRotator LandedRotationOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							bool bUseActionIcon;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)						int32 PickupAmmo;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)						bool bAllowPickup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							float DrawScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							bool bShouldFallOnSide;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							int32 LifeSpan;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							int32 CollisionRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							int32 CollisionHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							EDrawType DrawType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							FVector PrePivot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							uint8 AmbientGlow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							int32 CullDistance; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							FRotator RotationRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							USceneComponent* StaticMeshRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)							TArray<UMaterialInstance*> Skins;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddToNavigation();
	void RemoveFromNavigation();
	//void StaticPrecache(LevelInfo L);
	void PostBeginPlay();
	void MatchStarting();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void MatchEnding();
	void Destroyed();
	FString GetHumanReadableName() const;
	bool IsSuperItem();
	//void UpdateHUD(AHUD* H);
	void Reset();
	void RespawnEffect();
	APickup* Transmogrify(APickup*  NewClass);
	float DetourWeight(APawn* Other, float PathWeight);
	float BotDesireability(APawn* Bot);
	bool UseEnemyClass(AAA2_PlayerState* PRI);
	AInventory* GetInventoryClassFor(APawn* Other);
	AInventory* SpawnCopy(APawn* Other, bool bRealInventory);
	bool ValidTouch(AActor* Other);
	bool CanSpawnCopy(APawn* Other, bool bRealInventory);
	void SetupCopy(AInventory* Copy, APawn* Other);
	void PickupTaken();
	void StartSleeping();
	void AnnouncePickup(APawn* Receiver);
	void SetRespawn();
	FString GetLocalString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2);
	AInventory* TakeItem(AActor* Other);
	void InitDroppedPickupFor(AInventory* Inv, bool bFreeze);
	void MaybeAdjustCollisionSize();
	void MaybeSetStaticMesh();
	bool ReadyToPickup(float MaxWait);
	void Landed(FVector HitNormal);
	float GetRespawnTime();
};
