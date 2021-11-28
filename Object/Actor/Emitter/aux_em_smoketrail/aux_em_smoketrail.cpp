// All the original content belonged to the US Army

#include "aux_em_smoketrail.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aaux_em_smoketrail::Aaux_em_smoketrail()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->AutoDestroy = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, -90);
	SpriteEmitter1->FadeOutStartTime = 0.1;
	SpriteEmitter1->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	SpriteEmitter1->MaxParticles = 20;
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0.5,-2});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {7, 7}, {7, 7}, {7, 7} });
	SpriteEmitter1->InitialParticlesPerSecond = 100;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_drt_cloud01_Mat.fx_drt_cloud01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter1->InitialDelayRange = FRange({ 0.6, 0.6 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {50, 50} });
	Emitters = { nullptr,nullptr,SpriteEmitter1 };
	//bTrailerSameRotation = true;
	//Physics = PHYS_Trailer;
	//RemoteRole = ROLE_None;
	//Mass = 16;
};
