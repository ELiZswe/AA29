// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_dirtchunk/em_bt_dirtchunk.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Aem_bt_dirtchunk::Aem_bt_dirtchunk()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_con_chunk1.fx_part_con_chunk1'"), NULL, LOAD_None, NULL);
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AutoDestroy = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->MaxParticles = 3;
	//MeshEmitter0->StartSizeRange=X=(Min=0.5, Max=0.5)|Y=(Min=0.5, Max=0.5)|Z=(Min=0.5, Max=0.5);
	MeshEmitter0->ParticlesPerSecond = 3;
	MeshEmitter0->InitialParticlesPerSecond = 5;
	MeshEmitter0->LifetimeRange = FRange({ 1, 1 });
	//MeshEmitter0->StartVelocityRange=X=(Min=-100, Max=100)|Y=(Min=-100, Max=100)|Z=(Min=-100, Max=100);
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->FadeIn = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->AutoDestroy = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->MaxParticles = 1;
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0.25,2});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({-0.7,0});
	//SpriteEmitter1->StartSizeRange=X=(Min=20, Max=10)|Y=(Min=20, Max=10)|Z=(Min=20, Max=20);
	SpriteEmitter1->InitialParticlesPerSecond = 100;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_drt_cloud01_Mat.fx_drt_cloud01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.7, 0.7 });
	Emitters = { MeshEmitter0,SpriteEmitter1 };
}