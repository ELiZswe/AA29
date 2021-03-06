// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BDMMuzzleFlash/BDMMuzzleFlash.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"
#include "AA29/Object/Actor/Emitter/aux_light_ExpLight/aux_light_ExpLight.h"
#include "Particles/Emitter.h"

ABDMMuzzleFlash::ABDMMuzzleFlash()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->Acceleration = FVector(5, 5, 10);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(138, 143, 149, 211)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({1,FColor(138, 143, 149, 211)});
	SpriteEmitter0->FadeOutStartTime = 0.5;
	SpriteEmitter0->MaxParticles = 1;
	SpriteEmitter0->StartLocationOffset = FVector(0, -80, 0);
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({1,6});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {4, 4}, {100, 100}, {100, 100} });
	SpriteEmitter0->InitialParticlesPerSecond = 22;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->LifetimeRange = FRange({ 3, 3 });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(5, 5, 5);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(138, 143, 149, 211)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(138, 143, 149, 211)});
	SpriteEmitter1->FadeOutStartTime = 0.5;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->StartLocationOffset = FVector(0, -88, 0);
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {25, 25}, {100, 100}, {100, 100} });
	SpriteEmitter1->InitialParticlesPerSecond = 22;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 1, 1.5 });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	SpriteEmitter2->MaxParticles = 1;
	SpriteEmitter2->StartLocationOffset = FVector(0, -88, 0);
	SpriteEmitter2->StartSpinRange = FRangeVector({ {32600, 0}, {0, 0}, {0, 0} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,3});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {8, 10}, {100, 100}, {100, 100} });
	SpriteEmitter2->InitialParticlesPerSecond = 55;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 0.05, 0.05 });
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->Acceleration = FVector(5, -15, 8);
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(138, 143, 149, 211)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(138, 143, 149, 211)});
	SpriteEmitter3->FadeOutStartTime = 0.5;
	SpriteEmitter3->MaxParticles = 1;
	SpriteEmitter3->StartLocationOffset = FVector(0, -1, 0);
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter3->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter3->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({2,3.5});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {25, 20}, {100, 100}, {100, 100} });
	SpriteEmitter3->InitialParticlesPerSecond = 22;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 3, 3 });
	USpriteEmitter* SpriteEmitter4 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter4->UseColorScale = true;
	SpriteEmitter4->FadeOut = true;
	SpriteEmitter4->RespawnDeadParticles = false;
	SpriteEmitter4->SpinParticles = true;
	SpriteEmitter4->UseSizeScale = true;
	SpriteEmitter4->UseRegularSizeScale = false;
	SpriteEmitter4->UniformSize = true;
	SpriteEmitter4->AutomaticInitialSpawning = false;
	SpriteEmitter4->Acceleration = FVector(5, -15, 25);
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(138, 143, 149, 211)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({1,FColor(138, 143, 149, 211)});
	SpriteEmitter4->FadeOutStartTime = 0.5;
	SpriteEmitter4->MaxParticles = 1;
	SpriteEmitter4->StartLocationOffset = FVector(0, -1, 0);
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter4->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter4->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter4->SizeScale[1]=FParticleTimeScale({1,7});
	SpriteEmitter4->StartSizeRange = FRangeVector({ {20, 15}, {100, 100}, {100, 100} });
	SpriteEmitter4->InitialParticlesPerSecond = 22;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 3, 3.5 });
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->RespawnDeadParticles = false;
	SpriteEmitter5->SpinParticles = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->AutomaticInitialSpawning = false;
	SpriteEmitter5->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	SpriteEmitter5->MaxParticles = 1;
	SpriteEmitter5->StartLocationOffset = FVector(0, -9, 0);
	SpriteEmitter5->StartSpinRange = FRangeVector({ {32600, 0}, {0, 0}, {0, 0} });
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter5->SizeScale[1]=FParticleTimeScale({1,3});
	SpriteEmitter5->StartSizeRange = FRangeVector({ {7, 9}, {100, 100}, {100, 100} });
	SpriteEmitter5->InitialParticlesPerSecond = 55;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->LifetimeRange = FRange({ 0.02, 0.02 });
	USpriteEmitter* SpriteEmitter6 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter6->UseColorScale = true;
	SpriteEmitter6->FadeOut = true;
	SpriteEmitter6->RespawnDeadParticles = false;
	SpriteEmitter6->UseSizeScale = true;
	SpriteEmitter6->UseRegularSizeScale = false;
	SpriteEmitter6->UniformSize = true;
	SpriteEmitter6->AutomaticInitialSpawning = false;
	SpriteEmitter6->Acceleration = FVector(0, 0, -777);
	//SpriteEmitter6->ColorScale[0]=FParticleColorScale({0,FColor(140, 194, 255, 0)});
	//SpriteEmitter6->ColorScale[1]=FParticleColorScale({1,FColor(38, 57, 89, 0)});
	SpriteEmitter6->FadeOutStartTime = 0.5;
	SpriteEmitter6->MaxParticles = 1;
	SpriteEmitter6->StartLocationOffset = FVector(0, -22, 0);
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter6->SizeScale[1]=FParticleTimeScale({1,0.8});
	SpriteEmitter6->StartSizeRange = FRangeVector({ {2, 3}, {100, 100}, {100, 100} });
	SpriteEmitter6->InitialParticlesPerSecond = 111;
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->LifetimeRange = FRange({ 0.1, 0.2 });
	SpriteEmitter6->StartVelocityRange = FRangeVector({ {111, -111}, {722, 1155}, {-111, 111} });
	SpriteEmitter6->VelocityLossRange = FRangeVector({ {1, 1}, {1, 1}, {1, 1} });
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->UseColorScale = true;
	SpriteEmitter7->FadeOut = true;
	SpriteEmitter7->RespawnDeadParticles = false;
	SpriteEmitter7->SpinParticles = true;
	SpriteEmitter7->UseSizeScale = true;
	SpriteEmitter7->UseRegularSizeScale = false;
	SpriteEmitter7->UniformSize = true;
	SpriteEmitter7->AutomaticInitialSpawning = false;
	SpriteEmitter7->Acceleration = FVector(0, 0, 20);
	//SpriteEmitter7->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 105)});
	//SpriteEmitter7->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 110)});
	SpriteEmitter7->Opacity = 0.7;
	SpriteEmitter7->FadeOutStartTime = 0.3;
	SpriteEmitter7->MaxParticles = 15;
	SpriteEmitter7->StartLocationOffset = FVector(55, 24, 0);
	SpriteEmitter7->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {24, -24} });
	SpriteEmitter7->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter7->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0, 0}, {0, 0} });
	SpriteEmitter7->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter7->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter7->SizeScale[1]=FParticleTimeScale({2,13});
	SpriteEmitter7->StartSizeRange = FRangeVector({ {25, 15}, {100, 100}, {100, 100} });
	SpriteEmitter7->InitialParticlesPerSecond = 1111;
	SpriteEmitter7->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->LifetimeRange = FRange({ 1, 1.5 });
	SpriteEmitter7->StartVelocityRange = FRangeVector({ {0, 0}, {350, 150}, {-211, 211} });
	SpriteEmitter7->VelocityLossRange = FRangeVector({ {1, 1}, {0, 0}, {1, 1} });
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->UseColorScale = true;
	SpriteEmitter8->FadeOut = true;
	SpriteEmitter8->RespawnDeadParticles = false;
	SpriteEmitter8->SpinParticles = true;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->UniformSize = true;
	SpriteEmitter8->AutomaticInitialSpawning = false;
	SpriteEmitter8->Acceleration = FVector(0, 0, 20);
	//SpriteEmitter8->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 105)});
	//SpriteEmitter8->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 110)});
	SpriteEmitter8->Opacity = 0.5;
	SpriteEmitter8->FadeOutStartTime = 0.3;
	SpriteEmitter8->StartLocationOffset = FVector(55, 7, 0);
	SpriteEmitter8->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {12, -12} });
	SpriteEmitter8->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter8->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0, 0}, {0, 0} });
	SpriteEmitter8->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter8->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter8->SizeScale[1]=FParticleTimeScale({2,10});
	SpriteEmitter8->StartSizeRange = FRangeVector({ {10, 15}, {100, 100}, {100, 100} });
	SpriteEmitter8->InitialParticlesPerSecond = 1111;
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->LifetimeRange = FRange({ 1.5, 2 });
	SpriteEmitter8->StartVelocityRange = FRangeVector({ {0, 0}, {150, 100}, {-111, 111} });
	SpriteEmitter8->VelocityLossRange = FRangeVector({ {1, 1}, {0, 0}, {1, 1} });
	UMeshEmitter* MeshEmitter9 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter9->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_ak47.fx_flash_ak47'"), NULL, LOAD_None, NULL);
	MeshEmitter9->RenderTwoSided = true;
	MeshEmitter9->bUseAbsoluteRotation = true;
	MeshEmitter9->AbsoluteRotationSource = EAbsoluteRotationSource::PARS_ActorOnly;
	MeshEmitter9->FadeOut = true;
	MeshEmitter9->RespawnDeadParticles = false;
	MeshEmitter9->UseSizeScale = true;
	MeshEmitter9->UseRegularSizeScale = false;
	MeshEmitter9->AutomaticInitialSpawning = false;
	MeshEmitter9->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter9->StartLocationOffset = FVector(-8, -25, 0);
	//MeshEmitter9->SizeScale[0]=FParticleTimeScale({0,1});
	//MeshEmitter9->SizeScale[1]=FParticleTimeScale({1,4});
	MeshEmitter9->StartSizeRange = FRangeVector({ {0.575, 0.575}, {0.575, 0.575}, {0.575, 0.575} });
	MeshEmitter9->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	MeshEmitter9->LifetimeRange = FRange({ 0.1, 0.1 });
	MeshEmitter9->iFlashSpawnCount = 1;
	MeshEmitter9->MinFramesBeforeDeath = 1;
	UMeshEmitter* MeshEmitter10 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter10->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_BDM_backblast.fx_flash_BDM_backblast'"), NULL, LOAD_None, NULL);
	MeshEmitter10->RenderTwoSided = true;
	MeshEmitter10->bUseAbsoluteRotation = true;
	MeshEmitter10->AbsoluteRotationSource = EAbsoluteRotationSource::PARS_ActorOnly;
	MeshEmitter10->FadeOut = true;
	MeshEmitter10->RespawnDeadParticles = false;
	MeshEmitter10->UseSizeScale = true;
	MeshEmitter10->UseRegularSizeScale = false;
	MeshEmitter10->AutomaticInitialSpawning = false;
	MeshEmitter10->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter10->MaxParticles = 1;
	MeshEmitter10->StartLocationOffset = FVector(-8, -70, 0);
	//MeshEmitter10->SizeScale[0]=FParticleTimeScale({0,1});
	//MeshEmitter10->SizeScale[1]=FParticleTimeScale({1,14});
	MeshEmitter10->StartSizeRange = FRangeVector({ {0.25, 0.25}, {0.25, 0.25}, {0.25, 0.25} });
	MeshEmitter10->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	MeshEmitter10->LifetimeRange = FRange({ 0.1, 0.1 });
	MeshEmitter10->iFlashSpawnCount = 1;
	MeshEmitter10->MinFramesBeforeDeath = 1;
	UMeshEmitter* MeshEmitter11 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter11->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_BDM.fx_flash_BDM'"), NULL, LOAD_None, NULL);
	MeshEmitter11->RenderTwoSided = true;
	MeshEmitter11->bUseAbsoluteRotation = true;
	MeshEmitter11->AbsoluteRotationSource = EAbsoluteRotationSource::PARS_ActorOnly;
	MeshEmitter11->FadeOut = true;
	MeshEmitter11->RespawnDeadParticles = false;
	MeshEmitter11->UseSizeScale = true;
	MeshEmitter11->UseRegularSizeScale = false;
	MeshEmitter11->AutomaticInitialSpawning = false;
	MeshEmitter11->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter11->MaxParticles = 1;
	MeshEmitter11->StartLocationOffset = FVector(0, -75, 0);
	//MeshEmitter11->SizeScale[0]=FParticleTimeScale({0,1});
	//MeshEmitter11->SizeScale[1]=FParticleTimeScale({1,5});
	MeshEmitter11->StartSizeRange = FRangeVector({ {0.25, 0.25}, {0.25, 0.25}, {0.25, 0.25} });
	MeshEmitter11->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	MeshEmitter11->LifetimeRange = FRange({ 0.04, 0.04 });
	MeshEmitter11->iFlashSpawnCount = 1;
	MeshEmitter11->MinFramesBeforeDeath = 1;
	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4,SpriteEmitter5,SpriteEmitter6,SpriteEmitter7,SpriteEmitter8,MeshEmitter9,MeshEmitter10,MeshEmitter11 };
	LifeSpan = 10;
};

void ABDMMuzzleFlash::SpawnLight()
{
	AEmitter* E = nullptr;
	FVector NewRel = FVector(0, 0, 0);
	/*
	E = Spawn(Aaux_light_ExpLight::StaticClass());
	E.SetBase(this);
	NewRel.Y = 1000;
	E.SetRelativeLocation(NewRel);
	*/
}

