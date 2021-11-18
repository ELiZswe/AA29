// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Light/AA2_Light.h"
#include "TriggerCorona.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATriggerCorona : public AAA2_Light
{
	GENERATED_BODY()
public:
	ATriggerCorona();

	UPROPERTY()										bool bCoronaStartsOn;						//var() bool bCoronaStartsOn;

	void PreBeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void ToggleCorona();
	void MatchStarting();

};
