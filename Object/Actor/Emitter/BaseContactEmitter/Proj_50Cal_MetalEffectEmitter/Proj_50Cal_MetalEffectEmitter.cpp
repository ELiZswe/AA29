// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/Proj_50Cal_MetalEffectEmitter/Proj_50Cal_MetalEffectEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AProj_50Cal_MetalEffectEmitter::AProj_50Cal_MetalEffectEmitter()
{
	USpriteEmitter* SpriteEmitter13 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter13->UseCollision = true;
	SpriteEmitter13->UseMaxCollisions = true;
	SpriteEmitter13->UseColorScale = true;
	SpriteEmitter13->FadeOut = true;
	SpriteEmitter13->RespawnDeadParticles = false;
	SpriteEmitter13->UseSizeScale = true;
	SpriteEmitter13->UseRegularSizeScale = false;
	SpriteEmitter13->UniformSize = true;
	SpriteEmitter13->AutomaticInitialSpawning = false;
	SpriteEmitter13->Acceleration = FVector(0, 0, -1500);
	SpriteEmitter13->DampingFactorRange = FRangeVector({ {0.3, 0.3}, {0.3, 0.3}, {0.3, 0.3} });
	SpriteEmitter13->MaxCollisions = FRange({ 1, 3 });
	//SpriteEmitter13->ColorScale[0]=FParticleColorScale({0,FColor(140, 194, 255, 0)});
	//SpriteEmitter13->ColorScale[1]=FParticleColorScale({1,FColor(38, 57, 89, 0)});
	SpriteEmitter13->FadeOutStartTime = 0.5;
	SpriteEmitter13->MaxParticles = 12;
	SpriteEmitter13->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter13->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter13->SizeScale[1]=FParticleTimeScale({1,0.8});
	SpriteEmitter13->StartSizeRange = FRangeVector({ {3, 5}, {100, 100}, {100, 100} });
	SpriteEmitter13->InitialParticlesPerSecond = 1111;
	SpriteEmitter13->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter13->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter13->LifetimeRange = FRange({ 1, 1.5 });
	SpriteEmitter13->StartVelocityRange = FRangeVector({ {-200, -800}, {-50, 50}, {-50, 50} });
	SpriteEmitter13->VelocityLossRange = FRangeVector({ {1, 1}, {1, 1}, {1, 1} });
	Emitters = { SpriteEmitter13 };
}