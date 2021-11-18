// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/FSTS_EventLab/FSTS_EventLab.h"
#include "EL_VehicleTraining.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AEL_VehicleTraining : public AFSTS_EventLab
{
	GENERATED_BODY()
public:
	AEL_VehicleTraining();

	UPROPERTY()						bool TargetIDs;											//var array<Actor> TargetIDs;
	UPROPERTY()						bool LipSyncDebugs;											//var array<LipSyncDebug> LipSyncDebugs;
	UPROPERTY()						bool LipSyncs;											//var array<lipsync> LipSyncs;
	UPROPERTY()						bool ActionHintString4;											//var localized string ActionHintString4;
	UPROPERTY()						bool ActionHintString3;											//var localized string ActionHintString3;
	UPROPERTY()						bool ActionHintString2;											//var localized string ActionHintString2;
	UPROPERTY()						bool ActionHintString1;											//var localized string ActionHintString1;
	UPROPERTY()						bool GunnerPosition;											//var int GunnerPosition;
	UPROPERTY()						bool PassengerPosition;											//var int PassengerPosition;
	UPROPERTY()						bool DriverPosition;											//var int DriverPosition;
	UPROPERTY()						bool Vehicle;											//var AGP_Vehicles.AGP_Vehicle Vehicle;
	UPROPERTY()						bool Sgt;											//var AGP_Vehicles.AGP_VehicleBot Sgt;
	UPROPERTY()						bool InitialStateName;											//var name InitialStateName;
};
