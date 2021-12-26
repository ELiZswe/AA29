// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SideEffect/SideEffect.h"
#include "SideEffectSlow.generated.h"

class AAGP_Pawn;

UCLASS()
class ASideEffectSlow : public ASideEffect
{
	GENERATED_BODY()
	
public:
	ASideEffectSlow();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float		SpeedPenalty;			//var float SpeedPenalty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float		OldSpeedPenalty;		//var float OldSpeedPenalty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float		ElapsedTime;			//var float ElapsedTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AAGP_Pawn*	AffectedPawn;			//var AGP_Pawn AffectedPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float		FadeTimeProportion;		//var float FadeTimeProportion;

	bool OverrideEffects();
	void ScaleByDamage(int32 Damage);
	void Start();
	void update(float DeltaTime);
	void End();
};
