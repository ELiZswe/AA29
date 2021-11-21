// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_custom_fireext/em_bt_custom_fireext.h"
#include "AA29/Object/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_bt_custom_fireext::Aem_bt_custom_fireext()
{
	USpriteEmitter* SpriteEmitter52 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter52->FadeOut = true;
	SpriteEmitter52->RespawnDeadParticles = false;
	SpriteEmitter52->SpinParticles = true;
	SpriteEmitter52->UseSizeScale = true;
	SpriteEmitter52->UseRegularSizeScale = false;
	SpriteEmitter52->UniformSize = true;
	SpriteEmitter52->AutomaticInitialSpawning = false;
	SpriteEmitter52->CoordinateSystem = EParticleCoordinateSystem::PTCS_Absolute;
	SpriteEmitter52->MaxParticles = 15;
	//SpriteEmitter52->StartSpinRange=X=(Min=300, Max=-300)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter52->SizeScale[0]=FParticleTimeScale({1,20});
	//SpriteEmitter52->StartSizeRange=X=(Min=5, Max=5)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter52->InitialParticlesPerSecond = 15;
	SpriteEmitter52->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter52->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter52->SecondsBeforeInactive = 0;
	SpriteEmitter52->LifetimeRange = FRange({ 2, 2 });
	//SpriteEmitter52->StartVelocityRange=X=(Min=0, Max=0)|Y=(Min=200, Max=200)|Z=(Min=0, Max=0);
	SpriteEmitter52->GetVelocityDirectionFrom = EParticleVelocityDirection::PTVD_StartPositionAndOwner;
	Emitters = { SpriteEmitter52 };
}

void Aem_bt_custom_fireext::InitEmitters(FVector HitLocation, FVector HitNormal)
{
	//(Emitters[0].StartLocationOffset += (HitLocation + (0.1 * HitNormal)));
}