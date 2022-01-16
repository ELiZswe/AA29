// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/fx_exp_generator/fx_exp_generator.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"
#include "AA29/Object/Actor/Emitter/aux_light_ExpLight/aux_light_ExpLight.h"

Afx_exp_generator::Afx_exp_generator()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/generator/fx_gen_exp01.fx_gen_exp01'"), NULL, LOAD_None, NULL);
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
	MeshEmitter0->LifetimeRange = FRange({ 3, 3 });
	MeshEmitter0->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {650, 650} });
	UMeshEmitter* MeshEmitter1 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter1->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/generator/fx_gen_exp02.fx_gen_exp02'"), NULL, LOAD_None, NULL);
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
	MeshEmitter1->LifetimeRange = FRange({ 3, 3 });
	MeshEmitter1->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {650, 650} });
	UMeshEmitter* MeshEmitter2 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter2->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/generator/fx_gen_exp03.fx_gen_exp03'"), NULL, LOAD_None, NULL);
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
	MeshEmitter2->LifetimeRange = FRange({ 3, 3 });
	MeshEmitter2->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {950, 650} });
	UMeshEmitter* MeshEmitter3 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter3->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/generator/fx_gen_exp04.fx_gen_exp04'"), NULL, LOAD_None, NULL);
	MeshEmitter3->UseCollision = true;
	MeshEmitter3->UseMaxCollisions = true;
	MeshEmitter3->RespawnDeadParticles = false;
	MeshEmitter3->AutoDestroy = true;
	MeshEmitter3->SpinParticles = true;
	MeshEmitter3->Acceleration = FVector(0, 0, -740);
	MeshEmitter3->DampingFactorRange = FRangeVector({ {0.9, 0.9}, {0.9, 0.9}, {0.9, 0.9} });
	MeshEmitter3->MaxCollisions = FRange({ 2, 2 });
	MeshEmitter3->MaxParticles = 1;
	MeshEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	MeshEmitter3->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0.2, 0.3}, {0.2, 0.3} });
	MeshEmitter3->InitialParticlesPerSecond = 5;
	MeshEmitter3->SecondsBeforeInactive = 0;
	MeshEmitter3->LifetimeRange = FRange({ 3, 3 });
	MeshEmitter3->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {650, 650} });
	UMeshEmitter* MeshEmitter4 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter4->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/generator/fx_gen_exp05.fx_gen_exp05'"), NULL, LOAD_None, NULL);
	MeshEmitter4->UseCollision = true;
	MeshEmitter4->UseMaxCollisions = true;
	MeshEmitter4->RespawnDeadParticles = false;
	MeshEmitter4->AutoDestroy = true;
	MeshEmitter4->SpinParticles = true;
	MeshEmitter4->Acceleration = FVector(0, 0, -740);
	MeshEmitter4->DampingFactorRange = FRangeVector({ {0.9, 0.9}, {0.9, 0.9}, {0.9, 0.9} });
	MeshEmitter4->MaxCollisions = FRange({ 2, 2 });
	MeshEmitter4->MaxParticles = 1;
	MeshEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	MeshEmitter4->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0.2, 0.3}, {0.2, 0.3} });
	MeshEmitter4->InitialParticlesPerSecond = 5;
	MeshEmitter4->SecondsBeforeInactive = 0;
	MeshEmitter4->LifetimeRange = FRange({ 3, 3 });
	MeshEmitter4->StartVelocityRange = FRangeVector({ {-500, 500}, {-500, 500}, {650, 650} });
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
	USpriteEmitter* SpriteEmitter4 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter4->UseCollision = true;
	SpriteEmitter4->UseMaxCollisions = true;
	SpriteEmitter4->FadeOut = true;
	SpriteEmitter4->RespawnDeadParticles = false;
	SpriteEmitter4->SpinParticles = true;
	SpriteEmitter4->UseSizeScale = true;
	SpriteEmitter4->UseRegularSizeScale = false;
	SpriteEmitter4->UniformSize = true;
	SpriteEmitter4->AutomaticInitialSpawning = false;
	SpriteEmitter4->Acceleration = FVector(0, 0, 25);
	SpriteEmitter4->MaxCollisions = FRange({ 1, 1 });
	SpriteEmitter4->MaxParticles = 100;
	SpriteEmitter4->AddLocationFromOtherEmitter = 3;
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter4->StartSpinRange = FRangeVector({ {300, -300}, {0, 0}, {0, 0} });
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({1,10});
	SpriteEmitter4->StartSizeRange = FRangeVector({ {10, 10}, {100, 100}, {100, 100} });
	SpriteEmitter4->InitialParticlesPerSecond = 110;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->SecondsBeforeInactive = 0;
	SpriteEmitter4->LifetimeRange = FRange({ 0.3, 0.5 });
	SpriteEmitter4->InitialDelayRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->UseCollision = true;
	SpriteEmitter5->UseMaxCollisions = true;
	SpriteEmitter5->FadeOut = true;
	SpriteEmitter5->RespawnDeadParticles = false;
	SpriteEmitter5->SpinParticles = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->AutomaticInitialSpawning = false;
	SpriteEmitter5->Acceleration = FVector(0, 0, 25);
	SpriteEmitter5->MaxCollisions = FRange({ 1, 1 });
	SpriteEmitter5->MaxParticles = 100;
	SpriteEmitter5->AddLocationFromOtherEmitter = 4;
	SpriteEmitter5->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter5->StartSpinRange = FRangeVector({ {300, -300}, {0, 0}, {0, 0} });
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({1,10});
	SpriteEmitter5->StartSizeRange = FRangeVector({ {10, 10}, {100, 100}, {100, 100} });
	SpriteEmitter5->InitialParticlesPerSecond = 110;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->SecondsBeforeInactive = 0;
	SpriteEmitter5->LifetimeRange = FRange({ 0.3, 0.5 });
	SpriteEmitter5->InitialDelayRange = FRange({ 0.1, 0.1 });
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
	SpriteEmitter6->Acceleration = FVector(0, 0, 100);
	SpriteEmitter6->FadeOutStartTime = 0.1;
	SpriteEmitter6->MaxParticles = 3;
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter6->StartSpinRange = FRangeVector({ {300, -300}, {0, 0}, {0, 0} });
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({0.5,2});
	SpriteEmitter6->InitialParticlesPerSecond = 20;
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->SecondsBeforeInactive = 0;
	SpriteEmitter6->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter6->InitialDelayRange = FRange({ 0.2, 0.2 });
	SpriteEmitter6->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {50, 50} });
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->FadeOut = true;
	SpriteEmitter7->RespawnDeadParticles = false;
	SpriteEmitter7->AutoDestroy = true;
	SpriteEmitter7->UseSizeScale = true;
	SpriteEmitter7->UseRegularSizeScale = false;
	SpriteEmitter7->UniformSize = true;
	SpriteEmitter7->AutomaticInitialSpawning = false;
	SpriteEmitter7->FadeOutStartTime = 1;
	SpriteEmitter7->MaxParticles = 1;
	SpriteEmitter7->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter7->SizeScale[0]=FParticleTimeScale({1,4});
	SpriteEmitter7->InitialParticlesPerSecond = 100;
	SpriteEmitter7->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->SecondsBeforeInactive = 0;
	SpriteEmitter7->LifetimeRange = FRange({ 3, 3 });
	SpriteEmitter7->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {50, 50} });
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->FadeOut = true;
	SpriteEmitter8->FadeIn = true;
	SpriteEmitter8->RespawnDeadParticles = false;
	SpriteEmitter8->AutoDestroy = true;
	SpriteEmitter8->SpinParticles = true;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->UniformSize = true;
	SpriteEmitter8->AutomaticInitialSpawning = false;
	SpriteEmitter8->MaxParticles = 1;
	SpriteEmitter8->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter8->StartSpinRange = FRangeVector({ {3, -3}, {0, 0}, {0, 0} });
	//SpriteEmitter8->SizeScale[0]=FParticleTimeScale({1,7});
	SpriteEmitter8->InitialParticlesPerSecond = 20;
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->SecondsBeforeInactive = 0;
	SpriteEmitter8->LifetimeRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter9 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter9->FadeOut = true;
	SpriteEmitter9->RespawnDeadParticles = false;
	SpriteEmitter9->AutoDestroy = true;
	SpriteEmitter9->SpinParticles = true;
	SpriteEmitter9->UniformSize = true;
	SpriteEmitter9->AutomaticInitialSpawning = false;
	SpriteEmitter9->BlendBetweenSubdivisions = true;
	SpriteEmitter9->MaxParticles = 1;
	SpriteEmitter9->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter9->StartSpinRange = FRangeVector({ {30, -30}, {0, 0}, {0, 0} });
	SpriteEmitter9->InitialParticlesPerSecond = 100;
	SpriteEmitter9->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter9->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_explosion01_Mat.fx_part_explosion01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter9->TextureUSubdivisions = 4;
	SpriteEmitter9->TextureVSubdivisions = 2;
	SpriteEmitter9->SecondsBeforeInactive = 0;
	SpriteEmitter9->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter9->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {300, 300} });
	Emitters = { MeshEmitter0,MeshEmitter1,MeshEmitter2,MeshEmitter3,MeshEmitter4,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4,SpriteEmitter5,SpriteEmitter6,SpriteEmitter7,SpriteEmitter8,SpriteEmitter9 };
	//bNoDelete = false;
};

void Afx_exp_generator::PostBeginPlay()
{
	SpawnLight();
}

void Afx_exp_generator::SpawnLight()
{
	//Spawn(Aaux_light_ExpLight::StaticClass());
}

void Afx_exp_generator::BeginPlay()
{
	/*
	MeshEmitter(Emitters[0]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.generator.fx_gen_exp01", Class'StaticMesh'));
	MeshEmitter(Emitters[1]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.generator.fx_gen_exp02", Class'StaticMesh'));
	MeshEmitter(Emitters[2]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.generator.fx_gen_exp03", Class'StaticMesh'));
	MeshEmitter(Emitters[3]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.generator.fx_gen_exp04", Class'StaticMesh'));
	MeshEmitter(Emitters[4]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_FX.generator.fx_gen_exp05", Class'StaticMesh'));
	*/
}
