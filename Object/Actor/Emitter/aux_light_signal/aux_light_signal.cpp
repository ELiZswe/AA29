// All the original content belonged to the US Army

#include "aux_light_signal.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aaux_light_signal::Aaux_light_signal()
{
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->UseColorScale = true;
	SpriteEmitter7->FadeOut = true;
	SpriteEmitter7->FadeIn = true;
	SpriteEmitter7->UniformSize = true;
	//SpriteEmitter7->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter7->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter7->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	SpriteEmitter7->MaxParticles = 1;
	SpriteEmitter7->StartSizeRange = FRangeVector({ {16, 16}, {16, 16}, {16, 16} });
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->LifetimeRange = FRange({ 1, 1 });
	SpriteEmitter7->WarmupTicksPerSecond = 4;
	SpriteEmitter7->RelativeWarmupTime = 2;
	Emitters = { SpriteEmitter7 };
	//bNoDelete = false;
};


void Aaux_light_signal::SetSignalColor(FColor Color)
{
	//Emitters[0].ColorScale[0].Color = Class'Canvas'.MakeColor(Color.R, Color.G, Color.B, Color.A);
	//Emitters[0].ColorScale[1].Color = Class'Canvas'.MakeColor(Color.R, Color.G, Color.B, Color.A);
}
void Aaux_light_signal::SetSignalSize(float Units)
{
	//Emitters[0].StartSizeRange.X.Min = Units;
	//Emitters[0].StartSizeRange.X.Max = Units;
	//Emitters[0].StartSizeRange.Y.Min = Units;
	//Emitters[0].StartSizeRange.Y.Max = Units;
	//Emitters[0].StartSizeRange.Z.Min = Units;
	//Emitters[0].StartSizeRange.Z.Max = Units;
}