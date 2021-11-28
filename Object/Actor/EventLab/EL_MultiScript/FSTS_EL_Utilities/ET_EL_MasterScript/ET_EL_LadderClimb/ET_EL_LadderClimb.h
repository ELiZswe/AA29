// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"
#include "ET_EL_LadderClimb.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AET_EL_LadderClimb : public AET_EL_MasterScript
{
	GENERATED_BODY()
public:
	AET_EL_LadderClimb();

	UPROPERTY()						FString StationNameMsg;				//var localized string StationNameMsg;
	UPROPERTY()						FString StationMsg;					//var localized string StationMsg;
	UPROPERTY()						FString MoveMsg;					//var localized string MoveMsg;
	UPROPERTY()						FString SprintMsg;					//var localized string SprintMsg;
	UPROPERTY()						FString MoveForwardMsg;				//var localized string MoveForwardMsg;
	UPROPERTY()						bool bPlayerClimbingLadder;			//var bool bPlayerClimbingLadder;
	UPROPERTY()						bool bPlayerReachedSarge;			//var bool bPlayerReachedSarge;
};
