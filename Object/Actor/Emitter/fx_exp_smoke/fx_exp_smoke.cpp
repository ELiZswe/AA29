// All the original content belonged to the US Army

#include "fx_exp_smoke.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Afx_exp_smoke::Afx_exp_smoke()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->FadeIn = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->ResetOnTrigger = true;
	SpriteEmitter0->Acceleration = FVector(5, 0, 0);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(30, 30, 30, 255)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({3,FColor(226, 226, 226, 255)});
	SpriteEmitter0->FadeOutStartTime = 5;
	SpriteEmitter0->FadeInEndTime = 1;
	SpriteEmitter0->MaxParticles = 28;
	SpriteEmitter0->SpinCCWorCW = FVector(0.25, 0.75, 0.5);
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.06, 0.08}, {0, 0.05}, {0, 0.1} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,0.3});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({5,5});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {50, 100}, {50, 100}, {50, 100} });
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 1;
	SpriteEmitter0->TextureVSubdivisions = 1;
	SpriteEmitter0->LifetimeRange = FRange({ 10, 10 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-5, 5}, {-5, 5}, {50, 25} });
	SpriteEmitter0->fWindFactor = 3;
	Emitters = { SpriteEmitter0 };
	//bNoDelete = false;
};