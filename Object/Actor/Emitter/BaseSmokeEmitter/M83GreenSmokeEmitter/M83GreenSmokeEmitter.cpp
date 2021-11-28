// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/M83GreenSmokeEmitter/M83GreenSmokeEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AM83GreenSmokeEmitter::AM83GreenSmokeEmitter()
{
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->bCanJavelinSeeThrough = true;
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(36, 181, 112, 255)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(9, 213, 54, 220)});
	SpriteEmitter3->FadeOutFactor = FPlane({ 1.5, 1, 1, 1 });
	SpriteEmitter3->FadeOutStartTime = 6;
	SpriteEmitter3->MaxParticles = 35;
	SpriteEmitter3->StartLocationRange = FRangeVector({ {-5, 5}, {-5, 5}, {0, 0} });
	SpriteEmitter3->SphereRadiusRange = FRange({ 1024, 1024 });
	SpriteEmitter3->SpinsPerSecondRange = FRangeVector({ {0.02, 0.02}, {0.02, 0.03}, {0.02, 0.03} });
	SpriteEmitter3->StartSpinRange = FRangeVector({ {-100, 100}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0.35,200});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({1,220});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {1, 1}, {1, 1.3}, {1, 1.3} });
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 10, 20 });
	SpriteEmitter3->StartVelocityRange = FRangeVector({ {45, -45}, {45, -45}, {17, 20} });
	Emitters = { SpriteEmitter3 };
	//RemoteRole = ROLE_None;
}