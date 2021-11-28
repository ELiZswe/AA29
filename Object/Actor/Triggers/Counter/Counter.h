// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "Counter.generated.h"

UCLASS()
class AA29_API ACounter : public ATriggers
{
	GENERATED_BODY()
public:
	ACounter();

	UPROPERTY(EditAnywhere)			uint8					NumToCount;				//var() uint8 NumToCount;
	UPROPERTY(EditAnywhere)			bool					bShowMessage;			//var() bool bShowMessage;
	UPROPERTY(EditAnywhere)			FString					CountMessage;			//var() localized FString CountMessage;
	UPROPERTY(EditAnywhere)			FString					CompleteMessage;		//var() localized FString CompleteMessage;
	UPROPERTY()						uint8					OriginalNum;			//var uint8 OriginalNum;

	void BeginPlay();
	void Reset();
	void Trigger(AActor* Other, APawn* EventInstigator);
};
