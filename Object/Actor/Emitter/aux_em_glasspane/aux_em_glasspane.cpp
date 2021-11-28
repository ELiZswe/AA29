// All the original content belonged to the US Army

#include "aux_em_glasspane.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aaux_em_glasspane::Aaux_em_glasspane()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseCollision = true;
	SpriteEmitter0->UseMaxCollisions = true;
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->AutoDestroy = true;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->UseRandomSubdivision = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, -950);
	SpriteEmitter0->FadeOutStartTime = 3;
	SpriteEmitter0->MaxParticles = 50;
	SpriteEmitter0->StartLocationRange = FRangeVector({ {-60, 64}, {0, 0}, {-32, 32} });
	SpriteEmitter0->StartSizeRange = FRangeVector({ {3, 0.3}, {100, 100}, {100, 100} });
	//SpriteEmitter0->Sounds(0) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle1', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	//SpriteEmitter0->Sounds(1) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle2', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	//SpriteEmitter0->Sounds(2) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle3', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	SpriteEmitter0->CollisionSound = EParticleCollisionSound::PTSC_Random;
	SpriteEmitter0->CollisionSoundIndex = FRange({ 0, 1 });
	SpriteEmitter0->CollisionSoundProbability = FRange({ 0.5, 0.75 });
	SpriteEmitter0->InitialParticlesPerSecond = 50000;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_glasschunk_Mat.fx_part_glasschunk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 2;
	SpriteEmitter0->TextureVSubdivisions = 2;
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 5, 5 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-20, 200}, {-50, 50}, {0, 0} });
	Emitters = { SpriteEmitter0 };
	AutoDestroy = true;
	//bNoDelete = false;
};