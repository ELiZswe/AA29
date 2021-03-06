// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/RocketProjectile.h"
#include "Proj_AT4_Explosive.generated.h"

UCLASS()
class AProj_AT4_Explosive : public ARocketProjectile
{
	GENERATED_BODY()
public:
	AProj_AT4_Explosive(const FObjectInitializer& ObjectInitializer);
};
