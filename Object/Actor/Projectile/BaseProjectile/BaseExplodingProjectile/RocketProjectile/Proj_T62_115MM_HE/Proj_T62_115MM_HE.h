// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/RocketProjectile.h"
#include "Proj_T62_115MM_HE.generated.h"

UCLASS()
class AProj_T62_115MM_HE : public ARocketProjectile
{
	GENERATED_BODY()
public:
	AProj_T62_115MM_HE(const FObjectInitializer& ObjectInitializer);
};
