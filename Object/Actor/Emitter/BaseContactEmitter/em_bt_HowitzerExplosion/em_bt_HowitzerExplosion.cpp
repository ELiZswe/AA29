// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_HowitzerExplosion/em_bt_HowitzerExplosion.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_bt_HowitzerExplosion::Aem_bt_HowitzerExplosion()
{
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->FadeIn = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->DisableFogging = true;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter3->Opacity = 0.4;
	//SpriteEmitter3->DetailMode = 1;
	//SpriteEmitter3->StartLocationRange=X=(Min=-100, Max=100)|Y=(Min=-100, Max=100)|Z=(Min=0, Max=50);
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter3->StartSpinRange=X=(Min=-3, Max=3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({1,2});
	//SpriteEmitter3->StartSizeRange=X=(Min=10, Max=150)|Y=(Min=50, Max=150)|Z=(Min=50, Max=150);
	SpriteEmitter3->InitialParticlesPerSecond = 60;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 0.1, 0.1 });
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
	SpriteEmitter4->UseVelocityScale = true;
	SpriteEmitter4->AddVelocityFromOwner = true;
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({0.25,FColor(0, 0, 0, 255)});
	//SpriteEmitter4->ColorScale[2]=FParticleColorScale({5,FColor(0, 0, 0, 0)});
	SpriteEmitter4->Opacity = 0.5;
	SpriteEmitter4->FadeOutStartTime = 10;
	SpriteEmitter4->FadeInEndTime = 1;
	SpriteEmitter4->MaxParticles = 20;
	//SpriteEmitter4->StartLocationRange=X=(Min=-200, Max=200)|Y=(Min=-200, Max=200)|Z=(Min=0, Max=200);
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter4->SpinsPerSecondRange=X=(Min=-0.05, Max=-0.1)|Y=(Min=-0.15, Max=0.15)|Z=(Min=-0.15, Max=0.15);
	//SpriteEmitter4->StartSpinRange=X=(Min=0, Max=1)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({1,2});
	//SpriteEmitter4->StartSizeRange=X=(Min=200, Max=250)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter4->InitialParticlesPerSecond = 1000;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 12, 15 });
	//SpriteEmitter4->StartVelocityRange=X=(Min=-75, Max=75)|Y=(Min=-75, Max=75)|Z=(Min=0, Max=200);
	SpriteEmitter4->VelocityScale = { FParticleVelocityScale({ 1, FVector(0, 0, -0.5) }) };
	Emitters = { SpriteEmitter3,SpriteEmitter4 };
}

void Aem_bt_HowitzerExplosion::PostBeginPlay()
{
	SpawnLight();
}

void Aem_bt_HowitzerExplosion::SpawnLight()
{
	//Spawn(class'AGP_Effects.aux_light_ExpLight');
}