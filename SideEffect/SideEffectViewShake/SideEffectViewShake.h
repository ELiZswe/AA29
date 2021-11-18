// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/SideEffect/SideEffect.h"
#include "SideEffectViewShake.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASideEffectViewShake : public ASideEffect
{
	GENERATED_BODY()
public:
	ASideEffectViewShake();

	//var bool bScaleRateByDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bScaleRateByDamage;

	//var int DamageBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 DamageBase;

	//var float DamageScalar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float DamageScalar;

	//var float ShakeRateDeviation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ShakeRateDeviation;

	//var float ShakeMaxDeviation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ShakeMaxDeviation;

	//var float ShakeMinDeviation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ShakeMinDeviation;

	//var float ShakeRateBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ShakeRateBase;

	//var float ShakeMaxBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ShakeMaxBase;

	//var float ShakeMinBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ShakeMinBase;

	//var float HitShakeRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float HitShakeRate;

	//var float HitShakeMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float HitShakeMax;

	//var float HitShakeMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float HitShakeMin;

	//var float HitShakeOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float HitShakeOffset;

	//var int ShakeAngleDeviation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 ShakeAngleDeviation;

	//var int ShakeAngleBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 ShakeAngleBase;

	//var int ShakeAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 ShakeAngle;


};
