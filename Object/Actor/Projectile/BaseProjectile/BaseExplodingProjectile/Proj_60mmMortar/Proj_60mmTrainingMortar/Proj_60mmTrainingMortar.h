// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmMortar.h"
#include "Proj_60mmTrainingMortar.generated.h"

UCLASS()
class AProj_60mmTrainingMortar : public AProj_60mmMortar
{
	GENERATED_BODY()
public:
	AProj_60mmTrainingMortar(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY()		USoundBase* sndSmoke;			//var Sound sndSmoke;
	UPROPERTY()		bool bSmokeRound;				//var bool bSmokeRound;

	void PreBeginPlay();
	bool IsEnemyProjectile();
	void PostBeginPlay();
	void BeginPlay();
	bool ShouldExplode();
	void Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
	void Boom(FVector HitLocation, FVector HitNormal);
};
