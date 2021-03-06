// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_40Gren/Proj_40Gren.h"
#include "Proj_SmokeGren.generated.h"

UCLASS()
class AProj_SmokeGren : public AProj_40Gren
{
	GENERATED_BODY()
public:
	AProj_SmokeGren(const FObjectInitializer& ObjectInitializer);
};
