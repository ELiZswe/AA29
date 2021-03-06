// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmMortar.h"
#include "Proj_60mmSmokeMortar.generated.h"

UCLASS()
class AProj_60mmSmokeMortar : public AProj_60mmMortar
{
	GENERATED_BODY()
public:
	AProj_60mmSmokeMortar(const FObjectInitializer& ObjectInitializer);

	
	UPROPERTY()		float	sndSmoke;			//var Sound sndSmoke;
	UPROPERTY()		bool	bSmokeRound;		//var bool bSmokeRound;

	void PreBeginPlay();
	bool IsEnemyProjectile();
	void PostBeginPlay();
	bool ShouldExplode();
	void Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
	void Boom(FVector HitLocation, FVector HitNormal);
};
