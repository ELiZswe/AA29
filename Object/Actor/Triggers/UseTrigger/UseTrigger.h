// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "UseTrigger.generated.h"

UCLASS()
class AUseTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	AUseTrigger();
	
	UPROPERTY(EditAnywhere)			FString		Message;		//var() localized FString Message;

	bool SelfTriggered();
	bool UsedBy(APawn* User);
	void Touch(AActor* Other);
};
