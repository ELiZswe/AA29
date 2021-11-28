// All the original content belonged to the US Army

#include "M2MuzzleFlash.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

AM2MuzzleFlash::AM2MuzzleFlash()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_m16.fx_flash_m16'"), NULL, LOAD_None, NULL);
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
	//MeshEmitter0->SizeScale[0]=FParticleTimeScale({0.5,1});
	//MeshEmitter0->SizeScale[1]=FParticleTimeScale({1,0.5});
	MeshEmitter0->StartSizeRange = FRangeVector({ {0.95, 0.95}, {0.95, 0.95}, {0.95, 0.95} });
	MeshEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	MeshEmitter0->LifetimeRange = FRange({ 0.04, 0.04 });
	MeshEmitter0->iFlashSpawnCount = 1;
	MeshEmitter0->MinFramesBeforeDeath = 1;
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->FadeIn = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->Acceleration = FVector(5, 0, 0);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(60, 60, 60, 255)});
	SpriteEmitter0->FadeOutStartTime = 1;
	SpriteEmitter0->FadeInEndTime = 0.2;
	SpriteEmitter0->MaxParticles = 32;
	SpriteEmitter0->SpinCCWorCW = FVector(0.25, 0.75, 0.5);
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0.05}, {0, 0.1} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,0.1});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({5,1.3});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {30, 100}, {30, 100}, {30, 100} });
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 1;
	SpriteEmitter0->TextureVSubdivisions = 1;
	SpriteEmitter0->LifetimeRange = FRange({ 2.5, 5 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-5, 5}, {-5, 5}, {30, 15} });
	SpriteEmitter0->iFlashSpawnCount = 1;
	SpriteEmitter0->fWindFactor = 3;
	SpriteEmitter0->MinFramesBeforeDeath = 1;
	Emitters = { MeshEmitter0,SpriteEmitter0 };
};

void AM2MuzzleFlash::BeginPlay()
{
	//Super::BeginPlay();
	Cast<UMeshEmitter>(Emitters[0])->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_m16.fx_flash_m16'"), NULL, LOAD_None, NULL);
}
