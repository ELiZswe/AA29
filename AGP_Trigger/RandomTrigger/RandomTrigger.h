// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "RandomTrigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARandomTrigger : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	ARandomTrigger();

	UPROPERTY()							bool bRunning;								//var bool bRunning;
	UPROPERTY(EditAnywhere)				bool bStartOn;								//var() bool bStartOn;
	UPROPERTY(EditAnywhere)				bool bOnceOnly;								//var() bool bOnceOnly;
	UPROPERTY(EditAnywhere)				bool bTriggerControl;						//var() bool bTriggerControl;
	UPROPERTY(EditAnywhere)				float RandomMaxTime;						//var() float RandomMaxTime;
	UPROPERTY(EditAnywhere)				float RandomMinTime;						//var() float RandomMinTime;

	void BeginPlay();
	void Timer();
	void _setTimer();
	void _ClearTimer();
	void Trigger(AActor* Other, APawn* EventInstigator);

};
