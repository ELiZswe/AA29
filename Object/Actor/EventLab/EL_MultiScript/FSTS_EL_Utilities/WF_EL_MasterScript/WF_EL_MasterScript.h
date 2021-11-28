// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"
#include "WF_EL_MasterScript.generated.h"

/**
 * 
 */
class AWF_EL_ExplosiveWeaponsRange;
class AWF_EL_M249RangeStation;
class AWF_EL_M9RangeStation;
class WF_EL_MasterScript;

UCLASS()
class AA29_API AWF_EL_MasterScript : public AFSTS_EL_Utilities
{
	GENERATED_BODY()
public:
	AWF_EL_MasterScript();


	UPROPERTY()						FString MissionLocation;									//var localized string MissionLocation;
	UPROPERTY()						FString MissionTitle;										//var localized string MissionTitle;
	//UPROPERTY()						AWF_HudOverlay* QualificationHUDOverlay;				//var WF_HudOverlay QualificationHUDOverlay;
	UPROPERTY()						FName StationTargetManagerTag;								//var name StationTargetManagerTag;
	//UPROPERTY()						ATargetManager* StationTargetManager;					//var AGP_Gameplay.TargetManager StationTargetManager;
	UPROPERTY()						AActor* Station1_Start;										//var Actor Station1_Start;
	UPROPERTY()						bool bNoGoRestart;											//var bool bNoGoRestart;
	UPROPERTY()						bool bSkipIntro;											//var bool bSkipIntro;
	UPROPERTY(Config)				bool bWFMasterIntroHeard;									//var config bool bWFMasterIntroHeard;
	UPROPERTY()						bool bFriendlyFireFailure;									//var bool bFriendlyFireFailure;
	UPROPERTY()						AWF_EL_ExplosiveWeaponsRange* Station3;						//var WF_EL_ExplosiveWeaponsRangeStation Station3;
	UPROPERTY()						AWF_EL_M249RangeStation* Station2;							//var WF_EL_M249RangeStation Station2;
	UPROPERTY()						AWF_EL_M9RangeStation* Station1;							//var WF_EL_M9RangeStation Station1;
	UPROPERTY()						AWF_EL_MasterScript* WFMasterScript;						//var WF_EL_MasterScript WFMasterScript;

};
