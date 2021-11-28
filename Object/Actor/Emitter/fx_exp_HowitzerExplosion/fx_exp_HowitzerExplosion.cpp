// All the original content belonged to the US Army

#include "fx_exp_HowitzerExplosion.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Afx_exp_HowitzerExplosion::Afx_exp_HowitzerExplosion()
{
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->FadeIn = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->DisableFogging = true;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter3->Opacity = 0.4;
	SpriteEmitter3->DetailMode = EDetailMode::DM_Medium;
	SpriteEmitter3->StartLocationRange = FRangeVector({ {-100, 100}, {-100, 100}, {0, 50} });
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter3->StartSpinRange = FRangeVector({ {-3, 3}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({1,2});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {10, 150}, {50, 150}, {50, 150} });
	SpriteEmitter3->InitialParticlesPerSecond = 60;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter4 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter4->UseColorScale = true;
	SpriteEmitter4->FadeOut = true;
	SpriteEmitter4->FadeIn = true;
	SpriteEmitter4->RespawnDeadParticles = false;
	SpriteEmitter4->SpinParticles = true;
	SpriteEmitter4->UseSizeScale = true;
	SpriteEmitter4->UseRegularSizeScale = false;
	SpriteEmitter4->UniformSize = true;
	SpriteEmitter4->AutomaticInitialSpawning = false;
	SpriteEmitter4->UseVelocityScale = true;
	SpriteEmitter4->AddVelocityFromOwner = true;
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({0.25,FColor(0, 0, 0, 255)});
	//SpriteEmitter4->ColorScale[2]=FParticleColorScale({5,FColor(0, 0, 0, 0)});
	SpriteEmitter4->Opacity = 0.5;
	SpriteEmitter4->FadeOutStartTime = 10;
	SpriteEmitter4->FadeInEndTime = 1;
	SpriteEmitter4->MaxParticles = 20;
	SpriteEmitter4->StartLocationRange = FRangeVector({ {-200, 200}, {-200, 200}, {0, 200} });
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	SpriteEmitter4->SpinsPerSecondRange = FRangeVector({ {-0.05, -0.1}, {-0.15, 0.15}, {-0.15, 0.15} });
	SpriteEmitter4->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({1,2});
	SpriteEmitter4->StartSizeRange = FRangeVector({ {200, 250}, {100, 100}, {100, 100} });
	SpriteEmitter4->InitialParticlesPerSecond = 1000;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 12, 15 });
	SpriteEmitter4->StartVelocityRange = FRangeVector({ {-75, 75}, {-75, 75}, {0, 200} });
	//SpriteEmitter4->VelocityScale(0) = (RelativeTime = 1, RelativeVelocity = FVector(0, 0, -0.5));
	Emitters = { SpriteEmitter3,SpriteEmitter4 };
	//bNoDelete = false;
};