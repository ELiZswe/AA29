// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/CameraEffect/CameraEffect.h"
#include "CameraOverlay.generated.h"

UCLASS()
class UCameraOverlay : public UCameraEffect
{
	GENERATED_BODY()
	
public:
	UCameraOverlay();

	UPROPERTY()													UMaterialInstance*						OverlayMaterial;					//var() Material OverlayMaterial;
	UPROPERTY()													FColor							OverlayColor;						//var() Object.Color OverlayColor;
};
