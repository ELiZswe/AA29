// All the original content belonged to the US Army

#include "JavMissileSmoke.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AJavMissileSmoke::AJavMissileSmoke()
{
	USpriteEmitter* Smoke = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	Smoke->UseColorScale = true;
	Smoke->FadeOut = true;
	Smoke->SpinParticles = true;
	Smoke->UseSizeScale = true;
	Smoke->UseRegularSizeScale = false;
	Smoke->UniformSize = true;
	//Smoke->ColorScale[0]=FParticleColorScale({0,FColor(60, 70, 70, 128)});
	//Smoke->ColorScale[1]=FParticleColorScale({0.5,FColor(60, 70, 70, 50)});
	//Smoke->ColorScale[2]=FParticleColorScale({0.75,FColor(60, 70, 70, 0)});
	//Smoke->ColorScale[3]=FParticleColorScale({1,FColor(60, 70, 70, 0)});
	Smoke->MaxParticles = 80;
	Smoke->SpinsPerSecondRange = FRangeVector({ {-0.5, 0.5}, {0, 0}, {0, 0} });
	Smoke->StartSpinRange = FRangeVector({ {-15000, 15000}, {0, 0}, {0, 0} });
	//Smoke->SizeScale[0]=FParticleTimeScale({0,0});
	//Smoke->SizeScale[1]=FParticleTimeScale({0.1,0.8});
	//Smoke->SizeScale[2]=FParticleTimeScale({1,1});
	Smoke->StartSizeRange = FRangeVector({ {240, 240}, {240, 240}, {240, 240} });
	Smoke->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	Smoke->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball04_Mat.fx_smk_ball04_Mat'"), NULL, LOAD_None, NULL);
	Smoke->SecondsBeforeInactive = 0;
	Smoke->StartVelocityRange = FRangeVector({ {15, -15}, {15, -15}, {10, 10} });
	USpriteEmitter* Fire = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	Fire->ResetAfterChange = true;
	Fire->UseSizeScale = true;
	Fire->UseRegularSizeScale = false;
	Fire->UniformSize = true;
	Fire->AutomaticInitialSpawning = false;
	Fire->MaxParticles = 5000;
	//Fire->SizeScale[0]=FParticleTimeScale({0,0});
	//Fire->SizeScale[1]=FParticleTimeScale({0.1,1});
	//Fire->SizeScale[2]=FParticleTimeScale({1,0});
	Fire->StartSizeRange = FRangeVector({ {3, 3}, {3, 3}, {3, 3} });
	Fire->InitialParticlesPerSecond = 1000;
	Fire->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_drt_cloud01_Mat.fx_drt_cloud01_Mat'"), NULL, LOAD_None, NULL);
	Fire->SecondsBeforeInactive = 0;
	Fire->LifetimeRange = FRange({ 0.1, 0.1 });
	Fire->StartVelocityRange = FRangeVector({ {-0.1, 0.1}, {-0.1, 0.1}, {-0.1, 0.1} });
	Emitters = { Fire,Smoke };
	//bNoDelete = false;
	//SoundVolume = 255;
	//SoundRadius = 128;
};