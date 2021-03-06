// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "Proj_MK19Gren.generated.h"

UCLASS()
class AProj_MK19Gren : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AProj_MK19Gren(const FObjectInitializer& ObjectInitializer);

	void Boom(FVector HitLocation, FVector HitNormal);
};
