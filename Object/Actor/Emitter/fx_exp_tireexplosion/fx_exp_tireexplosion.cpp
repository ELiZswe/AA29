// All the original content belonged to the US Army

#include "fx_exp_tireexplosion.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Afx_exp_tireexplosion::Afx_exp_tireexplosion()
{
	UMeshEmitter* MeshEmitter16 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter16->UseCollision = true;
	MeshEmitter16->UseMaxCollisions = true;
	MeshEmitter16->RespawnDeadParticles = false;
	MeshEmitter16->AutoDestroy = true;
	MeshEmitter16->SpinParticles = true;
	MeshEmitter16->AutomaticInitialSpawning = false;
	MeshEmitter16->Acceleration = FVector(0, 0, -999);
	MeshEmitter16->DampingFactorRange = FRangeVector({ {0.6, 0.7}, {0.6, 0.7}, {0.2, 0.2} });
	MeshEmitter16->MaxCollisions = FRange({ 4, 4 });
	MeshEmitter16->MaxParticles = 0;
	MeshEmitter16->StartLocationRange = FRangeVector({ {122, 122}, {-66, -66}, {-166, -166} });
	MeshEmitter16->SpinsPerSecondRange = FRangeVector({ {0.01, 0.5}, {0.01, 0.5}, {-0.01, -2} });
	MeshEmitter16->StartSpinRange = FRangeVector({ {0, 0}, {0, 0}, {12000, 12000} });
	MeshEmitter16->InitialParticlesPerSecond = 500;
	MeshEmitter16->SecondsBeforeInactive = 0;
	MeshEmitter16->LifetimeRange = FRange({ 5, 5 });
	MeshEmitter16->InitialDelayRange = FRange({ 0.15, 0.15 });
	MeshEmitter16->StartVelocityRange = FRangeVector({ {900, 1600}, {-200, 200}, {800, 1100} });
	MeshEmitter16->VelocityLossRange = FRangeVector({ {1, 1}, {1, 1}, {1, 1} });
	USpriteEmitter* SpriteEmitter17 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter17->FadeOut = true;
	SpriteEmitter17->RespawnDeadParticles = false;
	SpriteEmitter17->SpinParticles = true;
	SpriteEmitter17->UseSizeScale = true;
	SpriteEmitter17->UseRegularSizeScale = false;
	SpriteEmitter17->UniformSize = true;
	SpriteEmitter17->AutomaticInitialSpawning = false;
	SpriteEmitter17->BlendBetweenSubdivisions = true;
	SpriteEmitter17->FadeOutStartTime = 0.3;
	SpriteEmitter17->MaxParticles = 2;
	SpriteEmitter17->StartLocationRange = FRangeVector({ {122, 122}, {-66, -66}, {-133, -133} });
	SpriteEmitter17->SpinsPerSecondRange = FRangeVector({ {0.2, 0.2}, {0, 0}, {0, 0} });
	SpriteEmitter17->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter17->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter17->SizeScale[1]=FParticleTimeScale({1,3});
	SpriteEmitter17->StartSizeRange = FRangeVector({ {33, 44}, {100, 100}, {100, 100} });
	SpriteEmitter17->InitialParticlesPerSecond = 15;
	SpriteEmitter17->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter17->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_explosion01_Mat.fx_part_explosion01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter17->TextureUSubdivisions = 4;
	SpriteEmitter17->TextureVSubdivisions = 2;
	SpriteEmitter17->SecondsBeforeInactive = 0;
	SpriteEmitter17->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter17->InitialDelayRange = FRange({ 0.1, 0.1 });
	SpriteEmitter17->StartVelocityRange = FRangeVector({ {0, 0}, {-33, -33}, {0, 0} });
	USpriteEmitter* SpriteEmitter18 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter18->UseColorScale = true;
	SpriteEmitter18->FadeOut = true;
	SpriteEmitter18->RespawnDeadParticles = false;
	SpriteEmitter18->UseSizeScale = true;
	SpriteEmitter18->UseRegularSizeScale = false;
	SpriteEmitter18->UniformSize = true;
	SpriteEmitter18->AutomaticInitialSpawning = false;
	SpriteEmitter18->Acceleration = FVector(0, 0, -777);
	//SpriteEmitter18->ColorScale[0]=FParticleColorScale({0,FColor(140, 194, 255, 0)});
	//SpriteEmitter18->ColorScale[1]=FParticleColorScale({1,FColor(38, 57, 89, 0)});
	SpriteEmitter18->FadeOutStartTime = 0.5;
	SpriteEmitter18->MaxParticles = 55;
	SpriteEmitter18->StartLocationRange = FRangeVector({ {122, 144}, {-58, -78}, {-123, -143} });
	//SpriteEmitter18->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter18->SizeScale[1]=FParticleTimeScale({1,0.8});
	SpriteEmitter18->StartSizeRange = FRangeVector({ {5, 7}, {100, 100}, {100, 100} });
	SpriteEmitter18->InitialParticlesPerSecond = 1111;
	SpriteEmitter18->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter18->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter18->LifetimeRange = FRange({ 1.5, 2.7 });
	SpriteEmitter18->InitialDelayRange = FRange({ 0.1, 0.1 });
	SpriteEmitter18->StartVelocityRange = FRangeVector({ {-200, 200}, {-55, -900}, {100, 500} });
	SpriteEmitter18->VelocityLossRange = FRangeVector({ {1, 1}, {1, 1}, {1, 1} });
	USpriteEmitter* SpriteEmitter19 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter19->RespawnDeadParticles = false;
	SpriteEmitter19->SpinParticles = true;
	SpriteEmitter19->UniformSize = true;
	SpriteEmitter19->AutomaticInitialSpawning = false;
	//SpriteEmitter19->ColorScale[0]=FParticleColorScale({0,FColor(252, 252, 252, 255)});
	//SpriteEmitter19->ColorScale[1]=FParticleColorScale({1,FColor(253, 253, 253, 255)});
	SpriteEmitter19->MaxParticles = 1;
	SpriteEmitter19->StartLocationRange = FRangeVector({ {122, 122}, {-66, -66}, {-133, -133} });
	SpriteEmitter19->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	SpriteEmitter19->StartSizeRange = FRangeVector({ {122, 122}, {100, 100}, {100, 100} });
	SpriteEmitter19->InitialParticlesPerSecond = 44;
	SpriteEmitter19->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter19->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter19->SecondsBeforeInactive = 0;
	SpriteEmitter19->LifetimeRange = FRange({ 0.03, 0.03 });
	SpriteEmitter19->InitialDelayRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter20 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter20->RespawnDeadParticles = false;
	SpriteEmitter20->SpinParticles = true;
	SpriteEmitter20->UseSizeScale = true;
	SpriteEmitter20->UseRegularSizeScale = false;
	SpriteEmitter20->UniformSize = true;
	SpriteEmitter20->AutomaticInitialSpawning = false;
	//SpriteEmitter20->ColorScale[0]=FParticleColorScale({0,FColor(252, 252, 252, 255)});
	//SpriteEmitter20->ColorScale[1]=FParticleColorScale({1,FColor(253, 253, 253, 255)});
	SpriteEmitter20->MaxParticles = 2;
	SpriteEmitter20->StartLocationRange = FRangeVector({ {-122, 122}, {0, 0}, {-55, -55} });
	SpriteEmitter20->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter20->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter20->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter20->StartSizeRange = FRangeVector({ {22, 55}, {100, 100}, {100, 100} });
	SpriteEmitter20->InitialParticlesPerSecond = 33;
	SpriteEmitter20->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter20->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter20->SecondsBeforeInactive = 0;
	SpriteEmitter20->LifetimeRange = FRange({ 0.03, 0.03 });
	Emitters = { MeshEmitter16,SpriteEmitter17,SpriteEmitter18,SpriteEmitter19,SpriteEmitter20 };
	//bNoDelete = false;
};

void Afx_exp_tireexplosion::BeginPlay()
{
	//MeshEmitter(Emitters[0]).StaticMesh = StaticMesh(DynamicLoadObject("M_AA2_Vehicles.btr-80.veh2_btr80_wheel", Class'StaticMesh'));
}

void Afx_exp_tireexplosion::PostBeginPlay()
{
	SpawnLight();
}

void Afx_exp_tireexplosion::SpawnLight()
{
	/*
	local Emitter E;
	FVector NewRel = FVector(0, 0, 0);
	E = Spawn(class'AGP_Effects.aux_light_ExpLight');
	E.SetBase(Self);
	NewRel.X = 200;
	NewRel.Y = -70;
	E.SetRelativeLocation(NewRel);
	*/
}
