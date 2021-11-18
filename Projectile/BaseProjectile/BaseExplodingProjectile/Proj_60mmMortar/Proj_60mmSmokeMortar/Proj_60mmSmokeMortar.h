// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmMortar.h"
#include "Proj_60mmSmokeMortar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_60mmSmokeMortar : public AProj_60mmMortar
{
	GENERATED_BODY()
public:
	AProj_60mmSmokeMortar(const FObjectInitializer& ObjectInitializer);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float sndSmoke;			//var Sound sndSmoke;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bSmokeRound;		//var bool bSmokeRound;
};
