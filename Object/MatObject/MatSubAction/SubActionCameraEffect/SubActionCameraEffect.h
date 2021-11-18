// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "SubActionCameraEffect.generated.h"

//class ACameraEffect;

UCLASS()
class AA29_API USubActionCameraEffect : public UMatSubAction
{
	GENERATED_BODY()
public:
	USubActionCameraEffect();

	UPROPERTY(EditAnywhere)										bool DisableAfterDuration;									//var() bool DisableAfterDuration;
	UPROPERTY(EditAnywhere)										float EndAlpha;								//var() float EndAlpha;
	UPROPERTY(EditAnywhere)										float StartAlpha;								//var() float StartAlpha;
	//UPROPERTY(EditAnywhere)										ACameraEffect* CameraEffect;						//var() CameraEffect CameraEffect;
};
