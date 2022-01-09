// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AARealHeroBriefSubPanel.generated.h"

class UAARealHeroStats;

UCLASS()
class UAARealHeroBriefSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAARealHeroBriefSubPanel();

	UPROPERTY(EditAnywhere)			UAARealHeroStats* l_Rails;			//var class<AARealHeroStats> MyRealHeroStatsClass;

	void ShowSubPanel();
	void SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass);
};
