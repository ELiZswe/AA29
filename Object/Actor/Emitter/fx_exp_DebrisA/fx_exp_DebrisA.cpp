// All the original content belonged to the US Army

#include "fx_exp_DebrisA.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Afx_exp_DebrisA::Afx_exp_DebrisA()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_tile01.fx_part_tile01'"), NULL, LOAD_None, NULL);
	MeshEmitter0->UseCollision = true;
	MeshEmitter0->UseMaxCollisions = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AutoDestroy = true;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -999);
	MeshEmitter0->DampingFactorRange = FRangeVector({ {0.6, 0.6}, {0.6, 0.6}, {0.2, 0.2} });
	MeshEmitter0->MaxCollisions = FRange({ 2, 2 });
	MeshEmitter0->MaxParticles = 3;
	MeshEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	MeshEmitter0->SpinsPerSecondRange = FRangeVector({ {0.1, 1.8}, {0.1, 1.8}, {0.1, 1.8} });
	MeshEmitter0->StartSizeRange = FRangeVector({ {5.7, 5.7}, {5.7, 5.7}, {5.7, 5.7} });
	MeshEmitter0->InitialParticlesPerSecond = 55;
	MeshEmitter0->SecondsBeforeInactive = 0;
	MeshEmitter0->LifetimeRange = FRange({ 3.5, 3.5 });
	MeshEmitter0->InitialDelayRange = FRange({ 0.25, 0.3 });
	MeshEmitter0->StartVelocityRange = FRangeVector({ {-600, 600}, {-600, 600}, {1111, 1400} });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(72, 72, 72, 222)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.5,FColor(56, 56, 56, 122)});
	//SpriteEmitter1->ColorScale[2]=FParticleColorScale({1,FColor(32, 32, 32, 55)});
	SpriteEmitter1->FadeOutStartTime = 2;
	SpriteEmitter1->FadeInEndTime = 1;
	SpriteEmitter1->MaxParticles = 66;
	SpriteEmitter1->AddLocationFromOtherEmitter = 0;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.1, 0.2}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({0.7,3});
	//SpriteEmitter1->SizeScale[2]=FParticleTimeScale({1,5});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {22, 33}, {100, 100}, {100, 100} });
	SpriteEmitter1->InitialParticlesPerSecond = 44;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 2, 2 });
	SpriteEmitter1->InitialDelayRange = FRange({ 0.5, 0.5 });
	Emitters = { MeshEmitter0,SpriteEmitter1 };
	//bNoDelete = false;
};

void Afx_exp_DebrisA::BeginPlay()
{
	//MeshEmitter(Emitters[0]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.Particles.fx_part_tile01", Class'StaticMesh'));
}