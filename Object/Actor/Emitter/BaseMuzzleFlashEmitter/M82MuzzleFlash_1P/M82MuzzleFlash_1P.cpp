// All the original content belonged to the US Army

#include "M82MuzzleFlash_1P.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

AM82MuzzleFlash_1P::AM82MuzzleFlash_1P()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_m82a1_1P.fx_flash_m82a1_1P'"), NULL, LOAD_None, NULL);
	MeshEmitter0->RenderTwoSided = true;
	MeshEmitter0->bUseAbsoluteRotation = true;
	MeshEmitter0->AbsoluteRotationSource = EAbsoluteRotationSource::PARS_ActorOnly;
	MeshEmitter0->FadeOut = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->UseSizeScale = true;
	MeshEmitter0->UseRegularSizeScale = false;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter0->MaxParticles = 1;
	//MeshEmitter0->SizeScale[0]=FParticleTimeScale({0.5,1});
	//MeshEmitter0->SizeScale[1]=FParticleTimeScale({1,0.5});
	MeshEmitter0->StartSizeRange = FRangeVector({ {0.55, 0.55}, {0.55, 0.55}, {0.55, 0.55} });
	MeshEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	MeshEmitter0->LifetimeRange = FRange({ 0.07, 0.09 });
	MeshEmitter0->iFlashSpawnCount = 1;
	MeshEmitter0->MinFramesBeforeDeath = 1;
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, -90, 100);
	SpriteEmitter1->MaxParticles = 5;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.2, 0.25}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({1,25});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {10, 10}, {100, 100}, {100, 100} });
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball04_Mat.fx_smk_ball04_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 0.8, 0.8 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {130, 150} });
	SpriteEmitter1->iFlashSpawnCount = 1;
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->Acceleration = FVector(0, 90, 100);
	SpriteEmitter2->MaxParticles = 5;
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter2->SpinsPerSecondRange = FRangeVector({ {-0.2, -0.25}, {0, 0}, {0, 0} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({1,25});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {10, 10}, {100, 100}, {100, 100} });
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball04_Mat.fx_smk_ball04_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 0.8, 0.8 });
	SpriteEmitter2->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {-130, -150} });
	SpriteEmitter2->iFlashSpawnCount = 1;
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->MaxParticles = 5;
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter3->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0, 0}, {0, 0} });
	SpriteEmitter3->StartSpinRange = FRangeVector({ {1, -1}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({1,25});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {7, 7}, {100, 100}, {100, 100} });
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball04_Mat.fx_smk_ball04_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 0.7, 0.7 });
	SpriteEmitter3->iFlashSpawnCount = 1;
	Emitters = { MeshEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3 };
};

void AM82MuzzleFlash_1P::BeginPlay()
{
	//Super::BeginPlay();
	Cast<UMeshEmitter>(Emitters[0])->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_m82a1_1p.fx_flash_m82a1_1p'"), NULL, LOAD_None, NULL);
}