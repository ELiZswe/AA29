// All the original content belonged to the US Army

#include "AA29/Object/Actor/SideEffect/SideEffectViewShake/SideEffectViewShake.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

ASideEffectViewShake::ASideEffectViewShake()
{
	ShakeAngleDeviation  = -1;
	ShakeMaxBase         = 1729;
	ShakeRateBase        = 28211;
	ShakeMinDeviation    = 182;
	ShakeMaxDeviation    = 91;
	ShakeRateDeviation   = 1365;
	DamageScalar         = 1;
	DamageBase           = 100;
	EffectDuration       = 0;
}

void ASideEffectViewShake::ScaleByDamage(int32 Damage)
{
	float DamageRatio = 0;
	/*
	DamageRatio = (FClamp(float((Damage / DamageBase)), 0.1, 1) * DamageScalar);
	HitShakeOffset = 0;
	HitShakeMin = (ShakeMinBase + ((((ShakeMinDeviation * 2) * FMath::FRand()) - ShakeMinDeviation) * DamageRatio));
	HitShakeMax = (ShakeMaxBase + ((((ShakeMaxDeviation * 2) * FMath::FRand()) - ShakeMaxDeviation) * DamageRatio));
	if (bScaleRateByDamage)
	{
		HitShakeRate = (ShakeRateBase + ((((ShakeRateDeviation * 2) * FMath::FRand()) - ShakeRateDeviation) * DamageRatio));
	}
	else
	{
		HitShakeRate = (ShakeRateBase + (((ShakeRateDeviation * 2) * FMath::FRand()) - ShakeRateDeviation));
	}
	ShakeAngle = int((float(ShakeAngleBase) + ((float((ShakeAngleDeviation * 2)) * FMath::FRand()) - float(ShakeAngleDeviation))));
	*/
}

void ASideEffectViewShake::Start()
{
	AHumanController* AffectedController = nullptr;
	/*
	Super::Start();
	AffectedController = Cast<AHumanController>(GetOwner());
	if (AffectedController != nullptr)
	{
		AffectedController.ClientStartViewShake(ShakeAngle, HitShakeOffset, HitShakeMin, HitShakeMax, HitShakeRate);
	}
	*/
}

void ASideEffectViewShake::update(float DeltaTime)
{
	//Super::update(DeltaTime);
}

void ASideEffectViewShake::End()
{
	//Super::End();
}
