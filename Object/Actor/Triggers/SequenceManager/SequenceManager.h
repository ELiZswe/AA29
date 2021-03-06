// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "SequenceManager.generated.h"

class ASequenceTrigger;
class UScriptObject;

UCLASS()
class ASequenceManager : public ATriggers
{
	GENERATED_BODY()
public:
	ASequenceManager();

	UPROPERTY(EditAnywhere)				FName				SequenceTag;					//var() FName SequenceTag;
	UPROPERTY(EditAnywhere)				FName				Event_ManagerStart;				//var() FName Event_ManagerStart;
	UPROPERTY(EditAnywhere)				FName				Event_ManagerFinish;			//var() FName Event_ManagerFinish;
	UPROPERTY(EditAnywhere)				FName				Event_ManagerOutOfOrder;		//var() FName Event_ManagerOutOfOrder;
	UPROPERTY(EditAnywhere)				FName				Event_ManagerInOrder;			//var() FName Event_ManagerInOrder;
	UPROPERTY(EditAnywhere)				bool				bFlag_ResetWhenOutOfOrder;		//var() bool bFlag_ResetWhenOutOfOrder;
	UPROPERTY(EditAnywhere)				bool				bFlag_ResetWhenFinished;		//var() bool bFlag_ResetWhenFinished;
	UPROPERTY(EditAnywhere)				bool				bFlag_TurnOffWhenFinished;		//var() bool bFlag_TurnOffWhenFinished;
	UPROPERTY(EditAnywhere)				bool				bSequenceInitiallyActive;		//var() bool bSequenceInitiallyActive;
	UPROPERTY()							ASequenceTrigger*	_list;							//var ASequenceTrigger* _list;
	UPROPERTY()							UScriptObject*		_OutOfOrderMonitor;				//var UScriptObject* _OutOfOrderMonitor;
	UPROPERTY()							UScriptObject*		_InOrderMonitor;				//var UScriptObject* _InOrderMonitor;
	UPROPERTY()							UScriptObject*		_StartMonitor;					//var UScriptObject* _StartMonitor;
	UPROPERTY()							UScriptObject*		_FinishMonitor;					//var UScriptObject* _FinishMonitor;

	void PostBeginPlay();
	void EnableSequence();
	void DisableSequence();
	void SetOutOfOrderMonitor(UScriptObject* mon);
	void SetInOrderMonitor(UScriptObject* mon);
	void SetStartMonitor(UScriptObject* mon);
	void SetFinishMonitor(UScriptObject* mon);
	void SequenceStart(ASequenceTrigger* starter, APawn* Instigator);
	void SequenceFinish(ASequenceTrigger* finisher, APawn* Instigator);
	void SequenceOutOfOrder(ASequenceTrigger* outoforder, APawn* Instigator);
	void SequenceInOrder(ASequenceTrigger* outoforder, APawn* Instigator);
};
