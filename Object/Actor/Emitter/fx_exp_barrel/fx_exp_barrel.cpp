// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/fx_exp_barrel/fx_exp_barrel.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"
#include "AA29/Object/Actor/Emitter/aux_light_ExpLight/aux_light_ExpLight.h"

Afx_exp_barrel::Afx_exp_barrel()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/exploding_barrel/exp_barrel01.exp_barrel01'"), NULL, LOAD_None, NULL);
	MeshEmitter0->UseCollision = true;
	MeshEmitter0->UseMaxCollisions = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AutoDestroy = true;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->Acceleration = FVector(0, 0, -950);
	MeshEmitter0->DampingFactorRange = FRangeVector({ {0.9, 0.9}, {0.9, 0.9}, {0.9, 0.9} });
	MeshEmitter0->MaxCollisions = FRange({ 2, 2 });
	MeshEmitter0->MaxParticles = 1;
	MeshEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	MeshEmitter0->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0.2, 0.3}, {0.2, 0.3} });
	MeshEmitter0->InitialParticlesPerSecond = 5;
	MeshEmitter0->SecondsBeforeInactive = 0;
	MeshEmitter0->LifetimeRange = FRange({ 6, 6 });
	MeshEmitter0->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {650, 650} });
	UMeshEmitter* MeshEmitter1 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter1->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/exploding_barrel/exp_barrel02.exp_barrel02'"), NULL, LOAD_None, NULL);
	MeshEmitter1->UseCollision = true;
	MeshEmitter1->UseMaxCollisions = true;
	MeshEmitter1->RespawnDeadParticles = false;
	MeshEmitter1->AutoDestroy = true;
	MeshEmitter1->SpinParticles = true;
	MeshEmitter1->Acceleration = FVector(0, 0, -740);
	MeshEmitter1->DampingFactorRange = FRangeVector({ {0.9, 0.9}, {0.9, 0.9}, {0.9, 0.9} });
	MeshEmitter1->MaxCollisions = FRange({ 2, 2 });
	MeshEmitter1->MaxParticles = 1;
	MeshEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	MeshEmitter1->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0.2, 0.3}, {0.2, 0.3} });
	MeshEmitter1->InitialParticlesPerSecond = 5;
	MeshEmitter1->SecondsBeforeInactive = 0;
	MeshEmitter1->LifetimeRange = FRange({ 6, 6 });
	MeshEmitter1->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {650, 650} });
	UMeshEmitter* MeshEmitter2 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter2->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/exploding_barrel/exp_barrel03.exp_barrel03'"), NULL, LOAD_None, NULL);
	MeshEmitter2->UseCollision = true;
	MeshEmitter2->UseMaxCollisions = true;
	MeshEmitter2->RespawnDeadParticles = false;
	MeshEmitter2->AutoDestroy = true;
	MeshEmitter2->SpinParticles = true;
	MeshEmitter2->Acceleration = FVector(0, 0, -740);
	MeshEmitter2->DampingFactorRange = FRangeVector({ {0.9, 0.9}, {0.9, 0.9}, {0.9, 0.9} });
	MeshEmitter2->MaxCollisions = FRange({ 2, 2 });
	MeshEmitter2->MaxParticles = 1;
	MeshEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	MeshEmitter2->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0.2, 0.3}, {0.2, 0.3} });
	MeshEmitter2->InitialParticlesPerSecond = 5;
	MeshEmitter2->SecondsBeforeInactive = 0;
	MeshEmitter2->LifetimeRange = FRange({ 6, 6 });
	MeshEmitter2->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {950, 650} });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseCollision = true;
	SpriteEmitter1->UseMaxCollisions = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, 25);
	SpriteEmitter1->MaxCollisions = FRange({ 1, 1 });
	SpriteEmitter1->MaxParticles = 100;
	SpriteEmitter1->AddLocationFromOtherEmitter = 0;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter1->StartSpinRange = FRangeVector({ {300, -300}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({1,10});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {10, 10}, {100, 100}, {100, 100} });
	SpriteEmitter1->InitialParticlesPerSecond = 110;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.3, 0.3 });
	SpriteEmitter1->InitialDelayRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseCollision = true;
	SpriteEmitter2->UseMaxCollisions = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->Acceleration = FVector(0, 0, 25);
	SpriteEmitter2->MaxCollisions = FRange({ 1, 1 });
	SpriteEmitter2->MaxParticles = 100;
	SpriteEmitter2->AddLocationFromOtherEmitter = 1;
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter2->StartSpinRange = FRangeVector({ {300, -300}, {0, 0}, {0, 0} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({1,10});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {10, 10}, {100, 100}, {100, 100} });
	SpriteEmitter2->InitialParticlesPerSecond = 110;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 0.3, 0.5 });
	SpriteEmitter2->InitialDelayRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseCollision = true;
	SpriteEmitter3->UseMaxCollisions = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->Acceleration = FVector(0, 0, 25);
	SpriteEmitter3->MaxCollisions = FRange({ 1, 1 });
	SpriteEmitter3->MaxParticles = 100;
	SpriteEmitter3->AddLocationFromOtherEmitter = 2;
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter3->StartSpinRange = FRangeVector({ {300, -300}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({1,10});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {10, 10}, {100, 100}, {100, 100} });
	SpriteEmitter3->InitialParticlesPerSecond = 110;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 0.3, 0.5 });
	SpriteEmitter3->InitialDelayRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->FadeIn = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->AutoDestroy = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->Acceleration = FVector(0, 0, 100);
	SpriteEmitter0->FadeOutStartTime = 0.1;
	SpriteEmitter0->MaxParticles = 3;
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter0->StartSpinRange = FRangeVector({ {300, -300}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0.5,2});
	SpriteEmitter0->InitialParticlesPerSecond = 20;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter0->InitialDelayRange = FRange({ 0.2, 0.2 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {50, 50} });
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->FadeOut = true;
	SpriteEmitter5->RespawnDeadParticles = false;
	SpriteEmitter5->AutoDestroy = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->AutomaticInitialSpawning = false;
	SpriteEmitter5->FadeOutStartTime = 1;
	SpriteEmitter5->MaxParticles = 1;
	SpriteEmitter5->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({1,4});
	SpriteEmitter5->InitialParticlesPerSecond = 100;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->SecondsBeforeInactive = 0;
	SpriteEmitter5->LifetimeRange = FRange({ 3, 3 });
	SpriteEmitter5->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {50, 50} });
	USpriteEmitter* SpriteEmitter6 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter6->FadeOut = true;
	SpriteEmitter6->FadeIn = true;
	SpriteEmitter6->RespawnDeadParticles = false;
	SpriteEmitter6->AutoDestroy = true;
	SpriteEmitter6->SpinParticles = true;
	SpriteEmitter6->UseSizeScale = true;
	SpriteEmitter6->UseRegularSizeScale = false;
	SpriteEmitter6->UniformSize = true;
	SpriteEmitter6->AutomaticInitialSpawning = false;
	SpriteEmitter6->MaxParticles = 1;
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter6->StartSpinRange = FRangeVector({ {3, -3}, {0, 0}, {0, 0} });
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({1,7});
	SpriteEmitter6->InitialParticlesPerSecond = 20;
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->SecondsBeforeInactive = 0;
	SpriteEmitter6->LifetimeRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->FadeOut = true;
	SpriteEmitter7->RespawnDeadParticles = false;
	SpriteEmitter7->AutoDestroy = true;
	SpriteEmitter7->SpinParticles = true;
	SpriteEmitter7->UniformSize = true;
	SpriteEmitter7->AutomaticInitialSpawning = false;
	SpriteEmitter7->BlendBetweenSubdivisions = true;
	SpriteEmitter7->MaxParticles = 1;
	SpriteEmitter7->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter7->StartSpinRange = FRangeVector({ {30, -30}, {0, 0}, {0, 0} });
	SpriteEmitter7->InitialParticlesPerSecond = 100;
	SpriteEmitter7->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_explosion01_Mat.fx_part_explosion01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->TextureUSubdivisions = 4;
	SpriteEmitter7->TextureVSubdivisions = 2;
	SpriteEmitter7->SecondsBeforeInactive = 0;
	SpriteEmitter7->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter7->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {300, 300} });
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->UseDirectionAs = EParticleDirectionUsage::PTDU_Normal;
	SpriteEmitter8->FadeOut = true;
	SpriteEmitter8->RespawnDeadParticles = false;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->AutomaticInitialSpawning = false;
	SpriteEmitter8->MaxParticles = 1;
	//SpriteEmitter8->SizeScale[0]=FParticleTimeScale({10,1000});
	SpriteEmitter8->InitialParticlesPerSecond = 110;
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_ring_Mat.fx_part_ring_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->SecondsBeforeInactive = 0;
	SpriteEmitter8->LifetimeRange = FRange({ 3, 3 });
	Emitters = { MeshEmitter0,MeshEmitter1,MeshEmitter2,nullptr,nullptr,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter0,SpriteEmitter5,SpriteEmitter6,SpriteEmitter7,SpriteEmitter8 };
};

void Afx_exp_barrel::PostBeginPlay()
{
	SpawnLight();
}

void Afx_exp_barrel::SpawnLight()
{
	////Spawn(Aaux_light_ExpLight::StaticClass());
}

void Afx_exp_barrel::BeginPlay()
{
	//MeshEmitter(Emitters[0]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.exploding_barrel.exp_barrel01", Class'StaticMesh'));
	//MeshEmitter(Emitters[1]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.exploding_barrel.exp_barrel02", Class'StaticMesh'));
	//MeshEmitter(Emitters[2]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.exploding_barrel.exp_barrel03", Class'StaticMesh'));
}
