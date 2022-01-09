// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/MissionResultDisplay/MissionResultDisplay.h"
#include "Mission2ResultDisplay.generated.h"

/**
 * 
 */
UCLASS()
class UMission2ResultDisplay : public UMissionResultDisplay
{
	GENERATED_BODY()
public:
	UMission2ResultDisplay();

	void Draw(UCanvas* Canvas);
	void SetScoreText();
};
