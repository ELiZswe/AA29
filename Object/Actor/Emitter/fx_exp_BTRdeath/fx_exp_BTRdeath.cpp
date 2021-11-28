// All the original content belonged to the US Army

#include "fx_exp_BTRdeath.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Afx_exp_BTRdeath::Afx_exp_BTRdeath()
{
	UMeshEmitter* MeshEmitter1 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter1->UseCollision = true;
	MeshEmitter1->UseMaxCollisions = true;
	MeshEmitter1->RespawnDeadParticles = false;
	MeshEmitter1->AutoDestroy = true;
	MeshEmitter1->SpinParticles = true;
	MeshEmitter1->AutomaticInitialSpawning = false;
	MeshEmitter1->Acceleration = FVector(0, 0, -999);
	MeshEmitter1->DampingFactorRange = FRangeVector({ {0.6, 0.6}, {0.6, 0.6}, {0.2, 0.2} });
	MeshEmitter1->MaxCollisions = FRange({ 2, 2 });
	MeshEmitter1->MaxParticles = 1;
	MeshEmitter1->StartLocationRange = FRangeVector({ {-122, -122}, {-77, -77}, {0, 0} });
	MeshEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	MeshEmitter1->SpinsPerSecondRange = FRangeVector({ {0.01, 0.5}, {0.01, 0.5}, {-0.01, -2} });
	MeshEmitter1->StartSizeRange = FRangeVector({ {0.7, 0.7}, {0.7, 0.7}, {0.7, 0.7} });
	MeshEmitter1->InitialParticlesPerSecond = 500;
	MeshEmitter1->SecondsBeforeInactive = 0;
	MeshEmitter1->LifetimeRange = FRange({ 3.5, 3.5 });
	MeshEmitter1->InitialDelayRange = FRange({ 0.25, 0.3 });
	MeshEmitter1->StartVelocityRange = FRangeVector({ {-600, 600}, {-600, 600}, {800, 1200} });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(72, 72, 72, 222)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({0.5,FColor(56, 56, 56, 122)});
	//SpriteEmitter2->ColorScale[2]=FParticleColorScale({1,FColor(32, 32, 32, 55)});
	SpriteEmitter2->FadeOutStartTime = 2;
	SpriteEmitter2->FadeInEndTime = 1;
	SpriteEmitter2->MaxParticles = 22;
	SpriteEmitter2->AddLocationFromOtherEmitter = 0;
	SpriteEmitter2->SpinsPerSecondRange = FRangeVector({ {0.1, 0.2}, {0, 0}, {0, 0} });
	SpriteEmitter2->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({0.7,3});
	//SpriteEmitter2->SizeScale[2]=FParticleTimeScale({1,5});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {22, 33}, {100, 100}, {100, 100} });
	SpriteEmitter2->InitialParticlesPerSecond = 12;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 2, 2 });
	SpriteEmitter2->InitialDelayRange = FRange({ 0.5, 0.5 });
	Emitters = { MeshEmitter1,SpriteEmitter2 };
	//bNoDelete = false;
};

void Afx_exp_BTRdeath::BeginPlay()
{
	//MeshEmitter(Emitters[0]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_Vehicles.BTR-80.veh2_btr80_btr_turret_broken", Class'StaticMesh'));
}
