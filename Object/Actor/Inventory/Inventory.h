// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "GameFramework/Actor.h"
#include "Inventory.generated.h"


class UStaticMesh;
class AInvContainer;
class AWeapon;
class APickup;
class UaDamageType;
class AArmor;
class APowerups;

UCLASS()
class AA29_API AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FString					ItemName;									//var() localized string ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FIntBox					IconCoords;									//var() Object.IntBox IconCoords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								UMaterialInstance*		IconMaterial;								//var() Material IconMaterial;
	UPROPERTY()																TArray<TSubclassOf<class AInventoryAttachment>> AttachmentClass;	//var class<InventoryAttachment> AttachmentClass;
	UPROPERTY()																AActor*					ThirdPersonActor;							//var Actor ThirdPersonActor;
	UPROPERTY()																bool					bUseAttachment;								//var bool bUseAttachment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float					BobDamping;									//var() float BobDamping;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)								bool					bDrawingFirstPerson;						//var() bool bDrawingFirstPerson;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FirstPerson")		FRotator				PlayerViewPivot;							//var(FirstPerson) Object.Rotator PlayerViewPivot;
	UPROPERTY()																FVector					PlayerViewOffset;							//var FVector PlayerViewOffset;
	UPROPERTY()																bool					bDrawOnHUD;									//var bool bDrawOnHUD;
	UPROPERTY()																bool					bUseInstigatorRotation;						//var bool bUseInstigatorRotation;
	UPROPERTY()																bool					bVirtualInventory;							//var bool bVirtualInventory;
	UPROPERTY()																uint8					idTeamOwner;								//var byte idTeamOwner;
	UPROPERTY()																float					fWeight;									//var float fWeight;
	UPROPERTY()																bool					_bHandsOnly;								//var bool _bHandsOnly;
	UPROPERTY()																bool					_bLarge;									//var bool _bLarge;
	UPROPERTY()																TSubclassOf<AInventory> Next;										//var Inventory Next;
	UPROPERTY()																TSubclassOf<AInventory> Prev;										//var Inventory Prev;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32					Charge;										//var() travel int Charge;
	UPROPERTY()																TSubclassOf<class APickup> PickupClass;								//var class<Pickup> PickupClass;
	UPROPERTY()																bool					bTossedOut;									//var bool bTossedOut;
	UPROPERTY()																bool					bDisplayableInv;							//var bool bDisplayableInv;
	UPROPERTY()																uint8					GroupOffset;								//var byte GroupOffset;
	UPROPERTY()																uint8					InventoryGroup;								//var byte InventoryGroup;
	
	//From Actor:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								USkeletalMesh* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float DrawScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								EDrawType DrawType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FName InitialState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								TSubclassOf<AInventory> Inventory;													//var inventory inventory
	//void StaticPrecache(LevelInfo L)
	
	bool IsSniperRifle();
	bool IsJavelin();
	void AttachToPawn(APawn* p);
	void updaterelative(int32 Pitch, int32 Yaw, int32 Roll);
	void DetachFromPawn(APawn* p, bool bPreserveWeapon);
	void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);
	UFUNCTION(BlueprintCallable)		virtual FString GetHumanReadableName() const;
	void PickupFunction(APawn* Other);
	AWeapon* RecommendWeapon(float rating);
	void TravelPreAccept();
	void TravelPostAccept();
	void Destroyed();
	void GiveTo(APawn* Other, APickup* Pickup);
	void SetTeamOwner();
	bool HandlePickupQuery(APickup* Item);
	APowerups* SelectNext();
	APickup* DropFrom(FVector StartLocation, bool bAttach);
	void Use(float Value);
	AWeapon* WeaponChange(uint8 F, bool bSilent);
	AWeapon* PrevWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon);
	AWeapon* NextWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon);
	AArmor* PrioritizeArmor(int32 Damage, UaDamageType* DamageType, FVector HitLocation);
	void OwnerEvent(FName EventName);
	void SetOwnerDisplay();
	FString StaticItemName();
	bool isLarge();
	bool isHandsOnly();
	bool VirtualWeapon();
	AInvContainer* GetSwapContainer();
	void InitFor(AInventory* Inv);
	void NotifyNewParachuteState(int32 NewState);
	FString DisplayDebugMessage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
