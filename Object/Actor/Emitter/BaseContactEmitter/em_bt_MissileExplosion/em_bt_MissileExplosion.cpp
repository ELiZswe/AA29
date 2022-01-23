// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_MissileExplosion/em_bt_MissileExplosion.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Aem_bt_MissileExplosion::Aem_bt_MissileExplosion()
{
	USpriteEmitter* SpriteEmitter12 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter12->FadeOut = true;
	SpriteEmitter12->FadeIn = true;
	SpriteEmitter12->RespawnDeadParticles = false;
	SpriteEmitter12->DisableFogging = true;
	SpriteEmitter12->SpinParticles = true;
	SpriteEmitter12->UseSizeScale = true;
	SpriteEmitter12->UseRegularSizeScale = false;
	SpriteEmitter12->UniformSize = true;
	SpriteEmitter12->AutomaticInitialSpawning = false;
	//SpriteEmitter12->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter12->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter12->Opacity = 0.7;
	//SpriteEmitter12->DetailMode = 1;
	//SpriteEmitter12->StartLocationRange=X=(Min=-150, Max=150)|Y=(Min=-150, Max=150)|Z=(Min=0, Max=150);
	SpriteEmitter12->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter12->StartSpinRange=X=(Min=-3, Max=3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter12->SizeScale[0]=FParticleTimeScale({1,5});
	//SpriteEmitter12->StartSizeRange=X=(Min=10, Max=150)|Y=(Min=50, Max=150)|Z=(Min=50, Max=150);
	SpriteEmitter12->InitialParticlesPerSecond = 60;
	SpriteEmitter12->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter12->SecondsBeforeInactive = 0;
	SpriteEmitter12->LifetimeRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter13 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter13->UseColorScale = true;
	SpriteEmitter13->FadeOut = true;
	SpriteEmitter13->FadeIn = true;
	SpriteEmitter13->RespawnDeadParticles = false;
	SpriteEmitter13->SpinParticles = true;
	SpriteEmitter13->UseSizeScale = true;
	SpriteEmitter13->UseRegularSizeScale = false;
	SpriteEmitter13->UniformSize = true;
	SpriteEmitter13->AutomaticInitialSpawning = false;
	SpriteEmitter13->UseVelocityScale = true;
	SpriteEmitter13->AddVelocityFromOwner = true;
	//SpriteEmitter13->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter13->ColorScale[1]=FParticleColorScale({0.25,FColor(0, 0, 0, 255)});
	//SpriteEmitter13->ColorScale[2]=FParticleColorScale({5,FColor(0, 0, 0, 0)});
	SpriteEmitter13->Opacity = 0.5;
	SpriteEmitter13->FadeOutStartTime = 13;
	SpriteEmitter13->FadeInEndTime = 1.5;
	SpriteEmitter13->MaxParticles = 24;
	//SpriteEmitter13->StartLocationRange=X=(Min=-200, Max=200)|Y=(Min=-200, Max=200)|Z=(Min=0, Max=200);
	SpriteEmitter13->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter13->SpinsPerSecondRange=X=(Min=-0.05, Max=-0.1)|Y=(Min=-0.15, Max=0.15)|Z=(Min=-0.15, Max=0.15);
	//SpriteEmitter13->StartSpinRange=X=(Min=0, Max=1)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter13->SizeScale[0]=FParticleTimeScale({1,3});
	//SpriteEmitter13->StartSizeRange=X=(Min=200, Max=250)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter13->InitialParticlesPerSecond = 1000;
	SpriteEmitter13->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter13->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter13->LifetimeRange = FRange({ 14, 18 });
	//SpriteEmitter13->StartVelocityRange=X=(Min=-50, Max=50)|Y=(Min=-50, Max=50)|Z=(Min=0, Max=300);
	//SpriteEmitter13->VelocityScale(0) = (RelativeTime = 2, RelativeVelocity = FVector(0, 0, -1));
	USpriteEmitter* SpriteEmitter14 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter14->FadeOut = true;
	SpriteEmitter14->RespawnDeadParticles = false;
	SpriteEmitter14->SpinParticles = true;
	SpriteEmitter14->UseSizeScale = true;
	SpriteEmitter14->UseRegularSizeScale = false;
	SpriteEmitter14->UniformSize = true;
	SpriteEmitter14->AutomaticInitialSpawning = false;
	SpriteEmitter14->AddVelocityFromOwner = true;
	SpriteEmitter14->Acceleration = FVector(0, 0, -1200);
	//SpriteEmitter14->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter14->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter14->Opacity = 0.25;
	SpriteEmitter14->FadeOutStartTime = 0.5;
	SpriteEmitter14->MaxParticles = 16;
	//SpriteEmitter14->StartLocationRange=X=(Min=-100, Max=100)|Y=(Min=-100, Max=100)|Z=(Min=0, Max=0);
	//SpriteEmitter14->SpinsPerSecondRange=X=(Min=0.06, Max=0.06)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter14->StartSpinRange=X=(Min=-0.5, Max=0.5)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter14->SizeScale[0]=FParticleTimeScale({1,2});
	//SpriteEmitter14->StartSizeRange=X=(Min=200, Max=250)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter14->InitialParticlesPerSecond = 20;
	SpriteEmitter14->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter14->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/FX2_Parts_Dirtclumps_Large_Mat.FX2_Parts_Dirtclumps_Large_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter14->LifetimeRange = FRange({ 1, 2 });
	//SpriteEmitter14->StartVelocityRange=X=(Min=-50, Max=50)|Y=(Min=-50, Max=50)|Z=(Min=500, Max=1000);
	SpriteEmitter14->WarmupTicksPerSecond = 5000;
	SpriteEmitter14->RelativeWarmupTime = 0.1;
	UMeshEmitter* MeshEmitter8 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter8->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_con_chunk1.fx_part_con_chunk1'"), NULL, LOAD_None, NULL);
	MeshEmitter8->UseParticleColor = true;
	MeshEmitter8->UseMaxCollisions = true;
	MeshEmitter8->RespawnDeadParticles = false;
	MeshEmitter8->SpinParticles = true;
	MeshEmitter8->DampRotation = true;
	MeshEmitter8->AutomaticInitialSpawning = false;
	MeshEmitter8->AddVelocityFromOwner = true;
	MeshEmitter8->Acceleration = FVector(0, 0, -600);
	MeshEmitter8->MaxCollisions = FRange({ 10, 10 });
	//MeshEmitter8->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//MeshEmitter8->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	MeshEmitter8->FadeOutStartTime = 1;
	MeshEmitter8->MaxParticles = 20;
	//MeshEmitter8->StartLocationRange=X=(Min=-100, Max=100)|Y=(Min=-100, Max=100)|Z=(Min=0, Max=0);
	MeshEmitter8->StartMassRange = FRange({ 500, 500 });
	//MeshEmitter8->SpinsPerSecondRange=X=(Min=0.25, Max=0.5)|Y=(Min=0.25, Max=0.5)|Z=(Min=0.25, Max=0.5);
	//MeshEmitter8->RotationDampingFactorRange = X = (Min = 0.25, Max = 0.5) | Y = (Min = 0.25, Max = 0.5) | Z = (Min = 0.25, Max = 0.5);
	//MeshEmitter8->StartSizeRange=X=(Min=1, Max=2)|Y=(Min=1, Max=2)|Z=(Min=1, Max=2);
	MeshEmitter8->InitialParticlesPerSecond = 500;
	//MeshEmitter8->StartVelocityRange=X=(Min=-450, Max=400)|Y=(Min=-400, Max=400)|Z=(Min=100, Max=1200);
	Emitters = { SpriteEmitter12,SpriteEmitter13,SpriteEmitter14,MeshEmitter8 };
}
