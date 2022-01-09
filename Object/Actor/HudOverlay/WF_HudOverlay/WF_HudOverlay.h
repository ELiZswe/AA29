// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HudOverlay/HudOverlay.h"
#include "WF_HudOverlay.generated.h"

class ATargetManager;

UCLASS()
class AWF_HudOverlay : public AHudOverlay
{
	GENERATED_BODY()
public:
	AWF_HudOverlay();

	UPROPERTY()					FColor					ScoreColor;				//var Color ScoreColor;
	UPROPERTY()					ATargetManager*			TargetManager;			//var AGP_Gameplay.TargetManager TargetManager;

	void Render(UCanvas* C);
};
