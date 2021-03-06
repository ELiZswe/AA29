// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AA29/MyEnums.h"
#include "SequenceTrigger.generated.h"

class ASequenceManager;

UCLASS()
class ASequenceTrigger : public ATrigger
{
	GENERATED_BODY()
public:
	ASequenceTrigger();

	UPROPERTY(EditAnywhere)				ASequenceTrigger*	nextInList;					//var ASequenceTrigger* nextInList;
	UPROPERTY(EditAnywhere)				FName				Event_Start;				//var() FName Event_Start;
	UPROPERTY(EditAnywhere)				FName				Event_Finish;				//var() FName Event_Finish;
	UPROPERTY(EditAnywhere)				FName				Event_OutOfOrder;			//var() FName Event_OutOfOrder;
	UPROPERTY(EditAnywhere)				FName				Event_InOrder;				//var() FName Event_InOrder;
	UPROPERTY(EditAnywhere)				bool				bStart;						//var() bool bStart;
	UPROPERTY(EditAnywhere)				bool				bFinish;					//var() bool bFinish;
	UPROPERTY(EditAnywhere)				int32				SequenceNumber;				//var() int32 SequenceNumber;
	UPROPERTY(EditAnywhere)				int32				Sequence_Next;				//var() int32 Sequence_Next;
	UPROPERTY(EditAnywhere)				bool				bUseManagerFlags;			//var() bool bUseManagerFlags;
	UPROPERTY(EditAnywhere)				bool				bFlag_ResetWhenOutOfOrder;	//var() bool bFlag_ResetWhenOutOfOrder;
	UPROPERTY(EditAnywhere)				bool				bFlag_ResetWhenFinished;	//var() bool bFlag_ResetWhenFinished;
	UPROPERTY(EditAnywhere)				bool				bFlag_TurnOffWhenFinished;	//var() bool bFlag_TurnOffWhenFinished;
	UPROPERTY()							bool				bActive;					//var bool bActive;
	UPROPERTY()							ASequenceManager*	my_manager;					//var ASequenceManager* my_manager;
	UPROPERTY()							bool				bOutOfOrder;				//var bool bOutOfOrder;
	UPROPERTY()							bool				bCurrent;					//var bool bCurrent;

	void PostBeginPlay();
	void ResetTrigger();
	void doFinish();
	void doOutOfOrder();
	bool exist(FName N);
	void DoTouch(AActor* Other);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void Activate();
	void Deactivate();
	void SetManager(ASequenceManager* new_manager);
	void ReportToManager(ESequenceStep Step, APawn* Instigator);
};
