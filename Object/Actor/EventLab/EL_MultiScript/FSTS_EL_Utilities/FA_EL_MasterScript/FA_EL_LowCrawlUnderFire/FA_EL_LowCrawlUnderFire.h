// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "FA_EL_LowCrawlUnderFire.generated.h"

class AVolume;
class AM249MuzzleFlash;

UCLASS()
class AA29_API AFA_EL_LowCrawlUnderFire : public AFA_EL_MasterScript
{
	GENERATED_BODY()
public:
	AFA_EL_LowCrawlUnderFire();

	UPROPERTY()						ESmokeGrenadeStatus SmokeGrenadeStatus;					//var ESmokeGrenadeStatus SmokeGrenadeStatus;
	UPROPERTY()						AVolume* GrenadeExplodeVolume;							//var Volume GrenadeExplodeVolume;
	UPROPERTY()						uint8 BurstNum;											//var byte BurstNum;
	UPROPERTY()						AM249MuzzleFlash* FlashEmitter;							//var AGP_Effects.M249MuzzleFlash FlashEmitter;
	UPROPERTY()						AActor* SmokeSpawnActor;								//var Actor SmokeSpawnActor;
	UPROPERTY()						bool bPlayerStoodUp;									//var bool bPlayerStoodUp;
	UPROPERTY()						bool bBadSmokeGrenadeThrow;								//var bool bBadSmokeGrenadeThrow;
	UPROPERTY()						bool bPlayerWaitedTooLong;								//var bool bPlayerWaitedTooLong;
	UPROPERTY()						bool bInFiringMode;										//var bool bInFiringMode;
	UPROPERTY()						bool bRandomFire;										//var bool bRandomFire;
	UPROPERTY()						bool bPlayerReachedFirstBoulder;						//var bool bPlayerReachedFirstBoulder;
	UPROPERTY()						bool bFirstProneEvent;									//var bool bFirstProneEvent;
	UPROPERTY()						bool bWaitingForStation2_1Finish;						//var bool bWaitingForStation2_1Finish;
	UPROPERTY()						bool bNoGoMessageStarted;								//var bool bNoGoMessageStarted;
	UPROPERTY()						bool bPlayerNoGo;										//var bool bPlayerNoGo;
	UPROPERTY()						bool bPlayerMustBeProne;								//var bool bPlayerMustBeProne;

	void PostBeginPlay();
	void PostPostInit();
	void DoReferenceLinking();
	void AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant);
	void RemoveGrenadeFromInventory();
	void Reset();
	void FFDrillSergeantScold();
	void DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant);
	void PlayFire();
	void QueueFiring(int32 BurstLength);
};
