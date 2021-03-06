// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AA29.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "BaseExplodingProjectile.generated.h"

UCLASS()
class ABaseExplodingProjectile : public ABaseProjectile
{
	GENERATED_BODY()
public:
	ABaseExplodingProjectile(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(EditAnywhere)		float					ExplosionSoundRadius;			//var float ExplosionSoundRadius;
	UPROPERTY(EditAnywhere)		bool					bSetRotation;					//var bool bSetRotation;
	UPROPERTY(EditAnywhere)		bool					bReachedCollision;				//var bool bReachedCollision;
	UPROPERTY(EditAnywhere)		bool					bHasStopped;					//var bool bHasStopped;
	UPROPERTY(EditAnywhere)		float					_fEffectDuration;				//var float _fEffectDuration;
	UPROPERTY(EditAnywhere)		float					_fAudIntensity;					//var float _fAudIntensity;
	UPROPERTY(EditAnywhere)		FVector					SavedLocation;					//var FVector SavedLocation;
	UPROPERTY(EditAnywhere)		FVector					SavedVelocity;					//var FVector SavedVelocity;
	UPROPERTY(EditAnywhere)		ECollisionType			SavedType;						//var BaseProjectile.ECollisionType SavedType;
	UPROPERTY(EditAnywhere)		UMaterialInstance*		SavedHitMaterial;				//var Material SavedHitMaterial;
	UPROPERTY(EditAnywhere)		FVector					SavedHitNormal;					//var FVector SavedHitNormal;
	UPROPERTY(EditAnywhere)		FVector					SavedHitLocation;				//var FVector SavedHitLocation;
	UPROPERTY(EditAnywhere)		AActor*					SavedHitactor;					//var Actor SavedHitactor;
	UPROPERTY(EditAnywhere)		bool					bAlreadySaved;					//var bool bAlreadySaved;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		sConcrete;						//var array<Sound> sConcrete;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		sMuffled;						//var array<Sound> sMuffled;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		sWater;							//var array<Sound> sWater;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		sMetal;							//var array<Sound> sMetal;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		sDirt;							//var array<Sound> sDirt;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		sWood;							//var array<Sound> sWood;
	UPROPERTY(EditAnywhere)		AEmitter*				ExplosionEmitter;				//var class<Emitter> ExplosionEmitter;
	UPROPERTY(EditAnywhere)		TSubclassOf <class UaDamageType> FragDamageType;		//var class<DamageType> FragDamageType;
	UPROPERTY(EditAnywhere)		TSubclassOf <class UaDamageType> ImpactDamageType;		//var class<DamageType> ImpactDamageType;
	UPROPERTY(EditAnywhere)		float					ImpactDamage;					//var float ImpactDamage;
	UPROPERTY(EditAnywhere)		float					ArmingTime;						//var float ArmingTime;
	UPROPERTY(EditAnywhere)		FObjectRange			ArmingTimeRange;				//var Object.Range ArmingTimeRange;
	UPROPERTY(EditAnywhere)		bool					_bPlayedSound;					//var bool _bPlayedSound;
	UPROPERTY(EditAnywhere)		bool					_bResolvedState;				//var bool _bResolvedState;
	UPROPERTY(EditAnywhere)		bool					ProjState;						//var EProjectileState ProjState;

	void BeginPlay();
	void Boom(FVector HitLocation, FVector HitNormal);
	void HandleDestroyCall();
	bool ShouldExplode();
	void Timer();
	bool IsInstigator(AActor* Other);
	void Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
	//void TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial);
	void PlayLandedSound(UMaterialInstance* HitMaterial);
};
