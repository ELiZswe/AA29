// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Triggers/Triggers.h"
#include "AA29/AA29.h"
#include "RandomDispatcher.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARandomDispatcher : public ATriggers
{
	GENERATED_BODY()
public:
	ARandomDispatcher();

	UPROPERTY()										bool bPaused;									//var bool bPaused;
	UPROPERTY()										int32 iTotalPending;							//var int iTotalPending;
	UPROPERTY()										int32 iTotalAvailable;							//var int iTotalAvailable;
	UPROPERTY()										int32 iTotalEvents;								//var int iTotalEvents;
	UPROPERTY()										int32 iTotalTargets;							//var int iTotalTargets;
	UPROPERTY()										int32 j;										//var int j;
	UPROPERTY()										int32 i;										//var int i;
	UPROPERTY()										float fCurrentDelay;							//var float fCurrentDelay;
	UPROPERTY()										TArray<float> PendingDelay;								//var float PendingDelay;
	UPROPERTY()										FName PendingEvent;								//var name PendingEvent;
	UPROPERTY()										TArray<int32> AvailableCounter;							//var int AvailableCounter;
	UPROPERTY()										FName AvailableEvent;							//var name AvailableEvent;

	UPROPERTY(EditAnywhere)							bool bDispatchOnceOnly;							//var() bool bDispatchOnceOnly;
	UPROPERTY(EditAnywhere)							bool bDistribute;								//var() bool bDistribute;
	UPROPERTY(EditAnywhere)							TArray<FOutStruct> EventList;					//var() OutStruct EventList;
	UPROPERTY(EditAnywhere)							float fUntriggerDelay;							//var() float fUntriggerDelay;
	UPROPERTY(EditAnywhere)							float fTriggerDelay;							//var() float fTriggerDelay;

	void DispatchComplete();
	void printPend();
	void printAvail();
	void printAll();
	int32 getTarget();
	bool PendingReady();

	void doPending();
	void DoAvailable(int32 Index);
	void EnableDispatcher(bool change_once_flag, bool once);
	void Trigger(AActor* Other, APawn* EventInstigator);

	//From Actor
	//UPROPERTY()										UScriptObject* _Target;							//var ScriptObject _Target;


};
