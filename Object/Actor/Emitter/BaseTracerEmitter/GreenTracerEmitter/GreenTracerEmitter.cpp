// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseTracerEmitter/GreenTracerEmitter/GreenTracerEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

AGreenTracerEmitter::AGreenTracerEmitter()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_greentracer.fx_flash_greentracer'"), NULL, LOAD_None, NULL);
	MeshEmitter0->bUseAbsoluteRotation = true;
	MeshEmitter0->AbsoluteRotationSource = EAbsoluteRotationSource::PARS_ActorOnly;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter0->MaxParticles = 1;
	MeshEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	MeshEmitter0->StartSizeRange = FRangeVector({ {1.125, 1.725}, {0.625, 0.625}, {0.625, 0.625} });
	MeshEmitter0->InitialParticlesPerSecond = 5000;
	MeshEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	MeshEmitter0->SecondsBeforeInactive = 0;
	Emitters = { MeshEmitter0 };
	//LightHue = 75;
	//LightSaturation = 173;
}