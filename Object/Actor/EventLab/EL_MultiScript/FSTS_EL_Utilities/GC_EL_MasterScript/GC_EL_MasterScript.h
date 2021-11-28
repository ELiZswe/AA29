// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"
#include "GC_EL_MasterScript.generated.h"

class AGC_EL_VehicleThrow;
class AGC_EL_TrenchThrow;
class AGC_EL_ProneThrow;
class AGC_EL_MortarThrow;
class AGC_EL_BunkerThrow;
class AGC_EL_FightingPositionThrow;
class AGC_EL_StagingArea;
class AGC_EL_LiveThrowArea;

UCLASS()
class AA29_API AGC_EL_MasterScript : public AFSTS_EL_Utilities
{
	GENERATED_BODY()
public:
	AGC_EL_MasterScript();

	UPROPERTY()						FString GoToNextStationString;								//var string GoToNextStationString;
	UPROPERTY()						FString PlayerFailedStatioNString;							//var string PlayerFailedStatioNString;
	UPROPERTY()						FString PlayerPassedStationString;							//var string PlayerPassedStationString;
	UPROPERTY()						bool bAllowGrenade;											//var bool bAllowGrenade;
	UPROPERTY()						AGC_EL_VehicleThrow* Station6;								//var GC_EL_VehicleThrow Station6;
	UPROPERTY()						AGC_EL_TrenchThrow* Station5;								//var GC_EL_TrenchThrow Station5;
	UPROPERTY()						AGC_EL_ProneThrow* Station4;								//var GC_EL_ProneThrow Station4;
	UPROPERTY()						AGC_EL_MortarThrow* Station3;								//var GC_EL_MortarThrow Station3;
	UPROPERTY()						AGC_EL_BunkerThrow* Station2;								//var GC_EL_BunkerThrow Station2;
	UPROPERTY()						AGC_EL_FightingPositionThrow* Station1;						//var GC_EL_FightingPositionThrow Station1;
	UPROPERTY()						AGC_EL_StagingArea* ConfidenceStagingArea;					//var GC_EL_StagingArea ConfidenceStagingArea;
	UPROPERTY()						AGC_EL_LiveThrowArea* LiveThrowArea;						//var GC_EL_LiveThrowArea LiveThrowArea;
	UPROPERTY()						AGC_EL_MasterScript* GCMasterScript;						//var GC_EL_MasterScript GCMasterScript;
};
