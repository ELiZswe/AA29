// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/InventoryAttachment.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "WeaponAttachment.generated.h"

class AInventory;

UCLASS()
class AWeaponAttachment : public AInventoryAttachment
{
	GENERATED_BODY()
public:
	AWeaponAttachment();
	
	UPROPERTY()		int32 TurretYaw;							//var int TurretYaw;
	UPROPERTY()		int32 TurretPitch;							//var int TurretPitch;
	UPROPERTY()		bool bReplicateTurret;						//var bool bReplicateTurret;
	UPROPERTY()		bool bDoMove;								//var bool bDoMove;
	UPROPERTY()		bool bDoFlash;								//var bool bDoFlash;
	UPROPERTY()		bool bDoTrace;								//var bool bDoTrace;
	UPROPERTY()		bool bLaserOn;								//var bool bLaserOn;
	UPROPERTY()		bool bMatchWeapons;							//var bool bMatchWeapons;
	UPROPERTY()		bool bAutoFire;								//var bool bAutoFire;
	UPROPERTY()		uint8 TraceCount;							//var byte TraceCount;
	UPROPERTY()		uint8 FWMeshCount;							//var byte FWMeshCount;
	UPROPERTY()		uint8 SpawnHitCount;						//var byte SpawnHitCount;
	UPROPERTY()		uint8 FlashCount;							//var byte FlashCount;
	UPROPERTY()		APawn* TurretController;					//var Pawn TurretController;
	UPROPERTY()		TArray<EBulletImpactType> BulletImpact;		//var Object.EBulletImpactType BulletImpact;
	UPROPERTY()		FColor BeaconColor;							//var Object.Color BeaconColor;
	UPROPERTY()		FVector mHitLocation;						//var FVector mHitLocation;
	UPROPERTY()		float FiringSpeed;							//var float FiringSpeed;
	UPROPERTY()		FName FiringMode;							//var name FiringMode;
	UPROPERTY()		TArray<FPrecisionVector> BulletTrace;		//var Object.PrecisionVector BulletTrace;

	//remaining:
	//var class<Actor> SplashEffect;

	void DestroyAR3P();
	void SpawnAndAttachAR3P();
	void ThirdPersonEffects();
	void CheckForSplash();
	void UpdateHit(AActor* HitActor, FVector HitLocation, FVector HitNormal);
	void moveTurret();
	void VerifyMesh();
	void SetLaser();
	int32 GetMaxBulletTraces();
	FName GetAttachBoneFor(AInventory* Inv);
	void AdjustAttachmentFor(AInventory* Inv);
	void AttachmentAnimation();
	void ThirdPersonTrace();
};
