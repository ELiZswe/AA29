// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/RocketProjectile.h"
#include "Proj_PG7VR_Demolition.generated.h"

UCLASS()
class AProj_PG7VR_Demolition : public ARocketProjectile
{
	GENERATED_BODY()
public:
	AProj_PG7VR_Demolition(const FObjectInitializer& ObjectInitializer);
};
