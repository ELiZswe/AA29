// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/DirtSlipEffect/DirtSlipEffect.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

ADirtSlipEffect::ADirtSlipEffect()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, 15);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(30, 90, 110, 0)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.1,FColor(34, 44, 66, 128)});
	//SpriteEmitter1->ColorScale[2]=FParticleColorScale({0.9,FColor(36, 49, 64, 128)});
	//SpriteEmitter1->ColorScale[3]=FParticleColorScale({1,FColor(20, 50, 80, 0)});
	SpriteEmitter1->MaxParticles = 100;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {0, 0}, {-24, 24}, {0, 0} });
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0, 0.025}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,0.25});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({0.5,1});
	//SpriteEmitter1->SizeScale[2]=FParticleTimeScale({0.9,2});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {50, 50}, {50, 50}, {50, 50} });
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.5, 1.1 });
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->BlendBetweenSubdivisions = true;
	SpriteEmitter0->UseRandomSubdivision = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, -550);
	SpriteEmitter0->FadeOutStartTime = 0.5;
	SpriteEmitter0->MaxParticles = 150;
	SpriteEmitter0->StartLocationRange = FRangeVector({ {-10, 10}, {-10, 10}, {-10, 10} });
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.5, 2}, {0, 0}, {0, 0} });
	SpriteEmitter0->StartSizeRange = FRangeVector({ {2, 8}, {100, 100}, {100, 100} });
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->TextureUSubdivisions = 16;
	SpriteEmitter0->TextureVSubdivisions = 16;
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.65, 0.65 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-150, -250}, {-80, 80}, {50, 250} });
	MaxSpritePPS = 70;
	MaxMeshPPS = 70;
	Emitters = { SpriteEmitter1,SpriteEmitter0 };
	//CullDistance = 5000;
	//bNoDelete = false;
	//RemoteRole = ROLE_None;
	//bHardAttach = true;
	//SoundVolume = 40;
}

void ADirtSlipEffect::SetDirtColor(FColor DirtColor)
{
	/*
	FColor DirtColorZeroAlpha = FColor(0, 0, 0, 0);
	FColor DirtColorHalfAlpha = FColor(0, 0, 0, 0);
	if (((DirtColor.R == 0) && (DirtColor.G == 0)) && (DirtColor.B == 0))
	{
		return;
	}
	DirtColor.A = 255;
	DirtColorZeroAlpha = DirtColor;
	DirtColorZeroAlpha.A = 0;
	DirtColorHalfAlpha = DirtColor;
	DirtColorHalfAlpha.A = 128;
	Emitters[0].ColorScale[0].Color = DirtColorZeroAlpha;
	Emitters[0].ColorScale[1].Color = DirtColorHalfAlpha;
	Emitters[0].ColorScale[2].Color = DirtColorHalfAlpha;
	Emitters[0].ColorScale[3].Color = DirtColorZeroAlpha;
	*/
}

void ADirtSlipEffect::UpdateDust(ASVehicleWheel* t, float DustSlipRate, float DustSlipThresh)
{
	/*
	float SpritePPS = 0;
	float MeshPPS = 0;
	if (t.bWheelOnGround && (t.SlipVel > DustSlipThresh))
	{
		SpritePPS = FMin((DustSlipRate * (t.SlipVel - DustSlipThresh)), float(MaxSpritePPS));
		Emitters[0].ParticlesPerSecond = SpritePPS;
		Emitters[0].InitialParticlesPerSecond = SpritePPS;
		Emitters[0].AllParticlesDead = false;
		MeshPPS = FMin((DustSlipRate * (t.SlipVel - DustSlipThresh)), float(MaxMeshPPS));
		Emitters[1].ParticlesPerSecond = MeshPPS;
		Emitters[1].InitialParticlesPerSecond = MeshPPS;
		Emitters[1].AllParticlesDead = false;
		AmbientSound = DirtSlipSound;
	}
	else
	{
		Emitters[0].ParticlesPerSecond = 0;
		Emitters[0].InitialParticlesPerSecond = 0;
		Emitters[1].ParticlesPerSecond = 0;
		Emitters[1].InitialParticlesPerSecond = 0;
		AmbientSound = nullptr;
	}
	*/
}
