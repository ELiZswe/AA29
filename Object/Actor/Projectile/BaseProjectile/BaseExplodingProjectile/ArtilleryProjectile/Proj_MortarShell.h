// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/ArtilleryProjectile/ArtilleryProjectile.h"
#include "Proj_MortarShell.generated.h"

UCLASS()
class AProj_MortarShell : public AArtilleryProjectile
{
	GENERATED_BODY()
public:
	AProj_MortarShell(const FObjectInitializer& ObjectInitializer);
	
};
