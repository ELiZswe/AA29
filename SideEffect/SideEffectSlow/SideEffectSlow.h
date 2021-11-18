// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/SideEffect/SideEffect.h"
#include "SideEffectSlow.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASideEffectSlow : public ASideEffect
{
	GENERATED_BODY()
	
public:
	ASideEffectSlow();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float FadeTimeProportion;						//var float FadeTimeProportion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class AAGP_Pawn> AffectedPawn;		//var AGP_Pawn AffectedPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ElapsedTime;								//var float ElapsedTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float OldSpeedPenalty;							//var float OldSpeedPenalty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float SpeedPenalty;								//var float SpeedPenalty;

};
