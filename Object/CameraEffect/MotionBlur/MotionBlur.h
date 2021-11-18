// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/CameraEffect/CameraEffect.h"
#include <AA29/AA29.h>
#include "MotionBlur.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UMotionBlur : public UCameraEffect
{
	GENERATED_BODY()
public:
	UMotionBlur();

	UPROPERTY()													float							LastFrameTime;					//var const float LastFrameTime;
	UPROPERTY()													Fpointer						RenderTargets;					//var const transient pointer RenderTargets;
	UPROPERTY()													uint8							BlurAlpha;						//var() byte BlurAlpha;
};
