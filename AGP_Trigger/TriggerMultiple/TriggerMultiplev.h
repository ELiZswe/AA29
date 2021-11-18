// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "AA29/AA29.h"
#include "TriggerMultiplev.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATriggerMultiplev : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	ATriggerMultiplev();

	UPROPERTY()									bool bDebug;							//var bool bDebug;
	UPROPERTY()									int32 SequenceCounter;					//var int SequenceCounter;
	UPROPERTY()									bool bHasBeenTriggered;					//var bool bHasBeenTriggered;
	UPROPERTY()									APawn* GlobalInstigator;				//var Pawn GlobalInstigator;
	//UPROPERTY()								FName mT;								//var MultiTimer mT;
	UPROPERTY(EditAnywhere)						bool bInterruptible;					//var() bool bInterruptible;
	UPROPERTY(EditAnywhere)						bool bResetEachRound;					//var() bool bResetEachRound;
	UPROPERTY(EditAnywhere)						int32 StartIndex;						//var() int StartIndex;
	UPROPERTY(EditAnywhere)						bool bTriggerOnce;						//var() bool bTriggerOnce;
	UPROPERTY(EditAnywhere)						float GlobalDelay;						//var() float GlobalDelay;
	UPROPERTY(EditAnywhere)						TArray<FEventParms> EventList;			//var() array<EventParms> EventList;
	UPROPERTY(EditAnywhere)						ETriggerTriggerType TriggerType;		//var() ETriggerType TriggerType;

	void PreBeginPlay();
	void MatchStarting();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void Timer();
	void StandardEvent();
	void RandomEvent();
	void SequenceEvent();
	void StartEvent(int32 Index);
	//void TimerNotify(FName TimerName, MultiTimer Timer);
	void DestroyMT();
	void Destroyed();

};
