// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleLightSmoke/VehicleLightSmoke.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AVehicleLightSmoke::AVehicleLightSmoke()
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
	SpriteEmitter0->AddVelocityFromOwner = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, 50);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter0->Opacity = 0.5;
	SpriteEmitter0->FadeOutStartTime = 0.75;
	SpriteEmitter0->FadeInEndTime = 0.5;
	SpriteEmitter0->MaxParticles = 50;
	SpriteEmitter0->StartLocationRange = FRangeVector({ {-10, 10}, {-10, 10}, {0, 0} });
	SpriteEmitter0->SpinCCWorCW = FVector(0.25, 0.25, 0.25);
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.05, 0.1}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({1,5});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {15, 25}, {15, 25}, {15, 25} });
	SpriteEmitter0->InitialParticlesPerSecond = 5;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Darken;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->LifetimeRange = FRange({ 3, 4 });
	SpriteEmitter0->InitialDelayRange = FRange({ 0.2, 0.2 });
	SpriteEmitter0->MaxAbsVelocity = FVector(60, 60, 1000);
	Emitters = { SpriteEmitter0 };
	AutoDestroy = true;
	//bNoDelete = false;
}