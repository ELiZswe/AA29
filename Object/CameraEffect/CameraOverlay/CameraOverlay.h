// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/CameraEffect/CameraEffect.h"
#include "CameraOverlay.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCameraOverlay : public UCameraEffect
{
	GENERATED_BODY()
	
public:
	UCameraOverlay();

	UPROPERTY()													UMaterial*						OverlayMaterial;					//var() Material OverlayMaterial;
	UPROPERTY()													FColor							OverlayColor;						//var() Object.Color OverlayColor;
};
