// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "Proj_60mmMortar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_60mmMortar : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AProj_60mmMortar(const FObjectInitializer& ObjectInitializer);
};
