// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/CameraEffect/CameraEffect.h"
#include "CamEffect_FlashBang.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCamEffect_FlashBang : public UCameraEffect
{
	GENERATED_BODY()
public:
	UCamEffect_FlashBang();

	void StartFlash(float Duration, float Intensity, APlayerController* PC);
	void EndFlash(APlayerController* PC);


	//native Function StartFlash(float Duration, float Intensity, PlayerController PC);
	//native Function EndFlash(PlayerController PC);
};
