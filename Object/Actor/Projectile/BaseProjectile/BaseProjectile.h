// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "BaseProjectile.generated.h"

class AEmitter;
class ABaseProjectile;

UCLASS()
class ABaseProjectile : public AProjectile
{
	GENERATED_BODY()
public:
	ABaseProjectile(const FObjectInitializer& ObjectInitializer);

		
	UPROPERTY(EditAnywhere)		uint8							idTeamOwner;				//var byte idTeamOwner;
	UPROPERTY(EditAnywhere)		TSubclassOf<ABaseProjectile>	EnemyProjectileClass;		//var class<BaseProjectile> EnemyProjectileClass;
	UPROPERTY(EditAnywhere)		USoundBase*						ExplosionSound;				//var Sound ExplosionSound;
	UPROPERTY(EditAnywhere)		AEmitter*						TrailEmitter;				//var Emitter TrailEmitter;
	UPROPERTY(EditAnywhere)		AEmitter*						cTrailEmitterClass;			//var class<Emitter> cTrailEmitterClass;
	UPROPERTY(EditAnywhere)		float							fAtmoFactor;				//var float fAtmoFactor;
	UPROPERTY(EditAnywhere)		float							fWindFactor;				//var float fWindFactor;
	UPROPERTY(EditAnywhere)		float							fKillRadius;				//var float fKillRadius;
	UPROPERTY(EditAnywhere)		TArray<AActor*>					DamageClasses;				//var array<class<Actor> > DamageClasses;

	void PreBeginPlay();
	bool IsEnemyProjectile();
	void MaybeSetStaticMesh();
	void BeginPlay();
	void PostBeginPlay();
	void PostNetBeginPlay();
	void SetupProjectile();
	void Destroyed();
	void StopTrail();
	void Collision(AActor* Other, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
};
