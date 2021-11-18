// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"
#include "ET_EL_MasterScript.generated.h"


class AET_EL_RopeRappel;
class AET_EL_LadderClimb;
class AET_EL_CargoNetDescent;
class AET_EL_RopeBridges;
class AET_EL_ObstacleArea;

UCLASS()
class AA29_API AET_EL_MasterScript : public AFSTS_EL_Utilities
{
	GENERATED_BODY()
public:
	AET_EL_MasterScript();


	UPROPERTY()						bool bHaveNotMoved;											//var bool bHaveNotMoved;
	UPROPERTY()						FVector PlayerLocation;											//var FVector PlayerLocation;
	UPROPERTY()						USoundBase* BadLandingSound;											//var Sound BadLandingSound;
	UPROPERTY()						FString MissionLocation;											//var localized string MissionLocation;
	UPROPERTY()						FString MissionTitle;											//var localized string MissionTitle;
	UPROPERTY()						AET_EL_RopeRappel* Station5;											//var ET_EL_RopeRappel Station5;
	UPROPERTY()						AET_EL_LadderClimb* Station4;											//var ET_EL_LadderClimb Station4;
	UPROPERTY()						AET_EL_CargoNetDescent* Station3;											//var ET_EL_CargoNetDescent Station3;
	UPROPERTY()						AET_EL_RopeBridges* Station2;											//var ET_EL_RopeBridges Station2;
	UPROPERTY()						AET_EL_ObstacleArea* Station1;											//var ET_EL_ObstacleArea Station1;
	UPROPERTY()						AET_EL_MasterScript* ETMasterScript;											//var ET_EL_MasterScript ETMasterScript;
};
