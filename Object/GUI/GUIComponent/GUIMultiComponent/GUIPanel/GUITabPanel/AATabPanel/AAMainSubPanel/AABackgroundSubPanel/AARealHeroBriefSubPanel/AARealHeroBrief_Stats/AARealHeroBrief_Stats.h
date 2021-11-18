// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARealHeroBriefSubPanel/AARealHeroBriefSubPanel.h"
#include "AARealHeroBrief_Stats.generated.h"

class UGUIContentBox;
class UNMLContent;
class UAARealHeroStats;

UCLASS()
class AA29_API UAARealHeroBrief_Stats : public UAARealHeroBriefSubPanel
{
	GENERATED_BODY()
public:
	UAARealHeroBrief_Stats();

	UPROPERTY(EditAnywhere)		UGUIContentBox*		gcb_NMLContent;			//var() automated GUIContentBox gcb_NMLContent;
	UPROPERTY()					UNMLContent*		MyNMLContent;			//var NMLContent MyNMLContent;
	UPROPERTY()					FString				PageToParse;			//var FString PageToParse;
	UPROPERTY()					FString				NMLServer;				//var FString NMLServer;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass);
};
