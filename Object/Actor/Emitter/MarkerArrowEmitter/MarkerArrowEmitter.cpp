// All the original content belonged to the US Army

#include "MarkerArrowEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

AMarkerArrowEmitter::AMarkerArrowEmitter()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FirstAid/arrow/Move_Arrow.Move_Arrow'"), NULL, LOAD_None, NULL);
	MeshEmitter0->UseSizeScale = true;
	MeshEmitter0->UseRegularSizeScale = false;
	MeshEmitter0->CoordinateSystem = EParticleCoordinateSystem::PTCS_Relative;
	MeshEmitter0->MaxParticles = 3;
	//MeshEmitter0->SizeScale[0]=FParticleTimeScale({4,10});
	MeshEmitter0->StartVelocityRange = FRangeVector({ {100, 100}, {0, 0}, {0, 0} });
	Emitters = { MeshEmitter0 };
	//bLightChanged = true;
	//bNoDelete = false;
	//Tag = "ToStation1_Arrow";
	//bUnlit = false;
	//bDirectional = true;
	//bIsLocal = true;
};