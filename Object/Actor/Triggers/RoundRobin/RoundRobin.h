// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "RoundRobin.generated.h"

UCLASS()
class ARoundRobin : public ATriggers
{
	GENERATED_BODY()
public:
	ARoundRobin();

	UPROPERTY(EditAnywhere)				TArray<FName>		OutEvents;		//var() FName OutEvents[16];
	UPROPERTY(EditAnywhere)				bool				bLoop;			//var() bool bLoop;
	UPROPERTY()							int32				i;				//var int32 i;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
