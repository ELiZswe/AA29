// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/Pickup.h"
#include "AGP_WeaponPickup.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_WeaponPickup : public APickup
{
	GENERATED_BODY()
public:
	AAGP_WeaponPickup();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttachMods")		TSubclassOf<class ABaseWeaponMod> Attach_Barrel;				//var(AttachMods) class<BaseWeaponMod> Attach_Barrel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachMods")	TSubclassOf<class ABaseWeaponMod> Attach_RailBottom;			//var(AttachMods) class<BaseWeaponMod> Attach_RailBottom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachMods")	TSubclassOf<class ABaseWeaponMod> Attach_RailRight;				//var(AttachMods) class<BaseWeaponMod> Attach_RailRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachMods")	TSubclassOf<class ABaseWeaponMod> Attach_RailLeft;				//var(AttachMods) class<BaseWeaponMod> Attach_RailLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachMods")	TSubclassOf<class ABaseWeaponMod> Attach_RailFront;				//var(AttachMods) class<BaseWeaponMod> Attach_RailFront;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachMods")	TSubclassOf<class ABaseWeaponMod> Attach_RailTop;				//var(AttachMods) class<BaseWeaponMod> Attach_RailTop;
	//UPROPERTY()															TSubclassOf<class AAttachmentHandler> AttachHandler;		//var AttachmentHandler AttachHandler;
	UPROPERTY()																bool bAttachMILESBox;											//var bool bAttachMILESBox;
	UPROPERTY()																TSubclassOf<class AActor> BlankPlug;							//var Actor BlankPlug;
	UPROPERTY()																TSubclassOf<class AActor> MILESBox;								//var Actor MILESBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")		float CollisionHeightDropped;									//var(Pickup) float CollisionHeightDropped;
	//UPROPERTY()															TSubclassOf<class AAI_Stats> Stats;							//var AI_Stats Stats;


	//void StaticPrecache (LevelInfo L);
	void PostBeginPlay();
	void LoadStartupMods();
	void BotDesireability(APawn* Bot);
	void MaybeSetStaticMesh();
	void AttachToMe(AActor* att, FVector offset);
	void InitDroppedPickupFor(AInventory* Inv, bool bFreeze);
	void SpawnMILESAttachments();
	void Destroyed();
	void MaybeAdjustCollisionSize();
	void SignalBlackhawkToLand();


};
