// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "Proj_60mmMortar.generated.h"

UCLASS()
class AProj_60mmMortar : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AProj_60mmMortar(const FObjectInitializer& ObjectInitializer);

	void PostNetBeginPlay();
	void PreBeginPlay();
	bool IsEnemyProjectile();
	void PostBeginPlay();
	void BeginPlay();
	void Boom(FVector HitLocation, FVector HitNormal);
};
