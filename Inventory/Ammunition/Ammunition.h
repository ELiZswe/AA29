// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Inventory.h"
#include "Ammunition.generated.h"

/**
 * 
 */

UCLASS()
class AA29_API AAmmunition : public AInventory
{
	GENERATED_BODY()
public:
	AAmmunition();
	
	UPROPERTY()		UTexture2D* IconFlashMaterial;
	UPROPERTY()		float MaxRange;
	UPROPERTY()		float RefireRate;
	UPROPERTY()		float WarnTargetPct;
	UPROPERTY()		bool bTryHeadShot;
	UPROPERTY()		bool bSplashDamage;
	UPROPERTY()		bool bInstantHit;
	UPROPERTY()		bool bLeadTarget;
	UPROPERTY()		bool bTrySplash;
	UPROPERTY()		bool bTossed;
	UPROPERTY()		bool bRecommendSplashDamage;
	UPROPERTY()		int32 PickupAmmo;
	UPROPERTY()		int32 InitialAmount;
	UPROPERTY()		int32 AmmoAmount;
	UPROPERTY()		int32 MaxAmmo;
	UPROPERTY()		USoundBase* FireSound;
	UPROPERTY()		TSubclassOf<class UDamageType> MyDamageType;
	UPROPERTY()		TSubclassOf<class AProjectile> ProjectileClass;



	void CheckOutOfAmmo();
	bool UseAmmo(int32 AmountNeeded, bool bAmountNeededIsMax);
	bool HasAmmo();
	//void DisplayDebug(UCanvas* Canvas, float YL, float YPos);
	void HandlePickupQuery(APickup* Item);
	void AddAmmo(int32 AmmoToAdd);
	void SpawnProjectile(FVector Start, FRotator Dir);
	float GetDamageRadius();
	void DecrementAmmo();
	void UseBullet(FVector StartTrace, FRotator Direction);
	//void ProcessTraceHit(Weapon W, FVector StartTrace, FRotator Direction, Actor HitActor, Actor.BoneInfo HitBone, FVector HitLocation, FVector HitNormal, Material HitMaterial, FVector X, FVector Y, FVector Z, float fStrength);
	//void NPC_ProcessTraceHit(Weapon W, FVector StartTrace, FRotator Direction, Actor HitActor, Actor.BoneInfo HitBone, FVector HitLocation, FVector HitNormal, Material HitMaterial, FVector X, FVector Y, FVector Z, float fStrength);



};
