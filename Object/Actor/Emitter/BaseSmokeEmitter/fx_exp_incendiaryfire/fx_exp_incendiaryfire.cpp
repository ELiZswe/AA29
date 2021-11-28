// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/fx_exp_incendiaryfire/fx_exp_incendiaryfire.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Afx_exp_incendiaryfire::Afx_exp_incendiaryfire()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->FadeIn = true;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(150, 170, 190, 255)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.7,FColor(0, 0, 0, 255)});
	//SpriteEmitter1->ColorScale[2]=FParticleColorScale({1,FColor(0, 0, 0, 255)});
	SpriteEmitter1->FadeOutStartTime = 3;
	SpriteEmitter1->FadeInEndTime = 1;
	SpriteEmitter1->MaxParticles = 6;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {22, 33} });
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.04, 0.05}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,4});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {50, 55}, {100, 100}, {100, 100} });
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {55, 55} });
	SpriteEmitter1->WarmupTicksPerSecond = 1;
	SpriteEmitter1->RelativeWarmupTime = 1;
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->FadeIn = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->BlendBetweenSubdivisions = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, -55);
	SpriteEmitter0->FadeOutStartTime = 0.4;
	SpriteEmitter0->FadeInEndTime = 0.1;
	SpriteEmitter0->MaxParticles = 4;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.1, 0.1}, {0, 0}, {0, 0} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({1,1.4});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {40, 44}, {100, 100}, {100, 100} });
	SpriteEmitter0->ParticlesPerSecond = 3.5;
	SpriteEmitter0->InitialParticlesPerSecond = 3.5;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_explosion01_Mat.fx_part_explosion01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 4;
	SpriteEmitter0->TextureVSubdivisions = 2;
	SpriteEmitter0->LifetimeRange = FRange({ 0.7, 0.7 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {133, 133} });
	SpriteEmitter0->WarmupTicksPerSecond = 1;
	SpriteEmitter0->RelativeWarmupTime = 1;
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(81, 124, 255, 255)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({1,FColor(21, 121, 255, 255)});
	SpriteEmitter2->MaxParticles = 4;
	SpriteEmitter2->StartLocationRange = FRangeVector({ {-9, 9}, {-9, 9}, {-15, -15} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,0.2});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {33, 37}, {100, 100}, {100, 100} });
	SpriteEmitter2->ParticlesPerSecond = 5;
	SpriteEmitter2->InitialParticlesPerSecond = 5;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball04_Mat.fx_smk_ball04_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 1, 1 });
	SpriteEmitter2->WarmupTicksPerSecond = 1;
	SpriteEmitter2->RelativeWarmupTime = 1;
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseCollision = true;
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->Acceleration = FVector(0, 0, -888);
	SpriteEmitter3->DampingFactorRange = FRangeVector({ {1, 1}, {1, 1}, {0.1, 0.5} });
	SpriteEmitter3->MaxCollisions = FRange({ 1, 1 });
	SpriteEmitter3->bOnlyBSPCollision = true;
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(210, 228, 255, 0)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(140, 209, 255, 0)});
	SpriteEmitter3->FadeOutStartTime = 0.7;
	SpriteEmitter3->MaxParticles = 17;
	SpriteEmitter3->StartSizeRange = FRangeVector({ {4, 8}, {100, 100}, {100, 100} });
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 1, 1 });
	SpriteEmitter3->StartVelocityRange = FRangeVector({ {-155, 155}, {-155, 155}, {222, 333} });
	Duration = FRange({ 21, 21 });
	Emitters = { SpriteEmitter1,SpriteEmitter0,SpriteEmitter2,SpriteEmitter3 };
}

void Afx_exp_incendiaryfire::BeginPlay()
{
	//Spawn(class'AGP_Effects.fx_exp_incendiary');
}
