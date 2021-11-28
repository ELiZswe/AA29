// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/DieselSmoke/DieselSmoke.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

ADieselSmoke::ADieselSmoke()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, 20);
	SpriteEmitter1->ColorScale = {FParticleColorScale({0,FColor(0, 0, 0, 0)}),FParticleColorScale({0.1,FColor(0, 0, 0, 112)}),FParticleColorScale({0.9,FColor(0, 0, 0, 96)}),FParticleColorScale({1,FColor(0, 0, 0, 96)})};
	SpriteEmitter1->FadeOutStartTime = 0.5;
	SpriteEmitter1->MaxParticles = 500;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {0, 0}, {-4, 0}, {0, 0} });
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0, 0.025}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,0.6});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({0.5,2.7});
	//SpriteEmitter1->SizeScale[2]=FParticleTimeScale({0.9,2.7});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {10, 18}, {10, 18}, {10, 18} });
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 4, 5.5 });
	MaxPPS = 12;
	Emitters = {SpriteEmitter1};
	//CullDistance = 5000;
	//bNoDelete = false;
	//bHardAttach = true;
	//SoundVolume = 40;
}

void ADieselSmoke::disableEffect()
{
	Emitters[0]->ParticlesPerSecond = 0;
	Emitters[0]->InitialParticlesPerSecond = 0;
}

void ADieselSmoke::SetEmitterColor(FColor DirtColor, int32 emitterNum)
{
	/*
	FColor DirtColorZeroAlpha = FColor(0, 0, 0, 0);
	FColor DirtColorHalfAlpha = FColor(0, 0, 0, 0);
	if (((DirtColor.R == 0) && (DirtColor.G == 0)) && (DirtColor.B == 0))
	{
		Log("DIrt color was black!!!");
		return;
	}
	DirtColor.A = 255;
	DirtColorZeroAlpha = DirtColor;
	DirtColorZeroAlpha.A = 0;
	DirtColorHalfAlpha = DirtColor;
	DirtColorHalfAlpha.A = 128;
	Emitters[emitterNum].ColorScale[0].Color = DirtColorZeroAlpha;
	Emitters[emitterNum].ColorScale[1].Color = DirtColorHalfAlpha;
	Emitters[emitterNum].ColorScale[2].Color = DirtColorHalfAlpha;
	Emitters[emitterNum].ColorScale[3].Color = DirtColorZeroAlpha;
	*/
}

void ADieselSmoke::UpdatePrecacheMaterials()
{
	//Super::UpdatePrecacheMaterials();
}

void ADieselSmoke::updatePuff(float puffCoeff)
{
	/*
	float SpritePPS = 0;
	FColor smokeColor = FColor(0, 0, 0, 0);
	smokeColor.R = 0;
	smokeColor.G = 0;
	smokeColor.B = 0;
	if (puffCoeff == 0)
	{
		SpritePPS = 0;
	}
	else
	{
		SpritePPS = (puffCoeff * float(MaxPPS));
	}
	Emitters[0].ParticlesPerSecond = SpritePPS;
	Emitters[0].InitialParticlesPerSecond = SpritePPS;
	Emitters[0].AllParticlesDead = false;
	*/
}