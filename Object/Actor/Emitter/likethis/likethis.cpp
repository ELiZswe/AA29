// All the original content belonged to the US Army

#include "likethis.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Alikethis::Alikethis()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Absolute;
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({10,10});
	SpriteEmitter0->ParticlesPerSecond = 0.5;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->LifetimeRange = FRange({ 10, 10 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {20, 20}, {0, 0}, {0, 0} });
	Emitters = { SpriteEmitter0 };
};