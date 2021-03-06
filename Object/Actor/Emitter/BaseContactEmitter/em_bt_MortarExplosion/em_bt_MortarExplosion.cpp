// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_MortarExplosion/em_bt_MortarExplosion.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/Actor/Emitter/aux_light_ExpLight/aux_light_ExpLight.h"

Aem_bt_MortarExplosion::Aem_bt_MortarExplosion()
{
	USpriteEmitter* SpriteEmitter6 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter6->FadeOut = true;
	SpriteEmitter6->FadeIn = true;
	SpriteEmitter6->RespawnDeadParticles = false;
	SpriteEmitter6->DisableFogging = true;
	SpriteEmitter6->SpinParticles = true;
	SpriteEmitter6->UseSizeScale = true;
	SpriteEmitter6->UseRegularSizeScale = false;
	SpriteEmitter6->UniformSize = true;
	//SpriteEmitter6->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter6->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter6->Opacity = 0.7;
	SpriteEmitter6->MaxParticles = 1;
	SpriteEmitter6->DetailMode = EDetailMode::DM_Medium;
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter6->StartSpinRange = FRangeVector({ {-3, 3}, {0, 0}, {0, 0} });
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({1,5});
	SpriteEmitter6->StartSizeRange = FRangeVector({ {50, 50}, {50, 50}, {100, 100} });
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->SecondsBeforeInactive = 0;
	SpriteEmitter6->LifetimeRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->UseColorScale = true;
	SpriteEmitter7->FadeOut = true;
	SpriteEmitter7->FadeIn = true;
	SpriteEmitter7->RespawnDeadParticles = false;
	SpriteEmitter7->SpinParticles = true;
	SpriteEmitter7->UseSizeScale = true;
	SpriteEmitter7->UseRegularSizeScale = false;
	SpriteEmitter7->UniformSize = true;
	SpriteEmitter7->AutomaticInitialSpawning = false;
	SpriteEmitter7->Acceleration = FVector(0, 0, -10);
	//SpriteEmitter7->ColorScale[0]=FParticleColorScale({0,FColor(157, 189, 219, 255)});
	//SpriteEmitter7->ColorScale[1]=FParticleColorScale({1,FColor(207, 220, 231, 255)});
	SpriteEmitter7->Opacity = 0.25;
	SpriteEmitter7->FadeOutStartTime = 3;
	SpriteEmitter7->FadeInEndTime = 0.5;
	SpriteEmitter7->MaxParticles = 15;
	SpriteEmitter7->StartLocationRange = FRangeVector({ {-50, 50}, {-50, 50}, {0, 0} });
	SpriteEmitter7->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter7->SpinsPerSecondRange = FRangeVector({ {-0.15, 0.15}, {-0.15, 0.15}, {-0.15, 0.15} });
	SpriteEmitter7->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter7->SizeScale[0]=FParticleTimeScale({1,3.5});
	SpriteEmitter7->StartSizeRange = FRangeVector({ {50, 100}, {50, 100}, {50, 100} });
	SpriteEmitter7->InitialParticlesPerSecond = 1000;
	SpriteEmitter7->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->LifetimeRange = FRange({ 9, 10 });
	SpriteEmitter7->StartVelocityRange = FRangeVector({ {-50, 50}, {-50, 50}, {25, 50} });
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->FadeOut = true;
	SpriteEmitter8->RespawnDeadParticles = false;
	SpriteEmitter8->SpinParticles = true;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->UniformSize = true;
	SpriteEmitter8->AutomaticInitialSpawning = false;
	SpriteEmitter8->Acceleration = FVector(0, 0, -1000);
	//SpriteEmitter8->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter8->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter8->Opacity = 0.75;
	SpriteEmitter8->FadeOutStartTime = 0.5;
	SpriteEmitter8->MaxParticles = 16;
	SpriteEmitter8->StartLocationRange = FRangeVector({ {-25, 25}, {-25, 25}, {0, 0} });
	SpriteEmitter8->SpinsPerSecondRange = FRangeVector({ {0.06, 0.06}, {0, 0}, {0, 0} });
	SpriteEmitter8->StartSpinRange = FRangeVector({ {-0.5, 0.5}, {0, 0}, {0, 0} });
	//SpriteEmitter8->SizeScale[0]=FParticleTimeScale({1,1.5});
	SpriteEmitter8->StartSizeRange = FRangeVector({ {75, 100}, {75, 100}, {75, 100} });
	SpriteEmitter8->InitialParticlesPerSecond = 20;
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/FX2_Parts_Dirtclumps_Large_Mat.FX2_Parts_Dirtclumps_Large_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->StartVelocityRange = FRangeVector({ {-50, 50}, {-50, 50}, {500, 1000} });
	SpriteEmitter8->WarmupTicksPerSecond = 5000;
	SpriteEmitter8->RelativeWarmupTime = 0.05;

	Emitters = { SpriteEmitter6,SpriteEmitter7,SpriteEmitter8 };
}

void Aem_bt_MortarExplosion::PostBeginPlay()
{
	SpawnLight();
}

void Aem_bt_MortarExplosion::SpawnLight()
{
	//Spawn(Aaux_light_ExpLight::StaticClass());
}
