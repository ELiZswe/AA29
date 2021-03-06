// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "LevelChange.generated.h"

UCLASS()
class ALevelChange : public ATriggers
{
	GENERATED_BODY()
public:
	ALevelChange();
	
	UPROPERTY(EditAnywhere)				FString				URL;					//var() FString URL;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
