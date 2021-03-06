// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "TriggerProjector.generated.h"

UCLASS()
class ATriggerProjector : public AProjector
{
	GENERATED_BODY()
public:
	ATriggerProjector();

	UPROPERTY(EditAnywhere)				bool bStartOn;				//var() bool bStartOn;
	UPROPERTY(EditAnywhere)				bool bOnceOnly;				//var() bool bOnceOnly;
	UPROPERTY()							bool bIsOn;					//var bool bIsOn;
	UPROPERTY()							bool bTriggeredOnce;		//var bool bTriggeredOnce;

	void BeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void TurnOn();
	void TurnOff();
};
