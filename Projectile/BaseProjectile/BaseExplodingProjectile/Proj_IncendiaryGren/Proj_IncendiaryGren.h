// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "Proj_IncendiaryGren.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_IncendiaryGren : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AProj_IncendiaryGren(const FObjectInitializer& ObjectInitializer);
};
