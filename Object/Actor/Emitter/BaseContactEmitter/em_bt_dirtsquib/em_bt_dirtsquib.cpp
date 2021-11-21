// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_dirtsquib/em_bt_dirtsquib.h"
#include "AA29/Object/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_bt_dirtsquib::Aem_bt_dirtsquib()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->AutoReset = true;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->Acceleration = FVector(0, 0, -40);
	SpriteEmitter0->MaxParticles = 1;
	SpriteEmitter0->AutoResetTimeRange = (Min = 1, Max = 1);
	SpriteEmitter0->StartLocationOffset = FVector(0, 0, 10);
	//SpriteEmitter0->StartSizeRange=X=(Min=-50, Max=-50)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter0->ParticlesPerSecond = 1;
	SpriteEmitter0->InitialParticlesPerSecond = 20;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_drt_shot_Mat.fx_drt_shot_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.37, 0.37 });
	//SpriteEmitter0->StartVelocityRange=X=(Min=0, Max=0)|Y=(Min=0, Max=0)|Z=(Min=250, Max=250);
	//SpriteEmitter0->VelocityLossRange=X=(Min=0, Max=0)|Y=(Min=0, Max=0)|Z=(Min=10, Max=10);
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->AutoReset = true;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, -40);
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->AutoResetTimeRange = (Min = 1, Max = 1);
	SpriteEmitter1->StartLocationOffset = FVector(0, 0, 13);
	//SpriteEmitter1->StartSizeRange=X=(Min=-50, Max=-50)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter1->ParticlesPerSecond = 1;
	SpriteEmitter1->InitialParticlesPerSecond = 20;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_drt_shot_Mat.fx_drt_shot_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.37, 0.37 });
	//SpriteEmitter1->StartVelocityRange=X=(Min=0, Max=0)|Y=(Min=0, Max=0)|Z=(Min=200, Max=200);
	//SpriteEmitter1->VelocityLossRange=X=(Min=0, Max=0)|Y=(Min=0, Max=0)|Z=(Min=10, Max=10);
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->FadeIn = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->AutoDestroy = true;
	SpriteEmitter2->AutoReset = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->MaxParticles = 1;
	SpriteEmitter2->AutoResetTimeRange = (Min = 1, Max = 1);
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0.25,2});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({-0.7,0});
	//SpriteEmitter2->StartSizeRange=X=(Min=20, Max=10)|Y=(Min=20, Max=10)|Z=(Min=20, Max=20);
	SpriteEmitter2->InitialParticlesPerSecond = 100;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_drt_cloud01_Mat.fx_drt_cloud01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 0.7, 0.7 });
	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2 };

}