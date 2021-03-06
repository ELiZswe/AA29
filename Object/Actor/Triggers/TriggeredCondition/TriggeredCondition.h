// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "TriggeredCondition.generated.h"

UCLASS()
class ATriggeredCondition : public ATriggers
{
	GENERATED_BODY()
public:
	ATriggeredCondition();

	UPROPERTY(EditAnywhere)				bool	bToggled;				//var() bool bToggled;
	UPROPERTY(EditAnywhere)				bool	bEnabled;				//var() bool bEnabled;
	UPROPERTY(EditAnywhere)				bool	bTriggerControlled;		//var() bool bTriggerControlled;
	UPROPERTY()							bool	bInitialValue;			//var bool bInitialValue;

	void PostBeginPlay();
	void Reset();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
};
