// All the original content belonged to the US Army

#include "m2a2muzzlesmoke.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Am2a2muzzlesmoke::Am2a2muzzlesmoke()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->FadeIn = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->Acceleration = FVector(0, 8, 6);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(200, 200, 200, 155)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({3,FColor(226, 226, 226, 255)});
	SpriteEmitter0->Opacity = 0.35;
	SpriteEmitter0->FadeOutStartTime = 0.5;
	SpriteEmitter0->FadeInEndTime = 0.25;
	SpriteEmitter0->MaxParticles = 6;
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0.05}, {0, 0.1} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({1,4});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {20, 25}, {100, 100}, {100, 100} });
	SpriteEmitter0->InitialParticlesPerSecond = 1000;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->LifetimeRange = FRange({ 1, 1.5 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-60, 60}, {25, 50}, {-60, 60} });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->FadeIn = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 8, 5);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(210, 210, 210, 155)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({3,FColor(226, 226, 226, 255)});
	SpriteEmitter1->Opacity = 0.5;
	SpriteEmitter1->FadeOutStartTime = 0.5;
	SpriteEmitter1->FadeInEndTime = 0.25;
	SpriteEmitter1->MaxParticles = 3;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0.05}, {0, 0.1} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,5});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {15, 17}, {100, 100}, {100, 100} });
	SpriteEmitter1->InitialParticlesPerSecond = 1000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 1, 1.25 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {-40, 40}, {70, 80}, {-40, 40} });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->FadeIn = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->Acceleration = FVector(0, 8, 5);
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(210, 210, 210, 155)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({3,FColor(226, 226, 226, 255)});
	SpriteEmitter2->Opacity = 0.5;
	SpriteEmitter2->FadeOutStartTime = 0.5;
	SpriteEmitter2->FadeInEndTime = 0.25;
	SpriteEmitter2->MaxParticles = 1;
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter2->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0.05}, {0, 0.1} });
	SpriteEmitter2->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,8});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {10, 12}, {100, 100}, {100, 100} });
	SpriteEmitter2->InitialParticlesPerSecond = 1000;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 1.25, 1.5 });
	SpriteEmitter2->StartVelocityRange = FRangeVector({ {0, 0}, {120, 150}, {0, 0} });
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->FadeIn = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->Acceleration = FVector(0, 8, 5);
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(210, 210, 210, 155)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({3,FColor(226, 226, 226, 255)});
	SpriteEmitter3->Opacity = 0.5;
	SpriteEmitter3->FadeOutStartTime = 0.5;
	SpriteEmitter3->FadeInEndTime = 0.25;
	SpriteEmitter3->MaxParticles = 4;
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter3->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0.05}, {0, 0.1} });
	SpriteEmitter3->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({1,4});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {18, 20}, {100, 100}, {100, 100} });
	SpriteEmitter3->InitialParticlesPerSecond = 1000;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 1.2, 1.8 });
	SpriteEmitter3->StartVelocityRange = FRangeVector({ {-60, 60}, {-40, -60}, {-40, 40} });
	USpriteEmitter* SpriteEmitter4 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter4->UseColorScale = true;
	SpriteEmitter4->FadeOut = true;
	SpriteEmitter4->FadeIn = true;
	SpriteEmitter4->RespawnDeadParticles = false;
	SpriteEmitter4->SpinParticles = true;
	SpriteEmitter4->UseSizeScale = true;
	SpriteEmitter4->UseRegularSizeScale = false;
	SpriteEmitter4->UniformSize = true;
	SpriteEmitter4->AutomaticInitialSpawning = false;
	SpriteEmitter4->Acceleration = FVector(0, 8, 6);
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(200, 200, 200, 155)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({3,FColor(226, 226, 226, 255)});
	SpriteEmitter4->Opacity = 0.35;
	SpriteEmitter4->FadeOutStartTime = 0.7;
	SpriteEmitter4->FadeInEndTime = 0.25;
	SpriteEmitter4->MaxParticles = 1;
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter4->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0.05}, {0, 0.1} });
	SpriteEmitter4->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter4->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter4->StartSizeRange = FRangeVector({ {20, 25}, {100, 100}, {100, 100} });
	SpriteEmitter4->InitialParticlesPerSecond = 1000;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 1.25, 1.5 });
	SpriteEmitter4->StartVelocityRange = FRangeVector({ {110, 110}, {0, 0}, {0, 0} });
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->UseColorScale = true;
	SpriteEmitter5->FadeOut = true;
	SpriteEmitter5->FadeIn = true;
	SpriteEmitter5->RespawnDeadParticles = false;
	SpriteEmitter5->SpinParticles = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->AutomaticInitialSpawning = false;
	SpriteEmitter5->Acceleration = FVector(0, 8, 6);
	//SpriteEmitter5->ColorScale[0]=FParticleColorScale({0,FColor(200, 200, 200, 155)});
	//SpriteEmitter5->ColorScale[1]=FParticleColorScale({3,FColor(226, 226, 226, 255)});
	SpriteEmitter5->Opacity = 0.35;
	SpriteEmitter5->FadeOutStartTime = 0.7;
	SpriteEmitter5->FadeInEndTime = 0.25;
	SpriteEmitter5->MaxParticles = 1;
	SpriteEmitter5->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter5->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0.05}, {0, 0.1} });
	SpriteEmitter5->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter5->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter5->StartSizeRange = FRangeVector({ {20, 25}, {100, 100}, {100, 100} });
	SpriteEmitter5->InitialParticlesPerSecond = 1000;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->LifetimeRange = FRange({ 1.25, 1.5 });
	SpriteEmitter5->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {110, 110} });
	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4,SpriteEmitter5 };
	//bNoDelete = false;
};