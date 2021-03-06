// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "Dispatcher.generated.h"

UCLASS()
class ADispatcher : public ATriggers
{
	GENERATED_BODY()
public:
	ADispatcher();
	
	UPROPERTY(EditAnywhere)			TArray<FName>	OutEvents;			//var() FName OutEvents[32];
	UPROPERTY(EditAnywhere)			TArray<float>	OutDelays;			//var() float OutDelays[32];
	UPROPERTY()						int32			i;					//var int32 i;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
