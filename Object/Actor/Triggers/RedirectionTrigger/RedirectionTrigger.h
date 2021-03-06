// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "RedirectionTrigger.generated.h"

UCLASS()
class ARedirectionTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	ARedirectionTrigger();
	
	UPROPERTY(EditAnywhere)				FName				RedirectionEvent;			//var() FName RedirectionEvent;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
