// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SideEffect/SideEffect.h"
#include "SideEffectViewShake.generated.h"

UCLASS()
class ASideEffectViewShake : public ASideEffect
{
	GENERATED_BODY()
public:
	ASideEffectViewShake();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool	bScaleRateByDamage;		//var bool bScaleRateByDamage
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32	DamageBase;				//var int DamageBase
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	DamageScalar;			//var float DamageScalar
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	ShakeRateDeviation;		//var float ShakeRateDeviation
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	ShakeMaxDeviation;		//var float ShakeMaxDeviation
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	ShakeMinDeviation;		//var float ShakeMinDeviation
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	ShakeRateBase;			//var float ShakeRateBase
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	ShakeMaxBase;			//var float ShakeMaxBase	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	ShakeMinBase;			//var float ShakeMinBase
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	HitShakeRate;			//var float HitShakeRate
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	HitShakeMax;			//var float HitShakeMax
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	HitShakeMin;			//var float HitShakeMin
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float	HitShakeOffset;			//var float HitShakeOffset
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32	ShakeAngleDeviation;	//var int ShakeAngleDeviation
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32	ShakeAngleBase;			//var int ShakeAngleBase
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32	ShakeAngle;				//var int ShakeAngle

	void ScaleByDamage(int32 Damage);
	void Start();
	void update(float DeltaTime);
	void End();
};
