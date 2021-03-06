// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/RPG7MuzzleFlash_1P/RPG7MuzzleFlash_1P.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/Actor/Emitter/aux_light_ExpLight/aux_light_ExpLight.h"
#include "Particles/Emitter.h"

ARPG7MuzzleFlash_1P::ARPG7MuzzleFlash_1P()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	SpriteEmitter0->MaxParticles = 1;
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0.01, 0.015}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,2});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({0,0});
	//SpriteEmitter0->SizeScale[2]=FParticleTimeScale({1,1});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {4, 5}, {100, 100}, {100, 100} });
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.07, 0.07 });
	SpriteEmitter0->iFlashSpawnCount = 1;
	SpriteEmitter0->MinFramesBeforeDeath = 1;
	Emitters = { SpriteEmitter0 };
};

void ARPG7MuzzleFlash_1P::DynamicFlash()
{
	AEmitter* E = nullptr;
	FVector NewRel = FVector(0, 0, 0);
	/*
	E = Spawn(Aaux_light_ExpLight::StaticClass());
	E.SetBase(this);
	NewRel.X = 250;
	E.SetRelativeLocation(NewRel);
	*/
}
