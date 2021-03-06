// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "ESSTrigger.generated.h"

UCLASS()
class AESSTrigger : public ATrigger
{
	GENERATED_BODY()
public:
	AESSTrigger();
	
	UPROPERTY()		USoundBase* sndBoomBoom;			//var Sound sndBoomBoom;

	void Reset();
	void DoTouch(AActor* Other);
};
