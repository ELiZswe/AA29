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

	UPROPERTY(EditAnywhere)		bool	bScaleRateByDamage;		//var bool bScaleRateByDamage
	UPROPERTY(EditAnywhere)		int32	DamageBase;				//var int DamageBase
	UPROPERTY(EditAnywhere)		float	DamageScalar;			//var float DamageScalar
	UPROPERTY(EditAnywhere)		float	ShakeRateDeviation;		//var float ShakeRateDeviation
	UPROPERTY(EditAnywhere)		float	ShakeMaxDeviation;		//var float ShakeMaxDeviation
	UPROPERTY(EditAnywhere)		float	ShakeMinDeviation;		//var float ShakeMinDeviation
	UPROPERTY(EditAnywhere)		float	ShakeRateBase;			//var float ShakeRateBase
	UPROPERTY(EditAnywhere)		float	ShakeMaxBase;			//var float ShakeMaxBase	
	UPROPERTY(EditAnywhere)		float	ShakeMinBase;			//var float ShakeMinBase
	UPROPERTY(EditAnywhere)		float	HitShakeRate;			//var float HitShakeRate
	UPROPERTY(EditAnywhere)		float	HitShakeMax;			//var float HitShakeMax
	UPROPERTY(EditAnywhere)		float	HitShakeMin;			//var float HitShakeMin
	UPROPERTY(EditAnywhere)		float	HitShakeOffset;			//var float HitShakeOffset
	UPROPERTY(EditAnywhere)		int32	ShakeAngleDeviation;	//var int ShakeAngleDeviation
	UPROPERTY(EditAnywhere)		int32	ShakeAngleBase;			//var int ShakeAngleBase
	UPROPERTY(EditAnywhere)		int32	ShakeAngle;				//var int ShakeAngle

	void ScaleByDamage(int32 Damage);
	void Start();
	void update(float DeltaTime);
	void End();
};
