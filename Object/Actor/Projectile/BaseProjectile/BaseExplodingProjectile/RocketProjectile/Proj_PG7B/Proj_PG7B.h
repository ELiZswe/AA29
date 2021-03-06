// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/RocketProjectile.h"
#include "Proj_PG7B.generated.h"

UCLASS()
class AProj_PG7B : public ARocketProjectile
{
	GENERATED_BODY()
public:
	AProj_PG7B(const FObjectInitializer& ObjectInitializer);
};
