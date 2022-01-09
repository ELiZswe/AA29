// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/DamagedEffect/DamagedEffect.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

ADamagedEffect::ADamagedEffect()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->UseRandomSubdivision = true;
	SpriteEmitter0->UseVelocityScale = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, 175);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(192, 192, 192, 0)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({0.1,FColor(160, 160, 160, 255)});
	//SpriteEmitter0->ColorScale[2]=FParticleColorScale({0.8,FColor(128, 128, 128, 192)});
	//SpriteEmitter0->ColorScale[3]=FParticleColorScale({1,FColor(128, 128, 128, 0)});
	SpriteEmitter0->MaxParticles = 50;
	SpriteEmitter0->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {0, 20} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,0.5});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({1,1.5});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {50, 50}, {100, 100}, {100, 100} });
	SpriteEmitter0->ParticlesPerSecond = 25;
	SpriteEmitter0->InitialParticlesPerSecond = 25;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->TextureUSubdivisions = 4;
	SpriteEmitter0->TextureVSubdivisions = 4;
	SpriteEmitter0->LifetimeRange = FRange({ 2.5, 1.5 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-100, 100}, {-100, 100}, {200, 200} });
	//SpriteEmitter0->VelocityScale(0) = (RelativeTime = 0, RelativeVelocity = FVector(0, 0, 0.5));
	//SpriteEmitter0->VelocityScale(1) = (RelativeTime = 0.5, RelativeVelocity = FVector(0.2, 0.2, 0.2));
	//SpriteEmitter0->VelocityScale(2) = (RelativeTime = 1, RelativeVelocity = FVector(1, 1, 0.2));
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, 50);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 0)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.5,FColor(34, 135, 210, 255)});
	//SpriteEmitter1->ColorScale[2]=FParticleColorScale({0.6,FColor(255, 255, 255, 64)});
	//SpriteEmitter1->ColorScale[3]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter1->Opacity = 0.5;
	SpriteEmitter1->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	SpriteEmitter1->MaxParticles = 4;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {-10, 10}, {-10, 10}, {0, 0} });
	SpriteEmitter1->StartLocationShape = EParticleStartLocationShape::PTLS_All;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0, 0.2}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({0.5,1.2});
	//SpriteEmitter1->SizeScale[2]=FParticleTimeScale({1,1.5});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {10, 20}, {100, 100}, {100, 100} });
	SpriteEmitter1->ParticlesPerSecond = 8;
	SpriteEmitter1->InitialParticlesPerSecond = 8;
	SpriteEmitter1->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {4, 4} });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 0)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({0.2,FColor(9, 175, 255, 0)});
	//SpriteEmitter2->ColorScale[2]=FParticleColorScale({0.4,FColor(13, 122, 242, 0)});
	//SpriteEmitter2->ColorScale[3]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter2->StartLocationRange = FRangeVector({ {-10, 10}, {-10, 10}, {0, 0} });
	SpriteEmitter2->SpinsPerSecondRange = FRangeVector({ {0, 0.2}, {0, 0}, {0, 0} });
	SpriteEmitter2->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,0.75});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,1});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {20, 30}, {100, 100}, {100, 100} });
	SpriteEmitter2->ParticlesPerSecond = 25;
	SpriteEmitter2->InitialParticlesPerSecond = 25;
	SpriteEmitter2->LifetimeRange = FRange({ 0.15, 0.15 });
	SpriteEmitter2->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {140, 180} });
	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2 };

	//AutoDestroy = true;
	//bNoDelete = false;
	//RemoteRole = ROLE_None;
	//bHardAttach = true;
}

void ADamagedEffect::PostBeginPlay()
{
	/*
	local AGP_Vehicle V;
	Super::PostBeginPlay();
	V = AGP_Vehicle(Owner);
	if (V != nullptr)
	{
		SetEffectScale(V.DamagedEffectScale);
		UpdateDamagedEffect(false, 0);
	}
	*/
}

