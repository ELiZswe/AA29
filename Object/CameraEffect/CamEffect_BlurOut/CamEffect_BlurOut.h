// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/CameraEffect/CameraEffect.h"
#include "CamEffect_BlurOut.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCamEffect_BlurOut : public UCameraEffect
{
	GENERATED_BODY()
public:
	UCamEffect_BlurOut();

	UPROPERTY()											bool							GBObject;						//var transient GaussianBlur GBObject;
	UPROPERTY()											float							LastPostRenderTime;				//var float LastPostRenderTime;
	UPROPERTY()											int32							MaxBlurTexels;					//var int MaxBlurTexels;
	UPROPERTY()											float							Duration;						//var float Duration;
	UPROPERTY()											float							StartTime;						//var float StartTime;
	UPROPERTY()											float							TimeLeft;						//var float TimeLeft;

	void BeginBlur(float Duration, int32 MaxBlurPixels, APlayerController* PC);
	void EndBlur(APlayerController* PC);
};
