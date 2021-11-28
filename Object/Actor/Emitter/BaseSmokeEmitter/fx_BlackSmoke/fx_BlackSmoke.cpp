// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/fx_BlackSmoke/fx_BlackSmoke.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Afx_BlackSmoke::Afx_BlackSmoke()
{
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->FadeOut = true;
	SpriteEmitter7->SpinParticles = true;
	SpriteEmitter7->UseSizeScale = true;
	SpriteEmitter7->UseRegularSizeScale = false;
	SpriteEmitter7->UniformSize = true;
	SpriteEmitter7->Acceleration = FVector(-5, 2, 0);
	SpriteEmitter7->FadeOutStartTime = 5;
	SpriteEmitter7->MaxParticles = 48;
	SpriteEmitter7->SpinCCWorCW = FVector(0.25, 0.75, 0.5);
	SpriteEmitter7->SpinsPerSecondRange = FRangeVector({ {0, 0.05}, {0, 0.05}, {0, 0.05} });
	//SpriteEmitter7->SizeScale[0]=FParticleTimeScale({0,0.4});
	//SpriteEmitter7->SizeScale[1]=FParticleTimeScale({5,4});
	SpriteEmitter7->StartSizeRange = FRangeVector({ {50, 100}, {50, 100}, {50, 100} });
	SpriteEmitter7->DrawStyle = EParticleDrawStyle::PTDS_Darken;
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->TextureUSubdivisions = 1;
	SpriteEmitter7->TextureVSubdivisions = 1;
	SpriteEmitter7->LifetimeRange = FRange({ 10, 10 });
	SpriteEmitter7->StartVelocityRange = FRangeVector({ {-5, 5}, {-5, 5}, {25, 75} });
	SpriteEmitter7->WarmupTicksPerSecond = 8;
	SpriteEmitter7->RelativeWarmupTime = 1;
	SpriteEmitter7->fWindFactor = 3;
	Emitters = { SpriteEmitter7 };
	//bNoDelete = true;
}