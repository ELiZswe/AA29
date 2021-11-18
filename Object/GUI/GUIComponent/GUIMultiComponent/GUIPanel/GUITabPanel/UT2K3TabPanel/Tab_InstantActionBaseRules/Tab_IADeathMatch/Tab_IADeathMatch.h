// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_InstantActionBaseRules/Tab_InstantActionBaseRules.h"
#include "Tab_IADeathMatch.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UTab_IADeathMatch : public UTab_InstantActionBaseRules
{
	GENERATED_BODY()
public:
	UTab_IADeathMatch();

	UPROPERTY(config)	bool		LastAutoAdjustSkill;		//var config bool LastAutoAdjustSkill;
	UPROPERTY()			FString		GoalScoreText;				//var localized FString GoalScoreText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString Play();

};
