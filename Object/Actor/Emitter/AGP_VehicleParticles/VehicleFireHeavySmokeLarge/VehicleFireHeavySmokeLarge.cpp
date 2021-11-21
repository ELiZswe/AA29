// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleFireHeavySmokeLarge/VehicleFireHeavySmokeLarge.h"
#include "AA29/Object/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AVehicleFireHeavySmokeLarge::AVehicleFireHeavySmokeLarge()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->AutoDestroy = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->BlendBetweenSubdivisions = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, 20);
	//SpriteEmitter0->ColorScale(0) = (RelativeTime = 0, Color = FColor(255, 255, 255, 255));
	//SpriteEmitter0->ColorScale(1) = (RelativeTime = 1, Color = FColor(255, 255, 255, 255));
	SpriteEmitter0->FadeOutStartTime = 0.4;
	SpriteEmitter0->FadeInEndTime = 0.05;
	SpriteEmitter0->MaxParticles = 2;
	//SpriteEmitter0->SpinsPerSecondRange = X = (Min = 0, Max = 0.05) | Y = (Min = 0, Max = 0) | Z = (Min = 0, Max = 0);
	//SpriteEmitter0->SizeScale(0) = (RelativeTime = 1, RelativeSize = 3);
	//SpriteEmitter0->StartSizeRange = X = (Min = 75, Max = 75) | Y = (Min = 75, Max = 75) | Z = (Min = 75, Max = 75);
	SpriteEmitter0->InitialParticlesPerSecond = 4;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_explosion01_Mat.fx_part_explosion01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 4;
	SpriteEmitter0->TextureVSubdivisions = 2;
	SpriteEmitter0->LifetimeRange = FRange({ 0.5, 0.5 });
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
	SpriteEmitter1->Acceleration = FVector(0, 0, 60);
	SpriteEmitter1->FadeOutStartTime = 3;
	SpriteEmitter1->FadeInEndTime = 0.5;
	SpriteEmitter1->MaxParticles = 50;
	//SpriteEmitter1->StartLocationRange = X = (Min = 0, Max = 0) | Y = (Min = 0, Max = 0) | Z = (Min = 10, Max = 20);
	SpriteEmitter1->SpinCCWorCW = FVector(0.25, 0.25, 0.25);
	//SpriteEmitter1->SpinsPerSecondRange = X = (Min = 0.05, Max = 0.1) | Y = (Min = 0, Max = 0) | Z = (Min = 0, Max = 0);
	//SpriteEmitter1->SizeScale(0) = (RelativeTime = 0, RelativeSize = 1);
	//SpriteEmitter1->SizeScale(1) = (RelativeTime = 8, RelativeSize = 20);
	//SpriteEmitter1->StartSizeRange = X = (Min = 15, Max = 30) | Y = (Min = 15, Max = 30) | Z = (Min = 15, Max = 30);
	SpriteEmitter1->InitialParticlesPerSecond = 5;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_Darken;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_dk_Mat.fx_smk_ball01_dk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 3.5, 4 });
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
	SpriteEmitter2->Acceleration = FVector(0, 0, 100);
	SpriteEmitter2->Opacity = 0.35;
	SpriteEmitter2->FadeOutStartTime = 1;
	SpriteEmitter2->FadeInEndTime = 0.1;
	SpriteEmitter2->MaxParticles = 50;
	SpriteEmitter2->AutoResetTimeRange = FRange({ 10, 10 });
	//SpriteEmitter2->StartLocationRange = X = (Min = -8, Max = 8) | Y = (Min = -8, Max = 8) | Z = (Min = -5, Max = 5);
	//SpriteEmitter2->StartLocationPolarRange = X = (Min = -25, Max = 25) | Y = (Min = -25, Max = 25) | Z = (Min = -25, Max = 25);
	//SpriteEmitter2->SpinsPerSecondRange = X = (Min = -0.2, Max = 0.2) | Y = (Min = -0.2, Max = 0.2) | Z = (Min = -0.2, Max = 0.2);
	//SpriteEmitter2->SizeScale(0) = (RelativeTime = 0, RelativeSize = 1);
	//SpriteEmitter2->SizeScale(1) = (RelativeTime = 2, RelativeSize = 0.1);
	//SpriteEmitter2->StartSizeRange = X = (Min = 40, Max = 60) | Y = (Min = 40, Max = 60) | Z = (Min = 40, Max = 60);
	SpriteEmitter2->InitialParticlesPerSecond = 5;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/FX2_misc_explosionA_Mat.FX2_misc_explosionA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->TextureUSubdivisions = 1;
	SpriteEmitter2->TextureVSubdivisions = 1;
	SpriteEmitter2->LifetimeRange = FRange({ 1.5, 2.5 });
	SpriteEmitter2->InitialDelayRange = FRange({ 0.5, 0.5 });
	SpriteEmitter2->MaxAbsVelocity = FVector(75, 75, 1000);
	//SpriteEmitter2->VelocityLossRange = X = (Min = -5, Max = 5) | Y = (Min = -5, Max = 5) | Z = (Min = 0, Max = 0);
	SpriteEmitter2->RotateVelocityLossRange = true;
	//SpriteEmitter2->AddVelocityMultiplierRange = X = (Min = 1, Max = 1) | Y = (Min = 1, Max = 1) | Z = (Min = 0, Max = 0);
	//SpriteEmitter2->VelocityScale(0) = (RelativeTime = 1, RelativeVelocity = FVector(1, -1, 0));
	//SpriteEmitter2->VelocityScale(1) = (RelativeTime = 1, RelativeVelocity = FVector(-1, 1, 0));
	//Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2 };
	AutoDestroy = true;
	//bNoDelete = false;

}