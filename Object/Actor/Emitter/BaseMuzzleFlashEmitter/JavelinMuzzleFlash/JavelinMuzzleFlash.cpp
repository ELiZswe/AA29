// All the original content belonged to the US Army

#include "JavelinMuzzleFlash.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

AJavelinMuzzleFlash::AJavelinMuzzleFlash()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseCollision = true;
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->Acceleration = FVector(5, 5, 7.5);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(149, 172, 157, 122)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({0.289286,FColor(219, 221, 220, 255)});
	//SpriteEmitter0->ColorScale[2]=FParticleColorScale({1,FColor(139, 141, 140, 255)});
	//SpriteEmitter0->ColorScale[3]=FParticleColorScale({1,FColor(139, 139, 139, 255)});
	//SpriteEmitter0->ColorScale[4]=FParticleColorScale({1,FColor(198, 201, 204, 122)});
	SpriteEmitter0->Opacity = 0.2;
	SpriteEmitter0->FadeOutStartTime = 0.5;
	SpriteEmitter0->MaxParticles = 64;
	SpriteEmitter0->StartLocationOffset = FVector(0, 75, 0);
	SpriteEmitter0->StartLocationRange = FRangeVector({ {-32, 32}, {-32, 32}, {-25, 25} });
	SpriteEmitter0->SphereRadiusRange = FRange({ 5, 80 });
	SpriteEmitter0->StartLocationPolarRange = FRangeVector({ {500, 500}, {500, 500}, {0, 0} });
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.05, 0.1}, {0, 0}, {0, 0} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {-1, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {36, 72}, {100, 100}, {100, 100} });
	SpriteEmitter0->InitialParticlesPerSecond = 1500;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->LifetimeRange = FRange({ 5, 7 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-750, 750}, {-250, 750}, {-7.5, -7.5} });
	SpriteEmitter0->VelocityLossRange = FRangeVector({ {5, 5}, {5, 5}, {0, 0} });
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Backblast.Backblast'"), NULL, LOAD_None, NULL);
	MeshEmitter0->UseMeshBlendMode = false;
	MeshEmitter0->RenderTwoSided = true;
	MeshEmitter0->UseParticleColor = true;
	MeshEmitter0->AbsoluteRotationSource = EAbsoluteRotationSource::PARS_ActorPlusOffset;
	MeshEmitter0->FadeOut = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->UseSizeScale = true;
	MeshEmitter0->UseRegularSizeScale = false;
	MeshEmitter0->AutomaticInitialSpawning = false;
	//MeshEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//MeshEmitter0->ColorScale[1]=FParticleColorScale({0.571429,FColor(255, 255, 255, 255)});
	//MeshEmitter0->ColorScale[2]=FParticleColorScale({1,FColor(0, 0, 236, 255)});
	MeshEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter0->MaxParticles = 1;
	//MeshEmitter0->SizeScale[0]=FParticleTimeScale({0,0.5});
	//MeshEmitter0->SizeScale[1]=FParticleTimeScale({0.25,1});
	MeshEmitter0->StartSizeRange = FRangeVector({ {0.75, 0.75}, {0.75, 0.75}, {0.75, 0.75} });
	MeshEmitter0->InitialParticlesPerSecond = 80000;
	MeshEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	MeshEmitter0->LifetimeRange = FRange({ 0.3, 0.3 });
	MeshEmitter0->iFlashSpawnCount = 1;
	MeshEmitter0->MinFramesBeforeDeath = 1;
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(5, 5, 7.5);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(217, 219, 221, 122)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 122)});
	SpriteEmitter1->Opacity = 0.25;
	SpriteEmitter1->FadeOutStartTime = 0.14;
	SpriteEmitter1->MaxParticles = 96;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {0, 25}, {-90, -90}, {0, 25} });
	SpriteEmitter1->SphereRadiusRange = FRange({ 0, 50 });
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0, 0.3}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,2});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {2, 45}, {100, 100}, {100, 100} });
	SpriteEmitter1->InitialParticlesPerSecond = 1500;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball02_Mat.fx_smk_ball02_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->LifetimeRange = FRange({ 5, 7 });
	SpriteEmitter1->InitialDelayRange = FRange({ 0.25, 0.25 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {-500, 500}, {0, 800}, {-250, 250} });
	SpriteEmitter1->VelocityLossRange = FRangeVector({ {4, 4}, {4, 4}, {3, 3} });
	Emitters = { SpriteEmitter0,MeshEmitter0,SpriteEmitter1 };
	LifeSpan = 10;
};

void AJavelinMuzzleFlash::BeginPlay()
{
	//Super::BeginPlay();
	Cast<UMeshEmitter>(Emitters[1])->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Backblast.Backblast'"), NULL, LOAD_None, NULL);
}

void AJavelinMuzzleFlash::DynamicFlash()
{
	/*
	local Emitter E;
	FVector NewRel = FVector(0, 0, 0);
	E = Spawn(Class'AGP_Effects.aux_light_ExpLight');
	E.SetBase(Self);
	NewRel.X = 250;
	E.SetRelativeLocation(NewRel);
	*/
}