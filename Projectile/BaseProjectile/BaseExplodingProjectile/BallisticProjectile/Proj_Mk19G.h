// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/BallisticProjectile.h"
#include "Proj_Mk19G.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_Mk19G : public ABallisticProjectile
{
	GENERATED_BODY()
public:
	AProj_Mk19G(const FObjectInitializer& ObjectInitializer);
};
