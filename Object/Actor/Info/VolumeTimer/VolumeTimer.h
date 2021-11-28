// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "VolumeTimer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AVolumeTimer : public AAA2_Info
{
	GENERATED_BODY()
public:
	AVolumeTimer();

	UPROPERTY()			float TimerFrequency;			//var float TimerFrequency;
	UPROPERTY()			AActor* A;						//var Actor A;

	void PostBeginPlay();
	void Timer();

};
