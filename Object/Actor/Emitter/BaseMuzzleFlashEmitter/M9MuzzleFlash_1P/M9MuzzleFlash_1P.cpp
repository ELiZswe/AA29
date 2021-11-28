// All the original content belonged to the US Army

#include "M9MuzzleFlash_1P.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AM9MuzzleFlash_1P::AM9MuzzleFlash_1P()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->UseRandomSubdivision = true;
	SpriteEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	SpriteEmitter0->MaxParticles = 1;
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0.01, 0.015}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({1,0.5});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {1, 2}, {100, 100}, {100, 100} });
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_flash_ak47_1P_Mat.fx_flash_ak47_1P_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 2;
	SpriteEmitter0->TextureVSubdivisions = 2;
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.07, 0.07 });
	SpriteEmitter0->iFlashSpawnCount = 1;
	SpriteEmitter0->MinFramesBeforeDeath = 1;
	Emitters = { SpriteEmitter0 };
};

