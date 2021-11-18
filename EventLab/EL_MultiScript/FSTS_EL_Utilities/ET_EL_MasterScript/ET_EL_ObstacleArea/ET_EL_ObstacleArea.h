// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"
#include "ET_EL_ObstacleArea.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AET_EL_ObstacleArea : public AET_EL_MasterScript
{
	GENERATED_BODY()
public:
	AET_EL_ObstacleArea();


	UPROPERTY(Config)				bool bEagleTowerMasterIntroHeard;				//var config bool bEagleTowerMasterIntroHeard;
	UPROPERTY()						FString OutOfBoundsMsg;							//var localized string OutOfBoundsMsg;
	UPROPERTY()						FString StationNameMsg;							//var localized string StationNameMsg;
	UPROPERTY()						FString StationMsg;								//var localized string StationMsg;
	UPROPERTY()						FString MoveMsg;								//var localized string MoveMsg;
	UPROPERTY()						FString StrafeMsg;								//var localized string StrafeMsg;
	UPROPERTY()						FString ClimbMsg;								//var localized string ClimbMsg;
	UPROPERTY()						FString StandingFromCrawlingMsg;				//var localized string StandingFromCrawlingMsg;
	UPROPERTY()						FString CrawlingMsg;							//var localized string CrawlingMsg;
	UPROPERTY()						FString JumpMsg;								//var localized string JumpMsg;
	UPROPERTY()						FString StandingFromCrouchingMsg;				//var localized string StandingFromCrouchingMsg;
	UPROPERTY()						FString CrouchingMsg;							//var localized string CrouchingMsg;
	UPROPERTY()						FString MoveForwardMsg;							//var localized string MoveForwardMsg;
};
