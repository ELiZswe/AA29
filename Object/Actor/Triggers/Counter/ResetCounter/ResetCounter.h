// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Counter/Counter.h"
#include "ResetCounter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AResetCounter : public ACounter
{
	GENERATED_BODY()
public:
	AResetCounter();

	UPROPERTY(EditAnywhere)			bool					bResetAtRoundEnd;				//var() bool bResetAtRoundEnd;

	void Reset();
	void MatchStarting();
};
