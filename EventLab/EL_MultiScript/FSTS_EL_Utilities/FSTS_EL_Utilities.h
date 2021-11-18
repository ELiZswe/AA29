// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EL_MultiScript/EL_MultiScript.h"
#include "FSTS_EL_Utilities.generated.h"

class AAGP_Objective;
class AFSTS_NPC_DrillSergeant;
UCLASS()
class AA29_API AFSTS_EL_Utilities : public AEL_MultiScript
{
	GENERATED_BODY()
public:
	AFSTS_EL_Utilities();

	//UPROPERTY()						TArray<AHelpInfo*> HelpInfoList;							//var array<HelpInfo> HelpInfoList;
	//UPROPERTY()						TArray<ATriggeredPlayerBlockingVolume*> BlockingVolumes;	//var array<TriggeredPlayerBlockingVolume> BlockingVolumes;
	UPROPERTY()						FString StationName;											//var string StationName;
	UPROPERTY()						int32 StationNumber;											//var int StationNumber;
	UPROPERTY()						int32 AuthNumStationsPassed;									//var int AuthNumStationsPassed;
	UPROPERTY()						int32 NumStationsPassed;										//var int NumStationsPassed;
	UPROPERTY()						FString TrainingName;											//var string TrainingName;
	UPROPERTY()						bool bPassedTraining;											//var bool bPassedTraining;
	UPROPERTY()						bool bFadeMoveFromDrillSergeantUse;								//var bool bFadeMoveFromDrillSergeantUse;
	UPROPERTY()						bool bStartFromDrillSergeantUse;								//var bool bStartFromDrillSergeantUse;
	UPROPERTY()						bool bAcceptDrillSergeantUse;									//var bool bAcceptDrillSergeantUse;
	UPROPERTY()						FName StationBeginPointTag;										//var name StationBeginPointTag;
	UPROPERTY()						bool bFadeMoveActive;											//var bool bFadeMoveActive;
	UPROPERTY()						FFadeMoveInfoStruct FadeMoveInfo;								//var FadeMoveInfoStruct FadeMoveInfo;
	UPROPERTY()						FName ResetActorTag;											//var name ResetActorTag;
	UPROPERTY()						FName StationObjectiveTag;										//var name StationObjectiveTag;
	UPROPERTY()						AAGP_Objective* StationObjective;								//var AGP.AGP_Objective StationObjective;
	UPROPERTY()						int32 NumStationsRequired;										//var int NumStationsRequired;
	UPROPERTY()						bool bStationComplete;											//var bool bStationComplete;
	UPROPERTY()						bool bNoReportStationToAAR;										//var bool bNoReportStationToAAR;
	UPROPERTY()						FName ProximityAlertTag;										//var name ProximityAlertTag;
	UPROPERTY()						float ProximityRadius;											//var float ProximityRadius;
	UPROPERTY()						AActor* ProximityMoveActor;										//var Actor ProximityMoveActor;
	UPROPERTY()						AActor* ProximityDestination;									//var Actor ProximityDestination;
	UPROPERTY()						bool bDetectActorProximity;										//var bool bDetectActorProximity;
	UPROPERTY()						FVector HelpMarkerLargeOffset;									//var FVector HelpMarkerLargeOffset;
	UPROPERTY()						FVector HelpMarkerSmallOffset;									//var FVector HelpMarkerSmallOffset;
	//UPROPERTY()						AFSTS_DirectionMarker* DirectionMarker;						//var FSTS_DirectionMarker DirectionMarker;
	UPROPERTY()						bool bCreateDirectionMarker;									//var bool bCreateDirectionMarker;
	//UPROPERTY()						AFSTS_HelpMarker* HelpMarker;								//var FSTS_HelpMarker HelpMarker;
	UPROPERTY()						bool bCreateHelpMarker;											//var bool bCreateHelpMarker;
	//UPROPERTY()						AFSTS_LocationMarker* LocationMarker;						//var FSTS_LocationMarker LocationMarker;
	UPROPERTY()						bool bCreateLocationMarker;										//var bool bCreateLocationMarker;
	UPROPERTY()						FName AltDrillSergeantTag;										//var name AltDrillSergeantTag;
	UPROPERTY()						AFSTS_NPC_DrillSergeant* AltDrillSergeant;						//var FSTS_NPC_DrillSergeant AltDrillSergeant;
	UPROPERTY()						FName DrillSergeantTag;											//var name DrillSergeantTag;
	UPROPERTY()						AFSTS_NPC_DrillSergeant* DrillSergeant;							//var FSTS_NPC_DrillSergeant DrillSergeant;


};
