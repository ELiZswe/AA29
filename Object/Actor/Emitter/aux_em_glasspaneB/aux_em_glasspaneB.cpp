// All the original content belonged to the US Army

#include "aux_em_glasspaneB.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aaux_em_glasspaneB::Aaux_em_glasspaneB()
{
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseCollision = true;
	SpriteEmitter2->UseMaxCollisions = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->AutoDestroy = true;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->UseRandomSubdivision = true;
	SpriteEmitter2->Acceleration = FVector(0, 0, -950);
	SpriteEmitter2->FadeOutStartTime = 3;
	SpriteEmitter2->MaxParticles = 50;
	SpriteEmitter2->StartLocationRange = FRangeVector({ {0, 0}, {-60, 64}, {-32, 32} });
	SpriteEmitter2->StartSizeRange = FRangeVector({ {3, 0.3}, {100, 100}, {100, 100} });
	//SpriteEmitter2->Sounds(0) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle1', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	//SpriteEmitter2->Sounds(1) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle2', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	//SpriteEmitter2->Sounds(2) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle3', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	SpriteEmitter2->CollisionSound = EParticleCollisionSound::PTSC_Random;
	SpriteEmitter2->CollisionSoundIndex = FRange({ 0, 1 });
	SpriteEmitter2->CollisionSoundProbability = FRange({ 0.5, 0.75 });
	SpriteEmitter2->InitialParticlesPerSecond = 50000;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_glasschunk_Mat.fx_part_glasschunk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->TextureUSubdivisions = 2;
	SpriteEmitter2->TextureVSubdivisions = 2;
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 5, 5 });
	SpriteEmitter2->StartVelocityRange = FRangeVector({ {-20, 200}, {-50, 50}, {0, 0} });
	Emitters = { SpriteEmitter2 };
	AutoDestroy = true;
	//bNoDelete = false;
}
