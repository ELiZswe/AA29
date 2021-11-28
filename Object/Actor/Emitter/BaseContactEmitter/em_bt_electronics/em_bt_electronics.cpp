// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_electronics/em_bt_electronics.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_bt_electronics::Aem_bt_electronics()
{
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->ResetAfterChange = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->UseRandomSubdivision = true;
	SpriteEmitter3->Acceleration = FVector(0, 0, -950);
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(175, 204, 253, 0)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(250, 136, 33, 0)});
	SpriteEmitter3->FadeOutStartTime = 0.5;
	SpriteEmitter3->MaxParticles = 5;
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,0.05});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({1,0.01});
	//SpriteEmitter3->StartSizeRange=X=(Min=5, Max=5)|Y=(Min=100, Max=100)|Z=(Min=150, Max=150);
	SpriteEmitter3->InitialParticlesPerSecond = 1000;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_threads_Mat.fx_part_threads_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->TextureUSubdivisions = 2;
	SpriteEmitter3->TextureVSubdivisions = 2;
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 0.2, 0.3 });
	//SpriteEmitter3->StartVelocityRange=X=(Min=250, Max=250)|Y=(Min=125, Max=-125)|Z=(Min=125, Max=-125);
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->BlendBetweenSubdivisions = true;
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(14, 15, 15, 0)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter2->FadeOutStartTime = 1.5;
	SpriteEmitter2->MaxParticles = 3;
	SpriteEmitter2->StartLocationOffset = FVector(15, 0, 0);
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,0.1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,0.25});
	SpriteEmitter2->InitialParticlesPerSecond = 1000;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_smokeanim01_Mat.fx_part_smokeanim01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->TextureUSubdivisions = 4;
	SpriteEmitter2->TextureVSubdivisions = 2;
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 1, 2 });
	//SpriteEmitter2->StartVelocityRange=X=(Min=-25, Max=-25)|Y=(Min=-10, Max=10)|Z=(Min=-10, Max=10);
	Emitters = { SpriteEmitter3,SpriteEmitter2 };
}

void Aem_bt_electronics::BeginPlay()
{
	//Spawn(class'AGP_Effects.aux_light_electronics');
}
