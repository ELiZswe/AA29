// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EventLab.h"
#include "FSTS_EventLab.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_EventLab : public AEventLab
{
	GENERATED_BODY()
public:
	AFSTS_EventLab();

	UPROPERTY()						bool bFadeMoveFromDrillSergeantUse;											//var bool bFadeMoveFromDrillSergeantUse;
	UPROPERTY()						bool bStartFromDrillSergeantUse;											//var bool bStartFromDrillSergeantUse;
	UPROPERTY()						bool bAcceptDrillSergeantUse;											//var bool bAcceptDrillSergeantUse;
	UPROPERTY()						bool StationBeginPointTag;											//var name StationBeginPointTag;
	UPROPERTY()						bool bFadeMoveActive;											//var bool bFadeMoveActive;
	UPROPERTY()						bool FadeMoveInfo;											//var FadeMoveInfoStruct FadeMoveInfo;
	UPROPERTY()						bool AltDrillSergeantTag;											//var name AltDrillSergeantTag;
	UPROPERTY()						bool AltDrillSergeant;											//var FSTS_NPC_DrillSergeant AltDrillSergeant;
	UPROPERTY()						bool DrillSergeantTag;											//var name DrillSergeantTag;
	UPROPERTY()						bool DrillSergeant;											//var FSTS_NPC_DrillSergeant DrillSergeant;
	UPROPERTY()						bool ActiveHint;											//var int ActiveHint;
	UPROPERTY()						bool HintQueue;											//var array<FSTS_PlayerHint> HintQueue;
};
