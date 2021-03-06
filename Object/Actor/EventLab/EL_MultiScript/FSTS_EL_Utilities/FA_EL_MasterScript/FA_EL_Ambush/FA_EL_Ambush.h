// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "FA_EL_Ambush.generated.h"

class AFSTS_Shot_Detection_Volume;

class AFSTS_NPC_DrillSergeant;
UCLASS()
class AFA_EL_Ambush : public AFA_EL_MasterScript
{
	GENERATED_BODY()
public:
	AFA_EL_Ambush();

	UPROPERTY()						AFSTS_Shot_Detection_Volume* WrongHitArea;					//var FSTS_Shot_Detection_Volume WrongHitArea;
	UPROPERTY()						AFSTS_Shot_Detection_Volume* CorrectHitArea;				//var FSTS_Shot_Detection_Volume CorrectHitArea;
	UPROPERTY()						bool bEnemySuppressed;										//var bool bEnemySuppressed;
	UPROPERTY()						bool bPlayingOtherWayMsg;									//var bool bPlayingOtherWayMsg;
	UPROPERTY()						bool bDetectShotVolumeHits;									//var bool bDetectShotVolumeHits;
	UPROPERTY()						int32 HitsOnShotVolume;										//var int HitsOnShotVolume;
	UPROPERTY()						bool bWaitingForStation4_1Finish;							//var bool bWaitingForStation4_1Finish;
	UPROPERTY()						bool bFirstProneEvent;										//var bool bFirstProneEvent;
	UPROPERTY()						bool bNoGoMessageStarted;									//var bool bNoGoMessageStarted;
	UPROPERTY()						bool bPlayerNoGo;											//var bool bPlayerNoGo;
	UPROPERTY()						bool bPlayerMustBeProne;									//var bool bPlayerMustBeProne;

	void PostBeginPlay();
	void DoReferenceLinking();
	void AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant);
	void PlayerHit();
	void Reset();
	void FFDrillSergeantScold();
	void DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant);
	void SpawnFlashEffectStuff();
	void Register_Volume_Hit(AFSTS_Shot_Detection_Volume* HitVolume);
};
