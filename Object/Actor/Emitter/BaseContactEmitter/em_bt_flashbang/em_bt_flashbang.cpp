// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_flashbang/em_bt_flashbang.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SparkEmitter/SparkEmitter.h"

Aem_bt_flashbang::Aem_bt_flashbang()
{
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
	SpriteEmitter0->Acceleration = FVector(0, 0, 50);
	SpriteEmitter0->FadeOutStartTime = 0.1;
	SpriteEmitter0->MaxParticles = 3;
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter0->StartSpinRange=X=(Min=300, Max=-300)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0.5,1.3});
	SpriteEmitter0->InitialParticlesPerSecond = 20;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.2, 0.2 });
	SpriteEmitter0->InitialDelayRange = FRange({ 0.2, 0.2 });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->AutoDestroy = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->FadeOutStartTime = 0.3;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({1,4});
	SpriteEmitter1->InitialParticlesPerSecond = 100;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 1, 1 });
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->AutoDestroy = true;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->BlendBetweenSubdivisions = true;
	SpriteEmitter3->MaxParticles = 1;
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter3->StartSpinRange=X=(Min=30, Max=-30)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter3->InitialParticlesPerSecond = 100;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_flash01_Mat.fx_part_flash01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->TextureUSubdivisions = 2;
	SpriteEmitter3->TextureVSubdivisions = 2;
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 0.1, 0.1 });
	USparkEmitter* SparkEmitter0 = NewObject<USparkEmitter>(USparkEmitter::StaticClass());
	SparkEmitter0->TimeBetweenSegmentsRange = FRange({ 0.01, 0.01 });
	SparkEmitter0->RespawnDeadParticles = false;
	SparkEmitter0->AutoDestroy = true;
	SparkEmitter0->AutomaticInitialSpawning = false;
	SparkEmitter0->MaxParticles = 45;
	SparkEmitter0->InitialParticlesPerSecond = 10000;
	SparkEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_threads_Mat.fx_part_threads_Mat'"), NULL, LOAD_None, NULL);
	SparkEmitter0->SecondsBeforeInactive = 0;
	SparkEmitter0->LifetimeRange = FRange({ 0.125, 0.15 });
	//SparkEmitter0->StartVelocityRange=X=(Min=1000, Max=-1000)|Y=(Min=1000, Max=-1000)|Z=(Min=1000, Max=-1000);
	Emitters = { nullptr,SpriteEmitter0,SpriteEmitter1,SpriteEmitter3,SparkEmitter0 };
	LifeSpan = 10;
}


void Aem_bt_flashbang::PostBeginPlay()
{
	SpawnLight();
}

void Aem_bt_flashbang::SpawnLight()
{
	//Spawn(class'AGP_Effects.aux_light_ExpLight');
}