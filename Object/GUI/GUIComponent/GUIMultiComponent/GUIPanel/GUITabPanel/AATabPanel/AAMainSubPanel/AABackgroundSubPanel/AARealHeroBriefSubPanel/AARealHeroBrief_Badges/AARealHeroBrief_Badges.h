// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARealHeroBriefSubPanel/AARealHeroBriefSubPanel.h"
#include "AARealHeroBrief_Badges.generated.h"

class UAARealHeroUniformDisplay;
class UAAGUIBadgeDescription;
class UAARealHeroStats;

UCLASS()
class AA29_API UAARealHeroBrief_Badges : public UAARealHeroBriefSubPanel
{
	GENERATED_BODY()
public:
	UAARealHeroBrief_Badges();

	UPROPERTY(EditAnywhere)			UAARealHeroUniformDisplay*		ud_UniformDisplay;				//var() automated AARealHeroUniformDisplay ud_UniformDisplay;
	UPROPERTY(EditAnywhere)			UAAGUIBadgeDescription*			bd_BadgeDescription;			//var() automated AAGUIBadgeDescription bd_BadgeDescription;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass);
	void SetUniform(int32 UniformIndex);
};
