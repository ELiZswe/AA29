// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ZoneInfo/AGP_ZoneInfo/AGP_ZoneInfo.h"

AAGP_ZoneInfo::AAGP_ZoneInfo()
{
	bMoveAGPProjectiles = true;
	bMoveAGPParticles = true;
	bUpdateSystem = true;
	fBaseVarianceTime = 30;
	//bStatic = false;
}

/*
replication
{
	reliable if ((Role == ROLE_Authority))
		vWind;
}
*/

void AAGP_ZoneInfo::BeginPlay()
{
	Super::BeginPlay();
	/*
	Enable("Timer");
	vMeanWind = Normal(vMeanWind);
	rBase = OrthoRotation(vMeanWind, MakeVect(vMeanWind.Z, vMeanWind.X, vMeanWind.Y), MakeVect(vMeanWind.Y, vMeanWind.Z, vMeanWind.X));
	*/
	UpdateWind();
}

void AAGP_ZoneInfo::ActorEntered(AActor* Other)
{
	/*
	if (bMoveAGPProjectiles && Other.IsA("BaseProjectile"))
	{
		(Other.Acceleration += (vWind * BaseProjectile(Other).fWindFactor));
	}
	else
	{
		if (bMoveAGPParticles && Other.IsA("Emitter"))
		{
			Emitter(Other).AddWindAcceleration(vWind);
		}
	}
	Super::ActorEntered(Other);
	*/
}

void AAGP_ZoneInfo::ActorLeaving(AActor* Other)
{
	/*
	if (bMoveAGPProjectiles && Other.IsA("BaseProjectile"))
	{
		(Other.Acceleration -= (vWind * BaseProjectile(Other).fWindFactor));
	}
	else
	{
		if (bMoveAGPParticles && Other.IsA("Emitter"))
		{
			Emitter(Other).AddWindAcceleration((-vWind));
		}
	}
	Super::ActorLeaving(Other);
	*/
}

void AAGP_ZoneInfo::Timer()
{
	UpdateWind();
}

void AAGP_ZoneInfo::UpdateWind()
{
	/*
	local BaseProjectile Proj;
	local Emitter EM;
	FVector vUpdate = FVector(0, 0, 0);
	vUpdate = CalcWind();
	if (bMoveAGPProjectiles)
	{
		ForEach ZoneActors(Class'BaseProjectile', Proj)
		{
			Proj.Acceleration = ((Proj.Acceleration - (vWind * Proj.fWindFactor)) + (vUpdate * Proj.fWindFactor));
		}
	}
	if (bMoveAGPParticles)
	{
		ForEach ZoneActors(Class'Emitter', EM)
		{
			EM.AddWindAcceleration((-vWind));
			EM.AddWindAcceleration(vUpdate);
		}
	}
	vWind = vUpdate;
	if (bUpdateSystem)
	{
		if (bRandVariance)
		{
			SetTimer((fBaseVarianceTime + (FRand() * fVarianceTime)), false);
		}
		else
		{
			SetTimer(fBaseVarianceTime, false);
		}
	}
	*/
}

FVector AAGP_ZoneInfo::CalcWind()
{
	FRotator update = FRotator(0, 0, 0);
	/*
	update.Pitch = int((182.041199 * CalcRandom(fPitchMaxDev, fPitchFalloff, fPitchMean, true)));
	update.Yaw = int((182.041199 * CalcRandom(fYawMaxDev, fYawFalloff, fYawMean, true)));
	(update += rBase);
	return (Normal(Vector(update)) * CalcRandom(fSpeedMaxDev, fSpeedFalloff, fSpeedMean, false));
	*/
	return FVector(0, 0, 0);
}