// All the original content belonged to the US Army

#include "AA29/Object/Actor/FSTS_HelpMarker/FSTS_DirectionMarker/FSTS_DirectionMarker.h"
#include "AA29/Object/Actor/Emitter/MarkerArrowEmitter/MarkerArrowEmitter.h"

AFSTS_DirectionMarker::AFSTS_DirectionMarker()
{
	PrimaryDrawScale = 1;
	AltDrawScale = 2;
	PrimaryStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FirstAid/arrow/Move_Arrow.Move_Arrow'"), NULL, LOAD_None, NULL);
	AltStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FirstAid/arrow/Move_Arrow.Move_Arrow'"), NULL, LOAD_None, NULL);
	BounceAxis = EBounceAxis::BA_LocalXAxis;
	//CustomDisplayClass = AMarkerArrowEmitter::StaticClass();
	//DrawType = DT_None;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FirstAid/arrow/Move_Arrow.Move_Arrow'"), NULL, LOAD_None, NULL);
	//RotationRate = FRotator(0, 0, 0);
}
