// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "ArtilleryProjectile.generated.h"

UCLASS()
class AArtilleryProjectile : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AArtilleryProjectile(const FObjectInitializer& ObjectInitializer);
	
};
