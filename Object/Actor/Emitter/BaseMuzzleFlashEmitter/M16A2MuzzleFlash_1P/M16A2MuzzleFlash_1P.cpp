// All the original content belonged to the US Army

#include "M16A2MuzzleFlash_1P.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AM16A2MuzzleFlash_1P::AM16A2MuzzleFlash_1P()
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
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({1,1});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {8, 8}, {100, 100}, {100, 100} });
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_flash_m16_1P_Mat.fx_flash_m16_1P_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 2;
	SpriteEmitter0->TextureVSubdivisions = 2;
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.04, 0.04 });
	SpriteEmitter0->iFlashSpawnCount = 1;
	SpriteEmitter0->MinFramesBeforeDeath = 1;
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, -11);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 47)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 47)});
	SpriteEmitter1->FadeOutStartTime = 0.1;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {-1, -1}, {-33, -33}, {1, 1} });
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.05, 0.1}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,3});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {3, 3.2}, {100, 100}, {100, 100} });
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 1.3, 1.4 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {-55, -55}, {0, 0}, {11, 11} });
	SpriteEmitter1->VelocityLossRange = FRangeVector({ {15, 15}, {15, 15}, {15, 15} });
	SpriteEmitter1->iFlashSpawnCount = 1;
	SpriteEmitter1->MinFramesBeforeDeath = 1;
	Emitters = { SpriteEmitter0,SpriteEmitter1 };
};