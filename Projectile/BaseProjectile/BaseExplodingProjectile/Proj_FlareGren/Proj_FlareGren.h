// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "Proj_FlareGren.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_FlareGren : public ABaseExplodingProjectile
{
	GENERATED_BODY()
public:
	AProj_FlareGren(const FObjectInitializer& ObjectInitializer);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bFlareOn;		//var bool bFlareOn;
};
