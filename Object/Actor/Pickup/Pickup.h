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
class ALevelInfo;
class AAA2_HUD;
class AInventory;

UCLASS()
class APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	APickup();
	
	UPROPERTY(EditAnywhere)							bool bActiveOnTrigger;									//var() bool bActiveOnTrigger;
	UPROPERTY()										bool bDestroyOnMoverEncroach;							//var bool bDestroyOnMoverEncroach;
	UPROPERTY()										UStaticMesh* StaticMeshFull;							//var StaticMesh StaticMeshFull;
	UPROPERTY()										UStaticMesh* StaticMeshEmpty;							//var StaticMesh StaticMeshEmpty;
	UPROPERTY(EditAnywhere)							TSubclassOf<class APickup> EnemyPickupClass;			//var() class<Pickup> EnemyPickupClass;
	UPROPERTY()										TSubclassOf<class APickup> Next;						//var Pickup Next;
	UPROPERTY()										uint8 idTeamOwner;										//var byte idTeamOwner;
	UPROPERTY()										bool bPlacedPickup;										//var bool bPlacedPickup;
	UPROPERTY()										TArray<TSubclassOf<class AController>> TeamOwner;				//var Controller TeamOwner;
	UPROPERTY(EditAnywhere)							TSubclassOf<class AxPickUpBase> PickUpBase;				//var() xPickUpBase PickUpBase;
	UPROPERTY(EditAnywhere)							FString PickupForce;									//var() string PickupForce;
	UPROPERTY(EditAnywhere)							USoundBase* PickupSound;								//var() Sound PickupSound;
	UPROPERTY(EditAnywhere)							FString PickupMessage;									//var() localized string PickupMessage;
	UPROPERTY()										float RespawnEffectTime;								//var float RespawnEffectTime;
	UPROPERTY(EditAnywhere)							float RespawnTime;										//var() float RespawnTime;
	UPROPERTY()										bool bPredictRespawns;									//var bool bPredictRespawns;
	UPROPERTY(EditAnywhere)							bool bDropped;											//var bool bDropped;
	UPROPERTY(EditAnywhere, Category="Display")		bool bAmbientGlow;										//var(Display) bool bAmbientGlow;
	UPROPERTY()										bool bOnlyReplicateHidden;								//var bool bOnlyReplicateHidden;
	UPROPERTY()										bool bInstantRespawn;									//var() bool bInstantRespawn;
	UPROPERTY(EditAnywhere)							TSubclassOf<class AInventory> InventoryType;			//var() class<Inventory> InventoryType;
	UPROPERTY()										TSubclassOf<class ABaseScope> PickupCache;				//var NavigationPoint PickupCache;
	UPROPERTY()										TSubclassOf<class AInventorySpot> myMarker;				//var InventorySpot myMarker;
	UPROPERTY()										float MaxDesireability;									//var float MaxDesireability;

	//FromActor:
	UPROPERTY(EditAnywhere)							UTexture2D* Texture;
	UPROPERTY()										USkeletalMeshComponent* VisibleSkeletalMesh;
	UPROPERTY()										UStaticMeshComponent* VisibleStaticMesh;
	UPROPERTY(EditAnywhere)							UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere)							USkeletalMesh* Mesh;
	UPROPERTY(EditAnywhere)							UTexture2D* ActionIcon;
	UPROPERTY(EditAnywhere)							FRotator Rotation;
	UPROPERTY(EditAnywhere)							FRotator RelativeRotation;
	UPROPERTY(EditAnywhere)							FRotator LandedRotationOffset;
	UPROPERTY(EditAnywhere)							bool bUseActionIcon;
	UPROPERTY(EditAnywhere)							int32 PickupAmmo;
	UPROPERTY(EditAnywhere)							bool bAllowPickup;
	UPROPERTY(EditAnywhere)							float DrawScale;
	UPROPERTY(EditAnywhere)							bool bShouldFallOnSide;
	UPROPERTY(EditAnywhere)							int32 LifeSpan;
	UPROPERTY(EditAnywhere)							int32 CollisionRadius;
	UPROPERTY(EditAnywhere)							int32 CollisionHeight;
	UPROPERTY(EditAnywhere)							EDrawType DrawType;
	UPROPERTY(EditAnywhere)							FVector PrePivot;
	UPROPERTY(EditAnywhere)							uint8 AmbientGlow;
	UPROPERTY(EditAnywhere)							int32 CullDistance; 
	UPROPERTY(EditAnywhere)							FRotator RotationRate;
	UPROPERTY(EditAnywhere)							USceneComponent* StaticMeshRoot;
	UPROPERTY(EditAnywhere)							TArray<UMaterialInstance*> Skins;
	
protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	void AddToNavigation();
	void RemoveFromNavigation();
	void StaticPrecache(ALevelInfo* L);
	void PostBeginPlay();
	void MatchStarting();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void MatchEnding();
	void Destroyed();
	FString GetHumanReadableName() const;
	bool IsSuperItem();
	//void UpdateHUD(AAA2_HUD* H);
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
	bool MaybeSetStaticMesh();
	bool ReadyToPickup(float MaxWait);
	void Landed(FVector HitNormal);
	float GetRespawnTime();
};
