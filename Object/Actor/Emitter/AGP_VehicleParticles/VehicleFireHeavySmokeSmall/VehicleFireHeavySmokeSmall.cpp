// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleFireHeavySmokeSmall/VehicleFireHeavySmokeSmall.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AVehicleFireHeavySmokeSmall::AVehicleFireHeavySmokeSmall()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->AutoDestroy = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->BlendBetweenSubdivisions = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, 20);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter0->FadeOutStartTime = 0.4;
	SpriteEmitter0->FadeInEndTime = 0.05;
	SpriteEmitter0->MaxParticles = 1;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0, 0.05}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({1,2});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {50, 50}, {50, 50}, {50, 50} });
	SpriteEmitter0->InitialParticlesPerSecond = 4;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_explosion01_Mat.fx_part_explosion01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 4;
	SpriteEmitter0->TextureVSubdivisions = 2;
	SpriteEmitter0->LifetimeRange = FRange({ 0.25, 0.25 });
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
	SpriteEmitter1->AddVelocityFromOwner = true;
	SpriteEmitter1->Acceleration = FVector(0, 0, 20);
	SpriteEmitter1->FadeOutStartTime = 3;
	SpriteEmitter1->FadeInEndTime = 0.5;
	SpriteEmitter1->MaxParticles = 60;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {-5, 5} });
	SpriteEmitter1->SpinCCWorCW = FVector(0.25, 0.25, 0.25);
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.05, 0.1}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({8,20});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {25, 25}, {25, 25}, {25, 25} });
	SpriteEmitter1->InitialParticlesPerSecond = 5;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_Darken;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 3.5, 5 });
	SpriteEmitter1->InitialDelayRange = FRange({ 1, 1 });
	SpriteEmitter1->MaxAbsVelocity = FVector(60, 60, 1000);
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->ProjectionNormal = FVector(32768, 0, 1);
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->FadeIn = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->AutoDestroy = true;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->UseVelocityScale = true;
	SpriteEmitter2->AddVelocityFromOwner = true;
	SpriteEmitter2->Acceleration = FVector(0, 0, 50);
	SpriteEmitter2->Opacity = 0.35;
	SpriteEmitter2->FadeOutStartTime = 1;
	SpriteEmitter2->FadeInEndTime = 0.1;
	SpriteEmitter2->MaxParticles = 50;
	SpriteEmitter2->AutoResetTimeRange = FRange({ 10, 10 });
	SpriteEmitter2->StartLocationRange = FRangeVector({ {-8, 8}, {-8, 8}, {-5, 5} });
	SpriteEmitter2->StartLocationPolarRange = FRangeVector({ {-25, 25}, {-25, 25}, {-25, 25} });
	SpriteEmitter2->SpinsPerSecondRange = FRangeVector({ {-0.2, 0.2}, {-0.2, 0.2}, {-0.2, 0.2} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({2,0.1});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {25, 35}, {25, 35}, {25, 35} });
	SpriteEmitter2->InitialParticlesPerSecond = 5;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/FX2_misc_explosionA_Mat.FX2_misc_explosionA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->TextureUSubdivisions = 1;
	SpriteEmitter2->TextureVSubdivisions = 1;
	SpriteEmitter2->LifetimeRange = FRange({ 1.5, 2.5 });
	SpriteEmitter2->InitialDelayRange = FRange({ 0.2, 0.2 });
	SpriteEmitter2->MaxAbsVelocity = FVector(75, 75, 1000);
	SpriteEmitter2->VelocityLossRange = FRangeVector({ {-5, 5}, {-5, 5}, {0, 0} });
	SpriteEmitter2->RotateVelocityLossRange = true;
	SpriteEmitter2->AddVelocityMultiplierRange = FRangeVector({ {1, 1}, {1, 1}, {0, 0} });
	//SpriteEmitter2->VelocityScale(0) = (RelativeTime = 1, RelativeVelocity = FVector(1, -1, 0));
	//SpriteEmitter2->VelocityScale(1) = (RelativeTime = 1, RelativeVelocity = FVector(-1, 1, 0));
	SpriteEmitter2->WarmupTicksPerSecond = 1;
	SpriteEmitter2->RelativeWarmupTime = 0.35;
	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2 };
	AutoDestroy = true;
	//bNoDelete = false;
}
