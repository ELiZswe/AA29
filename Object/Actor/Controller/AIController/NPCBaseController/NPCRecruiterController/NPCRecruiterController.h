// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "NPCRecruiterController.generated.h"

UCLASS()
class ANPCRecruiterController : public ANPCBaseController
{
	GENERATED_BODY()
public:
	ANPCRecruiterController();

	UPROPERTY()			TArray<FName>	anameUserActivatedAudio;			//var TArray<FName> anameUserActivatedAudio;
	UPROPERTY()			FName			nameUserLeavingAudio;				//var FName nameUserLeavingAudio;
	UPROPERTY()			float			Volume;								//var float Volume;
	UPROPERTY()			float			Radius;								//var float Radius;
	UPROPERTY()			float			Pitch;								//var float Pitch;
	UPROPERTY()			float			fpPlayerDetectionRange;				//var float fpPlayerDetectionRange;
	UPROPERTY()			bool			bLockPlayerDuringSpeech;			//var bool bLockPlayerDuringSpeech;
	UPROPERTY()			int32			iAudioIndex;						//var int32 iAudioIndex;
	UPROPERTY()			APawn*			pawnPlayerRequestingInformation;	//var Pawn pawnPlayerRequestingInformation;

	void PostBeginPlay();
	void NotifyPlayerPawnSeen(APawn* Seen);
	void NotifyPlayerPawnWatchingMe(APawn* pawnSeen);
	void Timer();
	bool UsedBy(APawn* User);
};
