// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AGP_Ammunition.generated.h"




//remaining:
//var class<Projectile> _cTracerClass;


class AProjectile;
class AWeapon;
UCLASS()
class AAGP_Ammunition : public AAmmunition
{
	GENERATED_BODY()
public:
	AAGP_Ammunition();

	UPROPERTY()		int32			Damage;					//var int32 Damage;
	UPROPERTY()		float			MomentumTransfer;		//var float MomentumTransfer;
	UPROPERTY()		AProjectile*	_cTracerClass;			//var AProjectile* _cTracerClass;
	UPROPERTY()		int32			_iTracerCount;			//var int32 _iTracerCount;

	void PreBeginPlay();
	bool IncrementTracer(FVector Start, FRotator Dir);
	void UseBullet(FVector StartTrace, FRotator Direction);
	void DecrementAmmo();
	void ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength);
	void NPC_ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength);
	AProjectile* SpawnProjectile(FVector Start, FRotator Dir);
	FString GetHumanReadableName() const;
};
