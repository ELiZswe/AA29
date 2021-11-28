// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "AvoidMarker.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAvoidMarker : public ATriggers
{
	GENERATED_BODY()
public:
	AAvoidMarker();

	UPROPERTY()						uint8					TeamNum;			//var uint8 TeamNum;

	void Touch(AActor* Other);
	bool RelevantTo(APawn* p);
	void StartleBots();
};
