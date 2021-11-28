// All the original content belonged to the US Army

#include "m2a2MuzzleFlash.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Am2a2MuzzleFlash::Am2a2MuzzleFlash()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_ak47.fx_flash_ak47'"), NULL, LOAD_None, NULL);
	MeshEmitter0->RenderTwoSided = true;
	MeshEmitter0->bUseAbsoluteRotation = true;
	MeshEmitter0->AbsoluteRotationSource = EAbsoluteRotationSource::PARS_ActorOnly;
	MeshEmitter0->FadeOut = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->UseSizeScale = true;
	MeshEmitter0->UseRegularSizeScale = false;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter0->MaxParticles = 1;
	MeshEmitter0->StartLocationOffset = FVector(0, -5, 0);
	//MeshEmitter0->SizeScale[0]=FParticleTimeScale({0.5,1});
	//MeshEmitter0->SizeScale[1]=FParticleTimeScale({1,2.5});
	MeshEmitter0->StartSizeRange = FRangeVector({ {0.75, 0.75}, {0.75, 0.75}, {0.75, 0.75} });
	MeshEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	MeshEmitter0->LifetimeRange = FRange({ 0.04, 0.04 });
	MeshEmitter0->iFlashSpawnCount = 1;
	MeshEmitter0->MinFramesBeforeDeath = 1;
	//smokeclass = class'AGP_Effects.m2a2muzzlesmoke';
	Emitters = { MeshEmitter0 };
	LifeSpan = 1000000;
};

void Am2a2MuzzleFlash::DynamicFlash()
{
	Super::DynamicFlash();
	//smokeemitter = Spawn(smokeclass, Self, , Self.Location, Self.Rotation);
}