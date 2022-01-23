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
class ALevelInfo;

UCLASS()
class AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AInventory();

	UPROPERTY(EditAnywhere)								FString					ItemName;									//var() localized string ItemName;
	UPROPERTY(EditAnywhere)								FIntBox					IconCoords;									//var() Object.IntBox IconCoords;
	UPROPERTY(EditAnywhere)								UMaterialInstance*		IconMaterial;								//var() Material IconMaterial;
	UPROPERTY()											TArray<TSubclassOf<class AInventoryAttachment>> AttachmentClass;	//var class<InventoryAttachment> AttachmentClass;
	UPROPERTY()											AActor*					ThirdPersonActor;							//var Actor ThirdPersonActor;
	UPROPERTY()											bool					bUseAttachment;								//var bool bUseAttachment;
	UPROPERTY(EditAnywhere)								float					BobDamping;									//var() float BobDamping;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)			bool					bDrawingFirstPerson;						//var() bool bDrawingFirstPerson;
	UPROPERTY(EditAnywhere, Category="FirstPerson")		FRotator				PlayerViewPivot;							//var(FirstPerson) Object.Rotator PlayerViewPivot;
	UPROPERTY()											FVector					PlayerViewOffset;							//var FVector PlayerViewOffset;
	UPROPERTY()											bool					bDrawOnHUD;									//var bool bDrawOnHUD;
	UPROPERTY()											bool					bUseInstigatorRotation;						//var bool bUseInstigatorRotation;
	UPROPERTY()											bool					bVirtualInventory;							//var bool bVirtualInventory;
	UPROPERTY()											uint8					idTeamOwner;								//var byte idTeamOwner;
	UPROPERTY()											float					fWeight;									//var float fWeight;
	UPROPERTY()											bool					_bHandsOnly;								//var bool _bHandsOnly;
	UPROPERTY()											bool					_bLarge;									//var bool _bLarge;
	UPROPERTY()											TSubclassOf<AInventory> Next;										//var Inventory Next;
	UPROPERTY()											TSubclassOf<AInventory> Prev;										//var Inventory Prev;
	UPROPERTY(EditAnywhere)								int32					Charge;										//var() travel int Charge;
	UPROPERTY()											TSubclassOf<class APickup> PickupClass;								//var class<Pickup> PickupClass;
	UPROPERTY()											bool					bTossedOut;									//var bool bTossedOut;
	UPROPERTY()											bool					bDisplayableInv;							//var bool bDisplayableInv;
	UPROPERTY()											uint8					GroupOffset;								//var byte GroupOffset;
	UPROPERTY()											uint8					InventoryGroup;								//var byte InventoryGroup;
	
	//From Actor:
	UPROPERTY(EditAnywhere)								UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere)								USkeletalMesh* Mesh;
	UPROPERTY(EditAnywhere)								float DrawScale;
	UPROPERTY(EditAnywhere)								EDrawType DrawType;
	UPROPERTY(EditAnywhere)								FName InitialState;
	UPROPERTY(EditAnywhere)								TSubclassOf<AInventory> Inventory;													//var inventory inventory

	void StaticPrecache(ALevelInfo* L);
	bool IsSniperRifle();
	bool IsJavelin();
	void AttachToPawn(APawn* p);
	void updaterelative(int32 Pitch, int32 Yaw, int32 Roll);
	void DetachFromPawn(APawn* p, bool bPreserveWeapon);
	void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);
	UFUNCTION(BlueprintCallable)		virtual FString GetHumanReadableName() const;
	void PickupFunction(APawn* Other);
	AWeapon* RecommendWeapon(float& rating);
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
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
};
