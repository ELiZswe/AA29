// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "Proj_40Gren.generated.h"

UCLASS()
class AProj_40Gren : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AProj_40Gren(const FObjectInitializer& ObjectInitializer);

	void Boom(FVector HitLocation, FVector HitNormal);
};
