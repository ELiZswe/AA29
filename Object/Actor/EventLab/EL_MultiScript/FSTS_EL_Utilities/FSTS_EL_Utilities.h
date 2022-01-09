// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/EL_MultiScript.h"
#include "FSTS_EL_Utilities.generated.h"

class AFSTS_NPC_DrillSergeant;
class AFSTS_DirectionMarker;
class AFSTS_HelpMarker;
class AFSTS_LocationMarker;

class AAGP_Objective;

class ATriggeredPlayerBlockingVolume;
class AWeapon;

UCLASS()
class AFSTS_EL_Utilities : public AEL_MultiScript
{
	GENERATED_BODY()
public:
	AFSTS_EL_Utilities();

	UPROPERTY()						TArray<FHelpInfo> HelpInfoList;									//var array<HelpInfo> HelpInfoList;
	UPROPERTY()						TArray<ATriggeredPlayerBlockingVolume*> BlockingVolumes;		//var array<TriggeredPlayerBlockingVolume> BlockingVolumes;
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
	UPROPERTY()						AFSTS_DirectionMarker* DirectionMarker;							//var FSTS_DirectionMarker DirectionMarker;
	UPROPERTY()						bool bCreateDirectionMarker;									//var bool bCreateDirectionMarker;
	UPROPERTY()						AFSTS_HelpMarker* HelpMarker;									//var FSTS_HelpMarker HelpMarker;
	UPROPERTY()						bool bCreateHelpMarker;											//var bool bCreateHelpMarker;
	UPROPERTY()						AFSTS_LocationMarker* LocationMarker;							//var FSTS_LocationMarker LocationMarker;
	UPROPERTY()						bool bCreateLocationMarker;										//var bool bCreateLocationMarker;
	UPROPERTY()						FName AltDrillSergeantTag;										//var name AltDrillSergeantTag;
	UPROPERTY()						AFSTS_NPC_DrillSergeant* AltDrillSergeant;						//var FSTS_NPC_DrillSergeant AltDrillSergeant;
	UPROPERTY()						FName DrillSergeantTag;											//var name DrillSergeantTag;
	UPROPERTY()						AFSTS_NPC_DrillSergeant* DrillSergeant;							//var FSTS_NPC_DrillSergeant DrillSergeant;

	void PostInit();
	void DoReferenceLinking();
	void Destroyed();
	void Reset();
	void EventLabTick(float DeltaTime);
	void StartHelpTimer(int32 HelpIndex, bool bRepeat);
	bool SetHelpLSActor(AActor* nActor, bool bNoSetAll, int32 Index);
	void LogStationEnd(AFSTS_EL_Utilities* CompletedStation, bool bStationPassed);
	int32 GetHelpInfoListIndex(FName HelpName);
	bool HandleHelpTimerEvent(FName EventName);
	void DoHelpMessage(int32 Index);
	void StopHelpTimer(int32 HelpIndex);
	bool CheckLocationProximity(FVector DestinationLocation, FVector VariableLocation, float Radius);
	bool CheckActorProximity();
	void DetectProximityToActor(AActor* Destination, AActor* ActorToMove, float ProxyRadius, FName AlertTag);
	void CreateMarkers();
	void SetLocationMarker(AFSTS_LocationMarker* MarkerToSet, FVector NewLocation, FVector AdditionalOffset, bool bActivateNow);
	void ActivateLocationMarker(AFSTS_LocationMarker* MarkerToSet);
	void DeactivateLocationMarker(AFSTS_LocationMarker* MarkerToSet);
	void SetHelpMarker(AFSTS_HelpMarker* MarkerToSet, FVector NewLocation, FVector AdditionalOffset, bool bActivateNow, bool bUseAltStaticMesh);
	void SetHelpMarkerRotation(AFSTS_HelpMarker* MarkerToSet, FRotator NewRotation);
	void ActivateHelpMarker(AFSTS_HelpMarker* MarkerToSet);
	void DeactivateHelpMarker(AFSTS_HelpMarker* MarkerToSet);
	void ForcePlayerCrouch(bool bCrouch);
	void ForcePlayerProne(bool bProne);
	float GetPlayerProximityTo(AActor* DistanceActor);
	void FacePlayerTo(AActor* ActorToFace, FName TargetBone, FName PlayerBone);
	void LinkDrillSergeants();
	void DrillSergeantUsed(AFSTS_NPC_DrillSergeant* Sarge);
	void SetDrillSergeantParams(bool bAcceptDSUse, bool bStartFromDSUse, bool bFadeMoveOnDSUse);
	void FadeMoveStart(AActor* PlayerMovePoint, AFSTS_EL_Utilities* CallBackScript);
	void FadeMoveMiddle();
	void FadeMoveEnd();
	void NotifyDrillSergeantUsed();
	void NotifyFadeMoveStart(FName PlayerMoveName);
	void NotifyFadeMoveMiddle(FName PlayerMoveName);
	void NotifyFadeMoveEnd(FName PlayerMoveName);
	bool Pawn_Damaged(APawn* DamagedPawn, AController* InstigatorController);
	bool Pawn_Damaged_Miles(APawn* DamagedPawn, AController* InstigatorController);
	void CheatMissionComplete();
	int32 GetNumStationsPassed();
	bool AllStationsComplete();
	FString GenerateDebugMissionSummaryString();
	void MissionComplete();
	bool HandlePassResults();
	bool GenerateLevelSpecificSuccessStrings(FString& Line1, FString& Line2);
	bool GenerateLevelSpecificFailureStrings(FString& Line1, FString& Line2);
	void GenerateAuthNumStationsPassed(int32 StationsPassed);
	void SetAuthNumStationsPassed(int32 NewVal);
	FString GetTrainingMapName();
	void InitBlockingVolumesArray();
	ATriggeredPlayerBlockingVolume* GetPlayerBlockingVolume(FName SearchTag);
	void ActivatePlayerBlocking(ATriggeredPlayerBlockingVolume* VolumeToActivate);
	void DeactivatePlayerBlocking(ATriggeredPlayerBlockingVolume* VolumeToDeactivate);
	void ForceDrawPlayerCrosshair(bool bForceActive);
	void CrouchEvent();
	void CrawlEvent();
	void LMouseClickEvent();
	void ActorProximityAlert(AActor* ProximityActor, FName AlertTag);
	void CheatSkipToStation(int32 StationNum);
	void ReloadEvent(AWeapon* ReloadedWeapon);
	void StationComplete();
	void LeavingStation();
};
