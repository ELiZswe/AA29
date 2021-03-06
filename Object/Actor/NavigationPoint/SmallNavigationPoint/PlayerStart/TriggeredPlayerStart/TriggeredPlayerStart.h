// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "TriggeredPlayerStart.generated.h"

UCLASS()
class ATriggeredPlayerStart : public APlayerStart
{
	GENERATED_BODY()
public:
	ATriggeredPlayerStart(const FObjectInitializer& ObjectInitializer);

	void Trigger(AActor* Other, APawn* EventInstigator);
};
