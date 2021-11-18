// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"
#include "ET_EL_CargoNetDescent.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AET_EL_CargoNetDescent : public AET_EL_MasterScript
{
	GENERATED_BODY()
public:
	AET_EL_CargoNetDescent();
	
	UPROPERTY()						FString StationNameMsg;					//var localized string StationNameMsg;
	UPROPERTY()						FString StationMsg;						//var localized string StationMsg;
	UPROPERTY()						FString MoveMsg;						//var localized string MoveMsg;
	UPROPERTY()						FString SprintMsg;						//var localized string SprintMsg;
	UPROPERTY()						FString MoveBackwardMsg;				//var localized string MoveBackwardMsg;
	UPROPERTY()						FString MouseMsg;						//var localized string MouseMsg;
	UPROPERTY()						FString MoveIntoPositionMsg;			//var localized string MoveIntoPositionMsg;
	UPROPERTY()						bool bEnteredLadder;					//var bool bEnteredLadder;

};
