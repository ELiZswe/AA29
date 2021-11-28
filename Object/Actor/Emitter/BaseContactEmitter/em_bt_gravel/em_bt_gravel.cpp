// All the original content belonged to the US Army


#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_gravel/em_bt_gravel.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Aem_bt_gravel::Aem_bt_gravel()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_con_chunk2.fx_part_con_chunk2'"), NULL, LOAD_None, NULL);
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AutoDestroy = true;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -740);
	MeshEmitter0->MaxParticles = 7;
	MeshEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//MeshEmitter0->SpinsPerSecondRange=X=(Min=-0.2, Max=-0.25)|Y=(Min=-0.2, Max=-0.25)|Z=(Min=-0.2, Max=-0.25);
	//MeshEmitter0->StartSizeRange=X=(Min=0.225, Max=0.225)|Y=(Min=0.225, Max=0.225)|Z=(Min=0.225, Max=0.225);
	MeshEmitter0->InitialParticlesPerSecond = 5000;
	MeshEmitter0->SecondsBeforeInactive = 0;
	MeshEmitter0->LifetimeRange = FRange({ 2, 2 });
	//MeshEmitter0->StartVelocityRange=X=(Min=250, Max=350)|Y=(Min=-200, Max=200)|Z=(Min=-200, Max=200);
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->ResetAfterChange = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->BlendBetweenSubdivisions = true;
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(79, 131, 169, 0)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter1->FadeOutStartTime = 0.1;
	SpriteEmitter1->MaxParticles = 3;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,0.1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,0.4});
	//SpriteEmitter1->StartSizeRange=X=(Min=5, Max=5)|Y=(Min=100, Max=100)|Z=(Min=150, Max=150);
	SpriteEmitter1->InitialParticlesPerSecond = 2000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_smokeanim01_Mat.fx_part_smokeanim01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->TextureUSubdivisions = 4;
	SpriteEmitter1->TextureVSubdivisions = 2;
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.3, 0.3 });
	//SpriteEmitter1->StartVelocityRange=X=(Min=150, Max=150)|Y=(Min=-250, Max=250)|Z=(Min=-250, Max=250);
	Emitters = { MeshEmitter0,SpriteEmitter1 };
}

void Aem_bt_gravel::BeginPlay()
{
	Cast<UMeshEmitter>(Emitters[0])->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_con_chunk2.fx_part_con_chunk2'"), NULL, LOAD_None, NULL);
}