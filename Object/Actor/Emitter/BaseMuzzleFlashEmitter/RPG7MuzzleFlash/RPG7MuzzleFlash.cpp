// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/RPG7MuzzleFlash/RPG7MuzzleFlash.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

ARPG7MuzzleFlash::ARPG7MuzzleFlash()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(5, 5, -5);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(39, 39, 39, 155)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(39, 39, 39, 155)});
	SpriteEmitter1->FadeOutStartTime = 0.5;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->StartLocationOffset = FVector(0, -111, 0);
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {50, 50}, {100, 100}, {100, 100} });
	SpriteEmitter1->InitialParticlesPerSecond = 22;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_dk_base_Mat.fx_smk_dk_base_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 3, 5 });
	USpriteEmitter* SpriteEmitter4 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter4->UseColorScale = true;
	SpriteEmitter4->FadeOut = true;
	SpriteEmitter4->RespawnDeadParticles = false;
	SpriteEmitter4->SpinParticles = true;
	SpriteEmitter4->UseSizeScale = true;
	SpriteEmitter4->UseRegularSizeScale = false;
	SpriteEmitter4->UniformSize = true;
	SpriteEmitter4->AutomaticInitialSpawning = false;
	SpriteEmitter4->Acceleration = FVector(5, 5, -5);
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(39, 39, 39, 155)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({1,FColor(39, 39, 39, 155)});
	SpriteEmitter4->FadeOutStartTime = 0.5;
	SpriteEmitter4->MaxParticles = 1;
	SpriteEmitter4->StartLocationOffset = FVector(0, -133, 0);
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter4->SpinsPerSecondRange = FRangeVector({ {0.07, 0.05}, {0, 0}, {0, 0} });
	SpriteEmitter4->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter4->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter4->StartSizeRange = FRangeVector({ {55, 55}, {100, 100}, {100, 100} });
	SpriteEmitter4->InitialParticlesPerSecond = 22;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_dk_base_Mat.fx_smk_dk_base_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 3, -5 });
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->UseColorScale = true;
	SpriteEmitter5->FadeOut = true;
	SpriteEmitter5->RespawnDeadParticles = false;
	SpriteEmitter5->SpinParticles = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->AutomaticInitialSpawning = false;
	SpriteEmitter5->Acceleration = FVector(5, 5, -5);
	//SpriteEmitter5->ColorScale[0]=FParticleColorScale({0,FColor(39, 39, 39, 155)});
	//SpriteEmitter5->ColorScale[1]=FParticleColorScale({1,FColor(39, 39, 39, 155)});
	SpriteEmitter5->FadeOutStartTime = 0.5;
	SpriteEmitter5->MaxParticles = 1;
	SpriteEmitter5->StartLocationOffset = FVector(0, -155, 0);
	SpriteEmitter5->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter5->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter5->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter5->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter5->StartSizeRange = FRangeVector({ {44, 44}, {100, 100}, {100, 100} });
	SpriteEmitter5->InitialParticlesPerSecond = 22;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_dk_base_Mat.fx_smk_dk_base_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->LifetimeRange = FRange({ 3, 5 });
	USpriteEmitter* SpriteEmitter6 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter6->UseColorScale = true;
	SpriteEmitter6->FadeOut = true;
	SpriteEmitter6->RespawnDeadParticles = false;
	SpriteEmitter6->SpinParticles = true;
	SpriteEmitter6->UseSizeScale = true;
	SpriteEmitter6->UseRegularSizeScale = false;
	SpriteEmitter6->UniformSize = true;
	SpriteEmitter6->AutomaticInitialSpawning = false;
	SpriteEmitter6->Acceleration = FVector(5, 5, -5);
	//SpriteEmitter6->ColorScale[0]=FParticleColorScale({0,FColor(39, 39, 39, 155)});
	//SpriteEmitter6->ColorScale[1]=FParticleColorScale({1,FColor(39, 39, 39, 155)});
	SpriteEmitter6->FadeOutStartTime = 0.5;
	SpriteEmitter6->MaxParticles = 1;
	SpriteEmitter6->StartLocationOffset = FVector(0, -177, 0);
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter6->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter6->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter6->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter6->StartSizeRange = FRangeVector({ {40, 40}, {100, 100}, {100, 100} });
	SpriteEmitter6->InitialParticlesPerSecond = 22;
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_dk_base_Mat.fx_smk_dk_base_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->LifetimeRange = FRange({ 3, 5 });
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->UseColorScale = true;
	SpriteEmitter8->FadeOut = true;
	SpriteEmitter8->RespawnDeadParticles = false;
	SpriteEmitter8->SpinParticles = true;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->UniformSize = true;
	SpriteEmitter8->AutomaticInitialSpawning = false;
	SpriteEmitter8->Acceleration = FVector(5, 5, -5);
	//SpriteEmitter8->ColorScale[0]=FParticleColorScale({0,FColor(39, 39, 39, 155)});
	//SpriteEmitter8->ColorScale[1]=FParticleColorScale({1,FColor(39, 39, 39, 155)});
	SpriteEmitter8->FadeOutStartTime = 0.5;
	SpriteEmitter8->MaxParticles = 1;
	SpriteEmitter8->StartLocationOffset = FVector(0, 11, 0);
	SpriteEmitter8->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter8->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter8->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter8->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter8->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter8->StartSizeRange = FRangeVector({ {44, 44}, {100, 100}, {100, 100} });
	SpriteEmitter8->InitialParticlesPerSecond = 22;
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_dk_base_Mat.fx_smk_dk_base_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->LifetimeRange = FRange({ 3, 5 });
	USpriteEmitter* SpriteEmitter9 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter9->UseColorScale = true;
	SpriteEmitter9->FadeOut = true;
	SpriteEmitter9->RespawnDeadParticles = false;
	SpriteEmitter9->SpinParticles = true;
	SpriteEmitter9->UseSizeScale = true;
	SpriteEmitter9->UseRegularSizeScale = false;
	SpriteEmitter9->UniformSize = true;
	SpriteEmitter9->AutomaticInitialSpawning = false;
	SpriteEmitter9->Acceleration = FVector(5, 5, -5);
	//SpriteEmitter9->ColorScale[0]=FParticleColorScale({0,FColor(39, 39, 39, 155)});
	//SpriteEmitter9->ColorScale[1]=FParticleColorScale({1,FColor(39, 39, 39, 155)});
	SpriteEmitter9->FadeOutStartTime = 0.5;
	SpriteEmitter9->MaxParticles = 1;
	SpriteEmitter9->StartLocationOffset = FVector(0, 44, 0);
	SpriteEmitter9->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter9->SpinsPerSecondRange = FRangeVector({ {0.05, 0.01}, {0, 0}, {0, 0} });
	SpriteEmitter9->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter9->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter9->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter9->StartSizeRange = FRangeVector({ {33, 33}, {100, 100}, {100, 100} });
	SpriteEmitter9->InitialParticlesPerSecond = 22;
	SpriteEmitter9->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter9->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_dk_base_Mat.fx_smk_dk_base_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter9->LifetimeRange = FRange({ 3, 5 });
	USpriteEmitter* SpriteEmitter11 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter11->RespawnDeadParticles = false;
	SpriteEmitter11->SpinParticles = true;
	SpriteEmitter11->UseSizeScale = true;
	SpriteEmitter11->UseRegularSizeScale = false;
	SpriteEmitter11->UniformSize = true;
	SpriteEmitter11->AutomaticInitialSpawning = false;
	SpriteEmitter11->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	SpriteEmitter11->MaxParticles = 1;
	SpriteEmitter11->StartLocationOffset = FVector(0, -5, 0);
	SpriteEmitter11->StartSpinRange = FRangeVector({ {32600, 0}, {0, 0}, {0, 0} });
	//SpriteEmitter11->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter11->SizeScale[1]=FParticleTimeScale({0,0});
	//SpriteEmitter11->SizeScale[2]=FParticleTimeScale({1,3});
	SpriteEmitter11->StartSizeRange = FRangeVector({ {7, 9}, {100, 100}, {100, 100} });
	SpriteEmitter11->InitialParticlesPerSecond = 22;
	SpriteEmitter11->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter11->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter11->LifetimeRange = FRange({ 0.05, 0.05 });
	USpriteEmitter* SpriteEmitter12 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter12->UseColorScale = true;
	SpriteEmitter12->FadeOut = true;
	SpriteEmitter12->RespawnDeadParticles = false;
	SpriteEmitter12->UseSizeScale = true;
	SpriteEmitter12->UseRegularSizeScale = false;
	SpriteEmitter12->UniformSize = true;
	SpriteEmitter12->AutomaticInitialSpawning = false;
	SpriteEmitter12->Acceleration = FVector(0, 0, -777);
	//SpriteEmitter12->ColorScale[0]=FParticleColorScale({0,FColor(140, 194, 255, 0)});
	//SpriteEmitter12->ColorScale[1]=FParticleColorScale({1,FColor(38, 57, 89, 0)});
	SpriteEmitter12->FadeOutStartTime = 0.5;
	SpriteEmitter12->MaxParticles = 11;
	SpriteEmitter12->StartLocationOffset = FVector(0, -15, 0);
	SpriteEmitter12->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter12->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter12->SizeScale[1]=FParticleTimeScale({1,0.8});
	SpriteEmitter12->StartSizeRange = FRangeVector({ {2, 3}, {100, 100}, {100, 100} });
	SpriteEmitter12->InitialParticlesPerSecond = 222;
	SpriteEmitter12->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter12->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter12->LifetimeRange = FRange({ 0.1, 0.2 });
	SpriteEmitter12->StartVelocityRange = FRangeVector({ {111, -111}, {722, 1155}, {-111, 111} });
	SpriteEmitter12->VelocityLossRange = FRangeVector({ {1, 1}, {1, 1}, {1, 1} });
	USpriteEmitter* SpriteEmitter13 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter13->UseColorScale = true;
	SpriteEmitter13->FadeOut = true;
	SpriteEmitter13->RespawnDeadParticles = false;
	SpriteEmitter13->UseSizeScale = true;
	SpriteEmitter13->UseRegularSizeScale = false;
	SpriteEmitter13->UniformSize = true;
	SpriteEmitter13->AutomaticInitialSpawning = false;
	SpriteEmitter13->Acceleration = FVector(0, 0, -777);
	//SpriteEmitter13->ColorScale[0]=FParticleColorScale({0,FColor(140, 194, 255, 0)});
	//SpriteEmitter13->ColorScale[1]=FParticleColorScale({1,FColor(38, 57, 89, 0)});
	SpriteEmitter13->FadeOutStartTime = 0.5;
	SpriteEmitter13->MaxParticles = 15;
	SpriteEmitter13->StartLocationOffset = FVector(0, -70, 0);
	SpriteEmitter13->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter13->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter13->SizeScale[1]=FParticleTimeScale({1,0.8});
	SpriteEmitter13->StartSizeRange = FRangeVector({ {2, 3}, {100, 100}, {100, 100} });
	SpriteEmitter13->InitialParticlesPerSecond = 222;
	SpriteEmitter13->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter13->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter13->LifetimeRange = FRange({ 0.1, 0.2 });
	SpriteEmitter13->StartVelocityRange = FRangeVector({ {111, -111}, {-922, -1455}, {-111, 111} });
	SpriteEmitter13->VelocityLossRange = FRangeVector({ {1, 1}, {1, 1}, {1, 1} });
	USpriteEmitter* SpriteEmitter14 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter14->UseColorScale = true;
	SpriteEmitter14->FadeOut = true;
	SpriteEmitter14->RespawnDeadParticles = false;
	SpriteEmitter14->SpinParticles = true;
	SpriteEmitter14->UseSizeScale = true;
	SpriteEmitter14->UseRegularSizeScale = false;
	SpriteEmitter14->UniformSize = true;
	SpriteEmitter14->AutomaticInitialSpawning = false;
	SpriteEmitter14->Acceleration = FVector(5, 5, -5);
	//SpriteEmitter14->ColorScale[0]=FParticleColorScale({0,FColor(138, 143, 149, 122)});
	//SpriteEmitter14->ColorScale[1]=FParticleColorScale({1,FColor(138, 143, 149, 122)});
	SpriteEmitter14->FadeOutStartTime = 0.5;
	SpriteEmitter14->MaxParticles = 4;
	SpriteEmitter14->StartLocationRange = FRangeVector({ {-99, -99}, {-119, -99}, {-111, 111} });
	SpriteEmitter14->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter14->SpinsPerSecondRange = FRangeVector({ {0.01, 0.07}, {0, 0}, {0, 0} });
	SpriteEmitter14->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter14->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter14->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter14->StartSizeRange = FRangeVector({ {66, 99}, {100, 100}, {100, 100} });
	SpriteEmitter14->InitialParticlesPerSecond = 44;
	SpriteEmitter14->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter14->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter14->LifetimeRange = FRange({ 5, 7 });
	SpriteEmitter14->StartVelocityRange = FRangeVector({ {0, 0}, {-14, -11}, {0, 0} });
	Emitters = { SpriteEmitter1,SpriteEmitter4,SpriteEmitter5,SpriteEmitter6,SpriteEmitter8,SpriteEmitter9,SpriteEmitter11,SpriteEmitter12,SpriteEmitter13,SpriteEmitter14 };
	LifeSpan = 10;
};

void ARPG7MuzzleFlash::DynamicFlash()
{
	/*
	local Emitter E;
	FVector NewRel = FVector(0, 0, 0);
	E = Spawn(class'AGP_Effects.aux_light_ExpLight');
	E.SetBase(Self);
	NewRel.X = 250;
	E.SetRelativeLocation(NewRel);
	*/
}
