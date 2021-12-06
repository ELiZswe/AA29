// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/PhysicsVolume/AGP_WindVolume/AGP_WindVolume.h"

AAGP_WindVolume::AAGP_WindVolume()
{
	bMoveAGPProjectiles = true;
	bMoveAGPParticles = true;
	bUpdateSystem = true;
	fBaseVarianceTime = 30;
	//bStatic = false;
}

void AAGP_WindVolume::BeginPlay()
{
	/*
	Super::BeginPlay();
	Enable('Timer');
	vMeanWind = Normal(vMeanWind);
	rBase = OrthoRotation(vMeanWind, MakeVect(vMeanWind.Z, vMeanWind.X, vMeanWind.Y), MakeVect(vMeanWind.Y, vMeanWind.Z, vMeanWind.X));
	UpdateWind();
	*/
}

void AAGP_WindVolume::ActorEnteredVolume(AActor* Other)
{
	/*
	if (bMoveAGPProjectiles && Other.IsA('BaseProjectile'))
	{
		(Other.Acceleration += (vWind * BaseProjectile(Other).fWindFactor));
	}
	else
	{
		if (bMoveAGPParticles && Other.IsA('Emitter'))
		{
			Emitter(Other).AddWindAcceleration(vWind);
		}
	}
	Super::ActorEnteredVolume(Other);
	*/
}

void AAGP_WindVolume::ActorLeavingVolume(AActor* Other)
{
	/*
	if (bMoveAGPProjectiles && Other.IsA('BaseProjectile'))
	{
		(Other.Acceleration -= (vWind * BaseProjectile(Other).fWindFactor));
	}
	else
	{
		if (bMoveAGPParticles && Other.IsA('Emitter'))
		{
			Emitter(Other).AddWindAcceleration((-vWind));
		}
	}
	Super::ActorLeavingVolume(Other);
	*/
}

void AAGP_WindVolume::Timer()
{
	UpdateWind();
}

void AAGP_WindVolume::UpdateWind()
{
	/*
	local BaseProjectile Proj;
	local Emitter EM;
	FVector vUpdate = FVector(0, 0, 0);
	vUpdate = CalcWind();
	if (bMoveAGPProjectiles)
	{
		ForEach AllActors(Class'BaseProjectile', Proj)
		{
			if (Proj.PhysicsVolume == Self)
			{
				Proj.Acceleration = ((Proj.Acceleration - (vWind * Proj.fWindFactor)) + (vUpdate * Proj.fWindFactor));
			}
		}
	}
	if (bMoveAGPParticles)
	{
		ForEach AllActors(Class'Emitter', EM)
		{
			if (EM.PhysicsVolume == Self)
			{
				EM.AddWindAcceleration((-vWind));
				EM.AddWindAcceleration(vUpdate);
			}
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

FVector AAGP_WindVolume::CalcWind()
{
	FRotator update = FRotator(0, 0, 0);
	/*
	update.Pitch = int((182.041199 * CalcRandom(fPitchMaxDev, fPitchFalloff, fPitchMean, true)));
	update.Yaw = int((182.041199 * CalcRandom(fYawMaxDev, fYawFalloff, fYawMean, true)));
	(update += rBase);
	return (Normal(Vector(update)) * CalcRandom(fSpeedMaxDev, fSpeedFalloff, fSpeedMean, false));
	*/
	return FVector(0, 0, 0);     //FAKE    /ELiZ
}