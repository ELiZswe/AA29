// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HudOverlay/HudOverlay.h"
#include "BRM_HudOverlay.generated.h"

class AEL_BRM;

UCLASS()
class AA29_API ABRM_HudOverlay : public AHudOverlay
{
	GENERATED_BODY()
public:
	ABRM_HudOverlay();

	UPROPERTY()					AEL_BRM* BRMLab;								//var EL_BRM BRMLab;

	void Render(UCanvas* C);
};