void ADamagedEffect::SetEffectScale(float Scaling)
{
	/*
	Emitters[0].SizeScale[0].RelativeSize = (Scaling * Default.Emitters[0].SizeScale[0].RelativeSize);
	Emitters[0].SizeScale[1].RelativeSize = (Scaling * Default.Emitters[0].SizeScale[1].RelativeSize);
	Emitters[1].SizeScale[0].RelativeSize = (Scaling * Default.Emitters[1].SizeScale[0].RelativeSize);
	Emitters[1].SizeScale[1].RelativeSize = (Scaling * Default.Emitters[1].SizeScale[1].RelativeSize);
	Emitters[1].SizeScale[2].RelativeSize = (Scaling * Default.Emitters[1].SizeScale[2].RelativeSize);
	Emitters[1].StartLocationRange.X.Min = (Scaling * Default.Emitters[1].StartLocationRange.X.Min);
	Emitters[1].StartLocationRange.X.Max = (Scaling * Default.Emitters[1].StartLocationRange.X.Max);
	Emitters[1].StartLocationRange.Y.Min = (Scaling * Default.Emitters[1].StartLocationRange.Y.Min);
	Emitters[1].StartLocationRange.Y.Max = (Scaling * Default.Emitters[1].StartLocationRange.Y.Max);
	Emitters[2].StartSizeRange.X.Min = (Scaling * Default.Emitters[2].StartSizeRange.X.Min);
	Emitters[2].StartSizeRange.X.Max = (Scaling * Default.Emitters[2].StartSizeRange.X.Max);
	Emitters[2].StartSizeRange.Y.Min = (Scaling * Default.Emitters[2].StartSizeRange.Y.Min);
	Emitters[2].StartSizeRange.Y.Max = (Scaling * Default.Emitters[2].StartSizeRange.Y.Max);
	Emitters[2].StartLocationRange.X.Min = (Scaling * Default.Emitters[2].StartLocationRange.X.Min);
	Emitters[2].StartLocationRange.X.Max = (Scaling * Default.Emitters[2].StartLocationRange.X.Max);
	Emitters[2].StartLocationRange.Y.Min = (Scaling * Default.Emitters[2].StartLocationRange.Y.Min);
	Emitters[2].StartLocationRange.Y.Max = (Scaling * Default.Emitters[2].StartLocationRange.Y.Max);
	*/
}

void ADamagedEffect::UpdateDamagedEffect(bool bFlame, float VelMag)
{
	/*
	float SmokeLifeScale = 0;
	if (bFlame)
	{
		Emitters[1].ParticlesPerSecond = Default.Emitters[1].ParticlesPerSecond;
		Emitters[1].InitialParticlesPerSecond = Default.Emitters[1].InitialParticlesPerSecond;
		Emitters[1].AllParticlesDead = false;
		Emitters[2].ParticlesPerSecond = Default.Emitters[2].ParticlesPerSecond;
		Emitters[2].InitialParticlesPerSecond = Default.Emitters[2].InitialParticlesPerSecond;
		Emitters[2].AllParticlesDead = false;
	}
	else
	{
		Emitters[1].ParticlesPerSecond = 0;
		Emitters[1].InitialParticlesPerSecond = 0;
		Emitters[2].ParticlesPerSecond = 0;
		Emitters[2].InitialParticlesPerSecond = 0;
	}
	SmokeLifeScale = (1 - (0.55 * ((VelMag - float(500)) / float(2000))));
	SmokeLifeScale = FClamp(SmokeLifeScale, 0.45, 1);
	Emitters[0].InitialParticlesPerSecond = (7.5 / SmokeLifeScale);
	Emitters[0].ParticlesPerSecond = (7.5 / SmokeLifeScale);
	Emitters[0].LifetimeRange.Min = (2 * SmokeLifeScale);
	Emitters[0].LifetimeRange.Max = (2 * SmokeLifeScale);
	*/
}