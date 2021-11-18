// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/FSTS_EventLab/EL_VehicleTraining/EL_VehicleTraining.h"
#include "EL_VehicleTraining_Driver.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AEL_VehicleTraining_Driver : public AEL_VehicleTraining
{
	GENERATED_BODY()
public:
	AEL_VehicleTraining_Driver();

	UPROPERTY()						bool FinishObjective;											//var FSTS_Objective FinishObjective;
	UPROPERTY()						bool Checkpoint2Objective;										//var FSTS_Objective Checkpoint2Objective;
	UPROPERTY()						bool Checkpoint1Objective;										//var FSTS_Objective Checkpoint1Objective;
	UPROPERTY()						bool Checkpoint0Objective;										//var FSTS_Objective Checkpoint0Objective;
	UPROPERTY()						bool VehicleDisabledHint;										//var FSTS_PlayerHint VehicleDisabledHint;
	UPROPERTY()						bool VehicleTippingHint;										//var FSTS_PlayerHint VehicleTippingHint;
	UPROPERTY()						bool VehicleStuckHint;											//var FSTS_PlayerHint VehicleStuckHint;
	UPROPERTY()						bool SpeedRangeHint;											//var FSTS_PlayerHint SpeedRangeHint;
	UPROPERTY()						bool SteeringHint;												//var FSTS_PlayerHint SteeringHint;
	UPROPERTY()						bool MoveForwardHint;											//var FSTS_PlayerHint MoveForwardHint;
	UPROPERTY()						bool ShiftGearsHint;											//var FSTS_PlayerHint ShiftGearsHint;
	UPROPERTY()						bool LookInTheMirrorHint;										//var FSTS_PlayerHint LookInTheMirrorHint;
	UPROPERTY()						bool StartTheCarHint;											//var FSTS_PlayerHint StartTheCarHint;
	UPROPERTY()						bool UseTheSeatbeltHint;										//var FSTS_PlayerHint UseTheSeatbeltHint;
	UPROPERTY()						bool EnterTheVehicleHint;										//var FSTS_PlayerHint EnterTheVehicleHint;
	UPROPERTY()						bool UseInstructorHint;											//var FSTS_PlayerHint UseInstructorHint;
	UPROPERTY()						bool MobileGunnerVehicle;										//var Vehicle MobileGunnerVehicle;
	UPROPERTY()						bool StaticGunnerVehicle;										//var Vehicle StaticGunnerVehicle;
	UPROPERTY()						bool MobileGunnerVehicleTag;									//var() name MobileGunnerVehicleTag;
	UPROPERTY()						bool StaticGunnerVehicleTag;									//var() name StaticGunnerVehicleTag;
	UPROPERTY()						bool RestartMessage;											//var string RestartMessage;
	UPROPERTY()						bool VehicleStuckTime;											//var float VehicleStuckTime;
	UPROPERTY()						bool bPlayerInVehicle;											//var bool bPlayerInVehicle;
	UPROPERTY()						bool CheckpointString2;											//var localized string CheckpointString2;
	UPROPERTY()						bool CheckpointString1;											//var localized string CheckpointString1;
	UPROPERTY()						bool LastCheckpoint;											//var int LastCheckpoint;
	UPROPERTY()						bool NextCheckpoint;											//var int NextCheckpoint;
	UPROPERTY()						bool bShoutRandomly;											//var bool bShoutRandomly;
};
