// All the original content belonged to the US Army

#include "ImpactSparks.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AImpactSparks::AImpactSparks()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->ScaleSizeYByVelocity = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->Acceleration = FVector(0, 0, -600);
	SpriteEmitter0->DampingFactorRange = FRangeVector({ {0.5, 0.5}, {0.5, 0.5}, {0.1, 0.1} });
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(174, 255, 255, 0)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({0.5,FColor(49, 214, 242, 0)});
	//SpriteEmitter0->ColorScale[2]=FParticleColorScale({1,FColor(0, 40, 102, 0)});
	SpriteEmitter0->MaxParticles = 1000;
	SpriteEmitter0->StartLocationRange = FRangeVector({ {-10, 10}, {0, 0}, {0, 0} });
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,0});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({0.05,0});
	//SpriteEmitter0->SizeScale[2]=FParticleTimeScale({0.1,2});
	//SpriteEmitter0->SizeScale[3]=FParticleTimeScale({1,2});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {2, 4}, {2, 2}, {100, 100} });
	SpriteEmitter0->ScaleSizeByVelocityMultiplier = FVector(0.01, 0.003, 1);
	SpriteEmitter0->ScaleSizeByVelocityMax = 1000;
	SpriteEmitter0->LifetimeRange = FRange({ 0.4, 0.6 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {350, 500}, {-50, 50}, {-50, 50} });
	SpriteEmitter0->MaxAbsVelocity = FVector(1000, 1000, 1000);
	SpriteEmitter0->VelocityLossRange = FRangeVector({ {1, 2}, {1, 2}, {1, 2} });
	HorizontalVelocityRange = 500;
	AdditionalVelocityScale = 0.25;
	MaxAdditionalVelocity = 200;
	SparkRadiusScale = 0.05;
	//ZeroSizeSize;
	Emitters = { SpriteEmitter0 };
	//bNoDelete = false;
	//RemoteRole = ROLE_None;
	//SoundVolume = 80;
};

void AImpactSparks::UpdateSparks(float SparkRadius, FVector VehicleVelocity)
{
	/*
	float UseRadius = 0;
	float VelMag = 0;
	float ParticleRate = 0;
	FVector LocalVehVel = FVector(0, 0, 0);
	FVector AddVel = FVector(0, 0, 0);
	VelMag = VSize(VehicleVelocity);
	ParticleRate = InterpCurveEval(SparkRate, VelMag);
	if (ParticleRate > 0.001)
	{
		LocalVehVel = (VehicleVelocity << Rotation);
		LocalVehVel.X = 0;
		if (!bSparksActive)
		{
			OldLocation = Location;
		}
		bSparksActive = true;
		UseRadius = (SparkRadiusScale * SparkRadius);
		Emitters[0].ParticlesPerSecond = ParticleRate;
		Emitters[0].InitialParticlesPerSecond = ParticleRate;
		Emitters[0].AllParticlesDead = false;
		Emitters[0].StartLocationRange.Y.Min = (-UseRadius);
		Emitters[0].StartLocationRange.Y.Max = UseRadius;
		Emitters[0].StartLocationRange.Z.Min = (-UseRadius);
		Emitters[0].StartLocationRange.Z.Max = UseRadius;
		AddVel = (AdditionalVelocityScale * LocalVehVel);
		if (VSize(AddVel) > MaxAdditionalVelocity)
		{
			AddVel = (Normal(AddVel) * MaxAdditionalVelocity);
		}
		Emitters[0].StartVelocityRange.Y.Min = ((LocalVehVel.Y + AddVel.Y) - HorizontalVelocityRange);
		Emitters[0].StartVelocityRange.Y.Max = ((LocalVehVel.Y + AddVel.Y) + HorizontalVelocityRange);
		Emitters[0].StartVelocityRange.Z.Min = ((LocalVehVel.Z + AddVel.Z) - HorizontalVelocityRange);
		Emitters[0].StartVelocityRange.Z.Max = ((LocalVehVel.Z + AddVel.Z) + HorizontalVelocityRange);
		AmbientSound = ScrapeSound;
	}
	else
	{
		bSparksActive = false;
		Emitters[0].ParticlesPerSecond = 0;
		Emitters[0].InitialParticlesPerSecond = 0;
		AmbientSound = None;
	}
	*/
}