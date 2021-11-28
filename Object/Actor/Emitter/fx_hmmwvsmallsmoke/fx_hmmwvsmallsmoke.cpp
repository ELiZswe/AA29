// All the original content belonged to the US Army

#include "fx_hmmwvsmallsmoke.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Afx_hmmwvsmallsmoke::Afx_hmmwvsmallsmoke()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->FadeIn = true;
	SpriteEmitter1->Disabled = true;
	SpriteEmitter1->Backup_Disabled = true;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->DampRotation = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->UseVelocityScale = true;
	SpriteEmitter1->Acceleration = FVector(1, 0, -0.5);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0.03,FColor(16, 16, 16, 100)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.07,FColor(32, 47, 32, 65)});
	//SpriteEmitter1->ColorScale[2]=FParticleColorScale({0.1,FColor(64, 64, 64, 35)});
	//SpriteEmitter1->ColorScale[3]=FParticleColorScale({0.25,FColor(82, 86, 95, 15)});
	//SpriteEmitter1->ColorScale[4]=FParticleColorScale({0.33,FColor(0, 0, 0, 5)});
	//SpriteEmitter1->ColorScale[5]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter1->FadeOutStartTime = 10;
	SpriteEmitter1->FadeInEndTime = 1.15;
	SpriteEmitter1->MaxParticles = 32;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {-4, 4}, {-4, 4}, {-4, -3} });
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	SpriteEmitter1->RotationDampingFactorRange = FRangeVector({ {0.1, 0.1}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1.5});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({0.5,10});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {10, 12}, {100, 100}, {100, 100} });
	SpriteEmitter1->ParticlesPerSecond = 2;
	SpriteEmitter1->InitialParticlesPerSecond = 1;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/FX2_SMK_Ball02A_Mat.FX2_SMK_Ball02A_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 25, 30 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {25, 30} });
	SpriteEmitter1->WarmupTicksPerSecond = 1;
	SpriteEmitter1->RelativeWarmupTime = 1;
	Emitters = { SpriteEmitter1 };
	//bNoDelete = false;
};