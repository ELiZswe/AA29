// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Light/AA2_Light.h"
#include "TriggerLight.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATriggerLight : public AAA2_Light
{
	GENERATED_BODY()
public:
	ATriggerLight();

	UPROPERTY()										float poundTime;						//var float poundTime;
	UPROPERTY()										AActor* SavedTrigger;					//var Actor SavedTrigger;
	UPROPERTY()										float Direction;						//var float Direction;
	UPROPERTY()										float Alpha;							//var float Alpha;
	UPROPERTY()										float InitialBrightness;				//var float InitialBrightness;
	UPROPERTY(EditAnywhere)							float RemainOnTime;						//var() float RemainOnTime;
	UPROPERTY(EditAnywhere)							bool bDelayFullOn;						//var() bool bDelayFullOn;
	UPROPERTY(EditAnywhere)							bool bInitiallyOn;						//var() bool bInitiallyOn;
	UPROPERTY(EditAnywhere)							float ChangeTime;						//var() float ChangeTime;

	void BeginPlay();
	void Tick(float DeltaTime);

};
