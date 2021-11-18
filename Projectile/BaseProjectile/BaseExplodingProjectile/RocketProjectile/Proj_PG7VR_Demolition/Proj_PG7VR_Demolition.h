// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/RocketProjectile.h"
#include "Proj_PG7VR_Demolition.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_PG7VR_Demolition : public ARocketProjectile
{
	GENERATED_BODY()
public:
	AProj_PG7VR_Demolition(const FObjectInitializer& ObjectInitializer);
};
