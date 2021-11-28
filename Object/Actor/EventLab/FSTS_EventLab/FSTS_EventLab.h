// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "FSTS_EventLab.generated.h"

class UFSTS_PlayerHint;
class AFSTS_NPC_DrillSergeant;

UCLASS()
class AA29_API AFSTS_EventLab : public AEventLab
{
	GENERATED_BODY()
public:
	AFSTS_EventLab();

	UPROPERTY()						TArray<UFSTS_PlayerHint*>	HintQueue;								//var TArray<FSTS_PlayerHint> HintQueue;
	UPROPERTY()						int32						ActiveHint;								//var int32 ActiveHint;
	UPROPERTY()						AFSTS_NPC_DrillSergeant*	DrillSergeant;							//var FSTS_NPC_DrillSergeant DrillSergeant;
	UPROPERTY()						FName						DrillSergeantTag;						//var FName DrillSergeantTag;
	UPROPERTY()						AFSTS_NPC_DrillSergeant*	AltDrillSergeant;						//var FSTS_NPC_DrillSergeant AltDrillSergeant;
	UPROPERTY()						FName						AltDrillSergeantTag;					//var FName AltDrillSergeantTag;
	UPROPERTY()						FFadeMoveInfoStruct			FadeMoveInfo;							//var FadeMoveInfoStruct FadeMoveInfo;
	UPROPERTY()						bool						bFadeMoveActive;						//var bool bFadeMoveActive;
	UPROPERTY()						FName						StationBeginPointTag;					//var FName StationBeginPointTag;
	UPROPERTY()						bool						bAcceptDrillSergeantUse;				//var bool bAcceptDrillSergeantUse;
	UPROPERTY()						bool						bStartFromDrillSergeantUse;				//var bool bStartFromDrillSergeantUse;
	UPROPERTY()						bool						bFadeMoveFromDrillSergeantUse;			//var bool bFadeMoveFromDrillSergeantUse;

	void QueueHint(UFSTS_PlayerHint* Hint);
	void RemoveHint(UFSTS_PlayerHint* Hint);
	void RemoveAllHints();
	void EventLabTick(float DeltaTime);
	void LinkDrillSergeants();
	void DrillSergeantUsed(AAGP_Character* Sarge);
	void SetDrillSergeantParams(bool bAcceptDSUse, bool bStartFromDSUse, bool bFadeMoveOnDSUse);
	void FadeMoveStart(AActor* PlayerMovePoint, AFSTS_EventLab* CallBackScript);
	void FadeMoveMiddle();
	void FadeMoveEnd();
	void NotifyDrillSergeantUsed();
	void NotifyFadeMoveStart(FName PlayerMoveName);
	void NotifyFadeMoveMiddle(FName PlayerMoveName);
	void NotifyFadeMoveEnd(FName PlayerMoveName);
};
