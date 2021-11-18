// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmMortar.h"
#include "Proj_60mmTrainingMortar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_60mmTrainingMortar : public AProj_60mmMortar
{
	GENERATED_BODY()
public:
	AProj_60mmTrainingMortar(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float sndSmoke;				//var Sound sndSmoke;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bSmokeRound;			//var bool bSmokeRound;
};
