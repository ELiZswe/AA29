// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"
#include "ET_EL_RopeBridges.generated.h"

class AAGP_UseTrigger;
class ATriggeredPlayerBlockingVolume;

UCLASS()
class AA29_API AET_EL_RopeBridges : public AET_EL_MasterScript
{
	GENERATED_BODY()
public:
	AET_EL_RopeBridges();

	UPROPERTY()						FString StationNameMsg;										//var localized string StationNameMsg;
	UPROPERTY()						FString StationMsg;											//var localized string StationMsg;
	UPROPERTY()						FString MoveMsg;											//var localized string MoveMsg;
	UPROPERTY()						FString MountThreeRopeBridgeMsg;							//var localized string MountThreeRopeBridgeMsg;
	UPROPERTY()						FString MountOneRopeBridgeMsg;								//var localized string MountOneRopeBridgeMsg;
	UPROPERTY()						FString EndThreeRopeBridgeMsg;								//var localized string EndThreeRopeBridgeMsg;
	UPROPERTY()						FString MoveForwardMsg;										//var localized string MoveForwardMsg;
	UPROPERTY()						FString EndOneRopeBridgeMsg;								//var localized string EndOneRopeBridgeMsg;
	UPROPERTY()						FString CommandoCrawlMsg;									//var localized string CommandoCrawlMsg;
	UPROPERTY()						FString EndTwoRopeBridgeMsg;								//var localized string EndTwoRopeBridgeMsg;
	UPROPERTY()						FString StrafeMsg;											//var localized string StrafeMsg;
	UPROPERTY()						FString MountTwoRopeBridgeMsg;								//var localized string MountTwoRopeBridgeMsg;
	UPROPERTY()						FString ActionMsg;											//var localized string ActionMsg;
	UPROPERTY()						AAGP_UseTrigger* Rope3EntryTrigger;							//var AGP.AGP_UseTrigger Rope3EntryTrigger;
	UPROPERTY()						AAGP_UseTrigger* Rope2EntryTrigger;							//var AGP.AGP_UseTrigger Rope2EntryTrigger;
	UPROPERTY()						AAGP_UseTrigger* Rope1EntryTrigger;							//var AGP.AGP_UseTrigger Rope1EntryTrigger;
	UPROPERTY()						AActor* Rope3Start;											//var Actor Rope3Start;
	UPROPERTY()						AActor* Rope2Start;											//var Actor Rope2Start;
	UPROPERTY()						AActor* Rope1Start;											//var Actor Rope1Start;
	UPROPERTY()						ATriggeredPlayerBlockingVolume* HighTowerBlockingVolume;	//var TriggeredPlayerBlockingVolume HighTowerBlockingVolume;
	UPROPERTY()						ATriggeredPlayerBlockingVolume* LowTowerBlockingVolume;		//var TriggeredPlayerBlockingVolume LowTowerBlockingVolume;

	void Reset();
	void PostBeginPlay();
	void DoReferenceLinking();
};
