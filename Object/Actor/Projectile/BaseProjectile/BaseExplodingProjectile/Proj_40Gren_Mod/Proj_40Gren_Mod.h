// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "Proj_40Gren_Mod.generated.h"

UCLASS()
class AProj_40Gren_Mod : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AProj_40Gren_Mod(const FObjectInitializer& ObjectInitializer);

	void Boom(FVector HitLocation, FVector HitNormal);
};
