// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/aux_em_mortar/aux_em_mortar.h"
#include "AA29/Object/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aaux_em_mortar::Aaux_em_mortar()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->AutoDestroy = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->FadeOutStartTime = 1;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter1->SizeScale(0) = (RelativeTime = 1, RelativeSize = 4);
	SpriteEmitter1->InitialParticlesPerSecond = 1000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
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
	//SpriteEmitter0->StartSpinRange = X = (Min = 300, Max = -300) | Y = (Min = 0, Max = 0) | Z = (Min = 0, Max = 0);
	//SpriteEmitter0->SizeScale(0) = (RelativeTime = 0.5, RelativeSize = 2);
	SpriteEmitter0->InitialParticlesPerSecond = 2000;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter0->InitialDelayRange = FRange({ 0.2, 0.2 });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->FadeIn = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->AutoDestroy = true;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->MaxParticles = 1;
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter2->StartSpinRange = X = (Min = 3, Max = -3) | Y = (Min = 0, Max = 0) | Z = (Min = 0, Max = 0);
	//SpriteEmitter2->SizeScale(0) = (RelativeTime = 1, RelativeSize = 5);
	SpriteEmitter2->InitialParticlesPerSecond = 2000;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->FadeOut = true;
	SpriteEmitter8->SpinParticles = true;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->UniformSize = true;
	SpriteEmitter8->Acceleration = FVector(5, 0, 0);
	SpriteEmitter8->FadeOutStartTime = 5;
	SpriteEmitter8->MaxParticles = 48;
	SpriteEmitter8->SpinCCWorCW = FVector(0.25, 0.75, 0.5);
	//SpriteEmitter8->SpinsPerSecondRange = X = (Min = 0, Max = 0.05) | Y = (Min = 0, Max = 0.05) | Z = (Min = 0, Max = 0.1);
	//SpriteEmitter8->SizeScale(0) = (RelativeTime = 0, RelativeSize = 0.4);
	//SpriteEmitter8->SizeScale(1) = (RelativeTime = 5, RelativeSize = 4);
	//SpriteEmitter8->StartSizeRange = X = (Min = 50, Max = 100) | Y = (Min = 50, Max = 100) | Z = (Min = 50, Max = 100);
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_Darken;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->TextureUSubdivisions = 1;
	SpriteEmitter8->TextureVSubdivisions = 1;
	SpriteEmitter8->LifetimeRange = FRange({ 10, 10 });
	SpriteEmitter8->InitialDelayRange = FRange({ 0.75, 0.75 });
	//SpriteEmitter8->StartVelocityRange = X = (Min = -5, Max = 5) | Y = (Min = -5, Max = 5) | Z = (Min = 50, Max = 25);
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->FadeOut = true;
	SpriteEmitter5->FadeIn = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->BlendBetweenSubdivisions = true;
	//SpriteEmitter5->StartLocationRange = X = (Min = -64, Max = 64) | Y = (Min = -64, Max = 64) | Z = (Min = 0, Max = 0);
	//SpriteEmitter5->SizeScale(0) = (RelativeTime = 1, RelativeSize = 1.5);
	//SpriteEmitter5->StartSizeRange = X = (Min = -32, Max = -32) | Y = (Min = 100, Max = 100) | Z = (Min = 100, Max = 100);
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/fx_part_fireanim01_Mat.fx_part_fireanim01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->TextureUSubdivisions = 4;
	SpriteEmitter5->TextureVSubdivisions = 2;
	SpriteEmitter5->InitialDelayRange = FRange({ 0.75, 0.75 });
	//SpriteEmitter5->StartVelocityRange = X = (Min = 0, Max = 0) | Y = (Min = 0, Max = 0) | Z = (Min = 8, Max = 16);

	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter1,SpriteEmitter8,SpriteEmitter5 };
}



void Aaux_em_mortar::PostBeginPlay()
{
	SpawnLight();
}

void Aaux_em_mortar::SpawnLight()
{
	//Spawn(class'AGP_Effects.aux_light_ExpLight');
}
