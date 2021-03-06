// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/RocketProjectile.h"
#include "MissileProjectile.generated.h"

UCLASS()
class AMissileProjectile : public ARocketProjectile
{
	GENERATED_BODY()
public:
	AMissileProjectile(const FObjectInitializer& ObjectInitializer);
	
};
