// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/AGP_WindVolume/AGP_WindVolume.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "Particles/Emitter.h"

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
	rBase = OrthoRotation(vMeanWind, FVector(vMeanWind.Z, vMeanWind.X, vMeanWind.Y), FVector(vMeanWind.Y, vMeanWind.Z, vMeanWind.X));
	UpdateWind();
	*/
}

void AAGP_WindVolume::ActorEnteredVolume(AActor* Other)
{
	if (bMoveAGPProjectiles && Other->IsA(ABaseProjectile::StaticClass()))
	{
		//Other->Acceleration += (vWind * Cast<ABaseProjectile>(Other)->fWindFactor);
	}
	else
	{
		if (bMoveAGPParticles && Other->IsA(AEmitter::StaticClass()))
		{
			//Cast<AEmitter>(Other)->AddWindAcceleration(vWind);
		}
	}
	Super::ActorEnteredVolume(Other);
}

void AAGP_WindVolume::ActorLeavingVolume(AActor* Other)
{
	if (bMoveAGPProjectiles && Other->IsA(ABaseProjectile::StaticClass()))
	{
		//(Other->Acceleration -= (vWind * Cast<ABaseProjectile>(Other)->fWindFactor));
	}
	else
	{
		/*
		if (bMoveAGPParticles && Other->IsA(AEmitter::StaticClass()))
		{
			Cast<AEmitter>(Other)->AddWindAcceleration((-vWind));
		}
		*/
	}
	Super::ActorLeavingVolume(Other);
}

void AAGP_WindVolume::Timer()
{
	UpdateWind();
}

void AAGP_WindVolume::UpdateWind()
{
	ABaseProjectile* Proj = nullptr;
	AEmitter* EM = nullptr;
	FVector vUpdate = FVector(0, 0, 0);
	vUpdate = CalcWind();
	/*
	if (bMoveAGPProjectiles)
	{
		ForEach AllActors(ABaseProjectile::StaticClass(), Proj)
		{
			if (Proj.PhysicsVolume == this)
			{
				Proj.Acceleration = ((Proj.Acceleration - (vWind * Proj.fWindFactor)) + (vUpdate * Proj.fWindFactor));
			}
		}
	}
	if (bMoveAGPParticles)
	{
		ForEach AllActors(Class'Emitter', EM)
		{
			if (EM.PhysicsVolume == this)
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
			SetTimer((fBaseVarianceTime + (FMath::FRand() * fVarianceTime)), false);
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
