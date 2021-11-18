// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/FSTS_EventLab/EL_VehicleTraining/EL_VehicleTraining.h"
#include "EL_VehicleTraining_Gunner.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AEL_VehicleTraining_Gunner : public AEL_VehicleTraining
{
	GENERATED_BODY()
public:
	AEL_VehicleTraining_Gunner();


	UPROPERTY()						bool TargetInfos;											//var TargetInfo TargetInfos;
	UPROPERTY()						bool EntryPoint;											//var PathNode EntryPoint;
	UPROPERTY()						bool bHovering;											//var bool bHovering;
	UPROPERTY()						bool HoverTimeToShowHint;											//var float HoverTimeToShowHint;
	UPROPERTY()						bool TargetStartTime;											//var float TargetStartTime;
	UPROPERTY()						bool MovieMessage;											//var string MovieMessage;
	UPROPERTY()						bool bTalkedToFrank;											//var bool bTalkedToFrank;
	UPROPERTY()						bool UseInstructorHint;											//var FSTS_PlayerHint UseInstructorHint;
	UPROPERTY()						bool FireHint;											//var FSTS_PlayerHint FireHint;
	UPROPERTY()						bool LaserHint;											//var FSTS_PlayerHint LaserHint;
	UPROPERTY()						bool ZoomHint;											//var FSTS_PlayerHint ZoomHint;
	UPROPERTY()						bool ActivateCROWSHint;											//var FSTS_PlayerHint ActivateCROWSHint;
	UPROPERTY()						bool UseTheSeatbeltHint;											//var FSTS_PlayerHint UseTheSeatbeltHint;
	UPROPERTY()						bool EnterTheVehicleHint;											//var FSTS_PlayerHint EnterTheVehicleHint;
	UPROPERTY()						bool MovieHeight;											//var float MovieHeight;
	UPROPERTY()						bool MovieWidth;											//var float MovieWidth;
	UPROPERTY()						bool Movie;											//var MovieTexture Movie;
	UPROPERTY()						bool LastWarningTime;											//var float LastWarningTime;
	UPROPERTY()						bool WarningNumber;											//var int WarningNumber;
	UPROPERTY()						bool RangeBoundsPerp;											//var FVector RangeBoundsPerp;
	UPROPERTY()						bool RangeBounds;											//var FVector RangeBounds;
	UPROPERTY()						bool RangeStart;											//var FVector RangeStart;
	UPROPERTY()						bool bPointingAtRange;											//var bool bPointingAtRange;
	UPROPERTY()						bool bCheckAim;											//var bool bCheckAim;
	UPROPERTY()						bool finalScore;											//var int finalScore;
	UPROPERTY()						bool lastCommentMade;											//var float lastCommentMade;
	UPROPERTY()						bool ShotsFired;											//var int ShotsFired;
	UPROPERTY()						bool tower;											//var Actor tower;
	UPROPERTY()						bool TrainingVehicle;											//var CROWS_HMMWV_Gunner TrainingVehicle;
	UPROPERTY()						bool MobileTargetManager;											//var AGP_Gameplay.TargetManager MobileTargetManager;
	UPROPERTY()						bool StationaryTargetManager;											//var AGP_Gameplay.TargetManager StationaryTargetManager;
	UPROPERTY()						bool bPlayerInCrows;											//var bool bPlayerInCrows;


};
