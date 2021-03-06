// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "Ammunition.generated.h"


class APickup;
class AProjectile;
class AWeapon;
UCLASS()
class AAmmunition : public AInventory
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
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	bool HandlePickupQuery(APickup* Item);
	bool AddAmmo(int32 AmmoToAdd);
	AProjectile* SpawnProjectile(FVector Start, FRotator Dir);
	float GetDamageRadius();
	void DecrementAmmo();
	void UseBullet(FVector StartTrace, FRotator Direction);
	void ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength);
	void NPC_ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength);
};
