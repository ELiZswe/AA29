// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projector/FSTS_LocationMarker/FSTS_LocationMarker.h"

AFSTS_LocationMarker::AFSTS_LocationMarker()
{
	MarkOffset = FVector(0, 0, 140);
	//FrameBufferBlendingOp = 2;
	//ProjTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_FX/Projectors/X_marks_the_spot_Mat.X_marks_the_spot_Mat'"), NULL, LOAD_None, NULL);
	//FOV = 20;
	//MaxTraceDistance = 300;
	//bProjectParticles = false;
	//bProjectActor = false;
	//bClipBSP = true;
	//bClipStaticMesh = true;
	//bGradient = true;
	//bProjectOnParallelBSP = false;
	//bStatic = false;
	//Tag = "LocationMarker";
	//Rotation = FRotator(-16384, 0, 0);
	//DrawScale = 0.25;
	//bUnlit = true;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
}

void AFSTS_LocationMarker::PostBeginPlay()
{
	//Super::PostBeginPlay();
	DeactivateMarker();
}

bool AFSTS_LocationMarker::IsMarkerActive()
{
	return bMarkerActive;
}

void AFSTS_LocationMarker::ActivateMarker()
{
	//AttachProjector();
	bMarkerActive = true;
}

void AFSTS_LocationMarker::DeactivateMarker()
{
	//DetachProjector(true);
	bMarkerActive = false;
}

bool AFSTS_LocationMarker::SetMarkingLocation(FVector NewLocation, FVector AdditionalMarkOffset)
{
	FVector newMarkerLocation = FVector(0, 0, 0);
	newMarkerLocation = ((NewLocation + MarkOffset) + AdditionalMarkOffset);
	//SetLocation(newMarkerLocation);
	return true;
}
