// All the original content belonged to the US Army

#include "AK47MuzzleFlash_1P.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AAK47MuzzleFlash_1P::AAK47MuzzleFlash_1P()
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
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({1,0.75});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {6, 6}, {100, 100}, {100, 100} });
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_flash_ak47_1P_Mat.fx_flash_ak47_1P_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 2;
	SpriteEmitter0->TextureVSubdivisions = 2;
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.07, 0.07 });
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
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 111)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 111)});
	SpriteEmitter1->FadeOutStartTime = 0.1;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {-1, -1}, {-11, -11}, {0, 0} });
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.05, 0.1}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {2, 3.2}, {100, 100}, {100, 100} });
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 1.3, 1.4 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {-40, -40}, {0, 0}, {11, 11} });
	SpriteEmitter1->VelocityLossRange = FRangeVector({ {15, 15}, {15, 15}, {15, 15} });
	SpriteEmitter1->iFlashSpawnCount = 1;
	SpriteEmitter1->MinFramesBeforeDeath = 1;
	Emitters = { SpriteEmitter0,SpriteEmitter1 };

};