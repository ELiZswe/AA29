// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/ET_EL_MasterScript/ET_EL_MasterScript.h"
#include "ET_EL_RopeRappel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AET_EL_RopeRappel : public AET_EL_MasterScript
{
	GENERATED_BODY()
public:
	AET_EL_RopeRappel();

	UPROPERTY()						FString StationNameMsg;						//var localized string StationNameMsg;
	UPROPERTY()						FString StationMsg;							//var localized string StationMsg;
	UPROPERTY()						FString MissionCompleteMsg;					//var localized string MissionCompleteMsg;
	UPROPERTY()						FString CongratulationsMsg;					//var localized string CongratulationsMsg;
	UPROPERTY()						FString MoveMsg;							//var localized string MoveMsg;
	UPROPERTY()						FString MoveBackwardMsg;					//var localized string MoveBackwardMsg;
	UPROPERTY()						FString MouseMsg;							//var localized string MouseMsg;
	UPROPERTY()						FString MoveForwardMsg;						//var localized string MoveForwardMsg;
	UPROPERTY()						FString CrawlingMsg;						//var localized string CrawlingMsg;
};
