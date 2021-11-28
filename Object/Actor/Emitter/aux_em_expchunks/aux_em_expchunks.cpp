// All the original content belonged to the US Army

#include "aux_em_expchunks.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aaux_em_expchunks::Aaux_em_expchunks()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_con_chunk1.fx_part_con_chunk1'"), NULL, LOAD_None, NULL);
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AutoDestroy = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -740);
	MeshEmitter0->MaxParticles = 7;
	MeshEmitter0->StartSizeRange = FRangeVector({ {0.5, 0.5}, {0.5, 0.5}, {0.5, 0.5} });
	MeshEmitter0->InitialParticlesPerSecond = 5;
	MeshEmitter0->LifetimeRange = FRange({ 2, 2 });
	MeshEmitter0->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {500, 500} });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, 25);
	SpriteEmitter1->FadeOutFactor = FPlane({ 1, 1, 1.2, 1 });
	SpriteEmitter1->FadeInFactor = FPlane({ 1.5, 1, 1, 1 });
	SpriteEmitter1->MaxParticles = 110;
	SpriteEmitter1->AddLocationFromOtherEmitter = 30;
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({1,10});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {10, 10}, {100, 100}, {100, 100} });
	SpriteEmitter1->InitialParticlesPerSecond = 110;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 2, 2 });
	Emitters = { nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,SpriteEmitter1,MeshEmitter0 };
};