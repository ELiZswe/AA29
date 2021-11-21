// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/aux_em_compmonitor/aux_em_compmonitor.h"
#include "AA29/Object/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aaux_em_compmonitor::Aaux_em_compmonitor()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->ResetAfterChange = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->UseRandomSubdivision = true;
	SpriteEmitter1->Acceleration = FVector(0, 0, -950);
	SpriteEmitter1->ColorScale = { FParticleColorScale({ 0, FColor(175, 204, 253, 0) }),FParticleColorScale({1, FColor(250, 136, 33, 0) }) };
	SpriteEmitter1->FadeOutStartTime = 0.5;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SizeScale = { FParticleTimeScale({0, 0.05}),FParticleTimeScale({ 1, 0.01 }) };
	//SpriteEmitter1->StartSizeRange = X = (Min = 5, Max = 5) | Y = (Min = 100, Max = 100) | Z = (Min = 150, Max = 150);
	SpriteEmitter1->InitialParticlesPerSecond = 1000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_threads_Mat.fx_part_threads_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->TextureUSubdivisions = 2;
	SpriteEmitter1->TextureVSubdivisions = 2;
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.2, 0.3 });
	//SpriteEmitter1->StartVelocityRange = X = (Min = 250, Max = 250) | Y = (Min = 125, Max = -125) | Z = (Min = 125, Max = -125);
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->BlendBetweenSubdivisions = true;
	SpriteEmitter2->ColorScale = { FParticleColorScale({0, FColor(140, 150, 150, 0)}),FParticleColorScale({1, FColor(0, 0, 0, 0)}) };
	SpriteEmitter2->FadeOutStartTime = 1.5;
	SpriteEmitter2->MaxParticles = 3;
	SpriteEmitter2->StartLocationOffset = FVector(15, 0, 0);
	SpriteEmitter2->SizeScale = { FParticleTimeScale({ 0, 0.1 }),FParticleTimeScale({ 1, 0.25 }) };
	SpriteEmitter2->InitialParticlesPerSecond = 1000;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_smokeanim01_Mat.fx_part_smokeanim01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->TextureUSubdivisions = 4;
	SpriteEmitter2->TextureVSubdivisions = 2;
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 1, 2 });
	//SpriteEmitter2->StartVelocityRange = X = (Min = -10, Max = 10) | Y = (Min = -10, Max = 10) | Z = (Min = -10, Max = 10);
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseCollision = true;
	SpriteEmitter3->UseMaxCollisions = true;
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->FadeIn = true;
	SpriteEmitter3->ResetAfterChange = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->BlendBetweenSubdivisions = true;
	SpriteEmitter3->UseRandomSubdivision = true;
	SpriteEmitter3->Acceleration = FVector(0, 0, -750);
	SpriteEmitter3->ColorScale = { FParticleColorScale({0, FColor(255, 255, 255, 0)}) };
	SpriteEmitter3->FadeInEndTime = 1;
	SpriteEmitter3->MaxParticles = 5;
	SpriteEmitter3->StartLocationOffset = FVector(2, 0, 0);
	//SpriteEmitter3->StartSpinRange = X = (Min = 3, Max = -3) | Y = (Min = 0, Max = 0) | Z = (Min = 0, Max = 0);
	SpriteEmitter3->SizeScale = { FParticleTimeScale({ 0, 0.05 }),FParticleTimeScale({ 1, 0.1 }) };
	//SpriteEmitter3->StartSizeRange = X = (Min = 25, Max = 25) | Y = (Min = 100, Max = 100) | Z = (Min = 100, Max = 100);
	//SpriteEmitter3->Sounds(0) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle1', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	//SpriteEmitter3->Sounds(1) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle2', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	//SpriteEmitter3->Sounds(2) = (Sound = Sound'S_AA2_Foley.bulletimpacts.tinkle3', Radius = (Min = 30, Max = 40), Pitch = (Min = 1, Max = 1.8), Weight = 1, Volume = (Min = 0.5, Max = 1), Probability = (Min = 1, Max = 1));
	SpriteEmitter3->CollisionSound = EParticleCollisionSound::PTSC_Random;
	SpriteEmitter3->CollisionSoundIndex = FRange({ 0, 1 });
	SpriteEmitter3->CollisionSoundProbability = FRange({1, 1});
	SpriteEmitter3->InitialParticlesPerSecond = 1000;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_glasschunk_Mat.fx_part_glasschunk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->TextureUSubdivisions = 2;
	SpriteEmitter3->TextureVSubdivisions = 2;
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 1, 1.7 });
	//SpriteEmitter3->StartVelocityRange = X = (Min = 60, Max = -60) | Y = (Min = 60, Max = -60) | Z = (Min = 60, Max = -60);
	Emitters = { SpriteEmitter1,SpriteEmitter2,SpriteEmitter3 };

}

void Aaux_em_compmonitor::BeginPlay()
{
	//Spawn(class'AGP_Effects.aux_light_electronics');
}
