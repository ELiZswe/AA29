// All the original content belonged to the US Army

#include "SuppressorMuzzleFlash.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

ASuppressorMuzzleFlash::ASuppressorMuzzleFlash()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_ak47.fx_flash_ak47'"), NULL, LOAD_None, NULL);
	MeshEmitter0->RenderTwoSided = true;
	MeshEmitter0->bUseAbsoluteRotation = true;
	MeshEmitter0->AbsoluteRotationSource = EAbsoluteRotationSource::PARS_ActorOnly;
	MeshEmitter0->FadeOut = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->UseSizeScale = true;
	MeshEmitter0->UseRegularSizeScale = false;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter0->MaxParticles = 1;
	//MeshEmitter0->SizeScale[0]=FParticleTimeScale({0.5,0.75});
	//MeshEmitter0->SizeScale[1]=FParticleTimeScale({1,0.25});
	MeshEmitter0->StartSizeRange = FRangeVector({ {0.1, 0.25}, {0.15, 0.25}, {0.1, 0.25} });
	MeshEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	MeshEmitter0->LifetimeRange = FRange({ 0.04, 0.04 });
	MeshEmitter0->iFlashSpawnCount = 1;
	MeshEmitter0->MinFramesBeforeDeath = 1;
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, -10);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 233)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 233)});
	SpriteEmitter1->FadeOutStartTime = 0.1;
	SpriteEmitter1->MaxParticles = 0;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {0, 2}, {0, 0}, {0, 2} });
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.02, 0.15}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,7});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {4, 5}, {100, 100}, {100, 100} });
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 1, 1.1 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {0, 0}, {22, 33}, {33, 44} });
	SpriteEmitter1->VelocityLossRange = FRangeVector({ {15, 15}, {15, 15}, {15, 15} });
	SpriteEmitter1->iFlashSpawnCount = 1;
	SpriteEmitter1->MinFramesBeforeDeath = 1;
	//MuzzleFlashLight = class'AGP_Effects.aux_light_suppressedlight';
	Emitters = { MeshEmitter0,SpriteEmitter1 };
};

void ASuppressorMuzzleFlash::BeginPlay()
{
	//Super::BeginPlay();
	Cast<UMeshEmitter>(Emitters[0])->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_ak47.fx_flash_ak47'"), NULL, LOAD_None, NULL);
}