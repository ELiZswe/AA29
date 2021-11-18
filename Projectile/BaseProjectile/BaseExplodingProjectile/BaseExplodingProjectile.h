// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AA29.h"
#include "AA29/Projectile/BaseProjectile/BaseProjectile.h"
#include "BaseExplodingProjectile.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABaseExplodingProjectile : public ABaseProjectile
{
	GENERATED_BODY()
public:
	ABaseExplodingProjectile(const FObjectInitializer& ObjectInitializer);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ExplosionSoundRadius;							//var float ExplosionSoundRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bSetRotation;									//var bool bSetRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bReachedCollision;								//var bool bReachedCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bHasStopped;									//var bool bHasStopped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float _fEffectDuration;								//var float _fEffectDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float _fAudIntensity;								//var float _fAudIntensity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector SavedLocation;								//var FVector SavedLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector SavedVelocity;								//var FVector SavedVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		ECollisionType SavedType;							//var BaseProjectile.ECollisionType SavedType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* SavedHitMaterial;				//var Material SavedHitMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector SavedHitNormal;								//var FVector SavedHitNormal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector SavedHitLocation;							//var FVector SavedHitLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AActor* SavedHitactor;								//var Actor SavedHitactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAlreadySaved;									//var bool bAlreadySaved;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sConcrete;						//var array<Sound> sConcrete;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sMuffled;						//var array<Sound> sMuffled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sWater;							//var array<Sound> sWater;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sMetal;							//var array<Sound> sMetal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sDirt;							//var array<Sound> sDirt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sWood;							//var array<Sound> sWood;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* ExplosionEmitter;						//var class<Emitter> ExplosionEmitter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf <class UaDamageType> FragDamageType;	//var class<DamageType> FragDamageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf <class UaDamageType> ImpactDamageType;	//var class<DamageType> ImpactDamageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ImpactDamage;									//var float ImpactDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ArmingTime;									//var float ArmingTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FObjectRange ArmingTimeRange;						//var Object.Range ArmingTimeRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool _bPlayedSound;									//var bool _bPlayedSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool _bResolvedState;								//var bool _bResolvedState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool ProjState;										//var EProjectileState ProjState;

};
