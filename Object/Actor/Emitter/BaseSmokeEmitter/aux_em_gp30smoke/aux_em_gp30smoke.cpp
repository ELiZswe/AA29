// All the original content belonged to the US Army


#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/aux_em_gp30smoke/aux_em_gp30smoke.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aaux_em_gp30smoke::Aaux_em_gp30smoke()
{
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({1,FColor(60, 70, 70, 0)});
	SpriteEmitter3->MaxParticles = 80;
	SpriteEmitter3->SphereRadiusRange = FRange({ 1024, 1024 });
	SpriteEmitter3->SpinsPerSecondRange = FRangeVector({ {0.01, 0.01}, {0.01, 0.01}, {0.01, 0.01} });
	SpriteEmitter3->StartSpinRange = FRangeVector({ {-300, 300}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0.35,100});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({1,120});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {1, 1}, {1, 1}, {1, 1} });
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball04_Mat.fx_smk_ball04_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 1, 1 });
	SpriteEmitter3->StartVelocityRange = FRangeVector({ {25, -25}, {25, -25}, {17, 20} });
	Emitters = { SpriteEmitter3 };
}