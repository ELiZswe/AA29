// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_be_wood/em_be_wood.h"
#include "AA29/Object/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Aem_be_wood::Aem_be_wood()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_wood_chunk1.fx_part_wood_chunk1'"), NULL, LOAD_None, NULL);
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AutoDestroy = true;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -540);
	MeshEmitter0->MaxParticles = 3;
	MeshEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//MeshEmitter0->SpinsPerSecondRange=X=(Min=0, Max=0)|Y=(Min=-2.5, Max=3.5)|Z=(Min=0, Max=0);
	//MeshEmitter0->StartSpinRange=X=(Min=-3000, Max=3000)|Y=(Min=0, Max=14300)|Z=(Min=0, Max=0);
	//MeshEmitter0->StartSizeRange=X=(Min=0.105, Max=0.25)|Y=(Min=0.105, Max=0.25)|Z=(Min=0.105, Max=0.25);
	MeshEmitter0->InitialParticlesPerSecond = 5000;
	MeshEmitter0->SecondsBeforeInactive = 0;
	MeshEmitter0->LifetimeRange = FRange({ 1, 1 });
	//MeshEmitter0->StartVelocityRange=X=(Min=50, Max=250)|Y=(Min=-100, Max=100)|Z=(Min=-100, Max=200);
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(14, 15, 15, 0)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter1->FadeOutStartTime = 0.5;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->StartLocationOffset = FVector(15, 0, 0);
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,0.1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,0.5});
	SpriteEmitter1->InitialParticlesPerSecond = 1000;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 1, 1 });
	//SpriteEmitter1->StartVelocityRange=X=(Min=-25, Max=-25)|Y=(Min=-10, Max=10)|Z=(Min=-10, Max=10);
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->Acceleration = FVector(0, 0, -100);
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(66, 83, 91, 110)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({1,FColor(66, 83, 91, 100)});
	SpriteEmitter2->FadeOutStartTime = 0.5;
	SpriteEmitter2->MaxParticles = 1;
	//SpriteEmitter2->StartLocationRange=X=(Min=-3, Max=-3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter2->SpinsPerSecondRange=X=(Min=0.2, Max=0.3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,1.7});
	//SpriteEmitter2->StartSizeRange=X=(Min=10, Max=12)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter2->InitialParticlesPerSecond = 1111;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 1, 1 });
	//SpriteEmitter2->StartVelocityRange=X=(Min=350, Max=370)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->Acceleration = FVector(0, 0, -100);
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(66, 83, 91, 70)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(66, 83, 91, 80)});
	SpriteEmitter3->FadeOutStartTime = 0.7;
	SpriteEmitter3->MaxParticles = 1;
	//SpriteEmitter3->StartLocationRange=X=(Min=-4, Max=-2)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter3->SpinsPerSecondRange=X=(Min=0.2, Max=0.3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({1,1.7});
	//SpriteEmitter3->StartSizeRange=X=(Min=13, Max=16)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter3->InitialParticlesPerSecond = 1111;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 1, 1 });
	//SpriteEmitter3->StartVelocityRange=X=(Min=610, Max=630)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);
	USpriteEmitter* SpriteEmitter4 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter4->UseColorScale = true;
	SpriteEmitter4->FadeOut = true;
	SpriteEmitter4->RespawnDeadParticles = false;
	SpriteEmitter4->SpinParticles = true;
	SpriteEmitter4->UseSizeScale = true;
	SpriteEmitter4->UseRegularSizeScale = false;
	SpriteEmitter4->UniformSize = true;
	SpriteEmitter4->AutomaticInitialSpawning = false;
	SpriteEmitter4->Acceleration = FVector(0, 0, -100);
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(66, 83, 91, 70)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({1,FColor(66, 83, 91, 60)});
	SpriteEmitter4->FadeOutStartTime = 1;
	SpriteEmitter4->MaxParticles = 1;
	//SpriteEmitter4->StartLocationRange=X=(Min=-4, Max=-2)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter4->SpinsPerSecondRange=X=(Min=0.1, Max=0.1)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter4->SizeScale[1]=FParticleTimeScale({1,1.7});
	//SpriteEmitter4->StartSizeRange=X=(Min=18, Max=22)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter4->InitialParticlesPerSecond = 1111;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 1, 1 });
	//SpriteEmitter4->StartVelocityRange=X=(Min=670, Max=750)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);
	Emitters = { MeshEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4 };
}


void Aem_be_wood::BeginPlay()
{
	//MeshEmitter(Emitters[0]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.Particles.fx_part_wood_chunk1", Class'StaticMesh'));
}

