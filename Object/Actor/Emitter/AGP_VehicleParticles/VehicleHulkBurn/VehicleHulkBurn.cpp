// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleHulkBurn/VehicleHulkBurn.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AVehicleHulkBurn::AVehicleHulkBurn()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->ProjectionNormal = FVector(0, 0, 0);
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->FadeIn = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->AutoDestroy = true;
	SpriteEmitter0->UseRevolution = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->BlendBetweenSubdivisions = true;
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter0->Opacity = 0.5;
	SpriteEmitter0->FadeOutStartTime = 7;
	SpriteEmitter0->FadeInEndTime = 0.1;
	SpriteEmitter0->MaxParticles = 90;
	SpriteEmitter0->StartLocationRange = FRangeVector({ {-50, 50}, {-50, 50}, {0, 0} });
	SpriteEmitter0->RevolutionsPerSecondRange = FRangeVector({ {0, 0}, {0, 0}, {0.01, 0.03} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {32768, 32768}, {0, 0}, {0, 0} });
	SpriteEmitter0->StartSizeRange = FRangeVector({ {100, 150}, {100, 150}, {100, 150} });
	SpriteEmitter0->InitialParticlesPerSecond = 6;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/FX2_PART_FIREANIM03_Mat.FX2_PART_FIREANIM03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 5;
	SpriteEmitter0->TextureVSubdivisions = 5;
	SpriteEmitter0->LifetimeRange = FRange({ 4, 10 });
	SpriteEmitter0->MaxAbsVelocity = FVector(0, 0, 0);
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->FadeIn = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->AutoDestroy = true;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, 50);
	SpriteEmitter1->FadeOutStartTime = 3;
	SpriteEmitter1->FadeInEndTime = 1;
	SpriteEmitter1->MaxParticles = 144;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {-100, 100}, {-100, 100}, {100, 128} });
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.025, 0.1}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,0.5});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,1});
	//SpriteEmitter1->SizeScale[2]=FParticleTimeScale({4,5});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {100, 200}, {100, 200}, {100, 200} });
	SpriteEmitter1->InitialParticlesPerSecond = 8;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_Darken;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 4, 10 });
	SpriteEmitter1->InitialDelayRange = FRange({ 0.5, 0.5 });
	//SpriteEmitter1->VelocityScale(0) = (RelativeTime = 2, RelativeVelocity = FVector(20, 20, 0));
	Emitters = { SpriteEmitter0,SpriteEmitter1 };
	AutoDestroy = true;
	//bNoDelete = false;
}