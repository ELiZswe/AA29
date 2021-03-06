// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "TimedTrigger.generated.h"

UCLASS()
class ATimedTrigger : public ATrigger
{
	GENERATED_BODY()
public:
	ATimedTrigger();

	UPROPERTY(EditAnywhere)							float DelaySeconds;					//var() float DelaySeconds;
	UPROPERTY(EditAnywhere)							bool bRepeating;					//var() bool bRepeating;

	void Timer();
	void MatchStarting();
};
