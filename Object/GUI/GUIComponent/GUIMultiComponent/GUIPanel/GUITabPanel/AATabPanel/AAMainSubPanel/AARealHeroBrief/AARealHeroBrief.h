// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AAMainSubPanel.h"
#include "AARealHeroBrief.generated.h"

class UAARealHeroBriefSubPanel;
class UAARealHeroStats;
class UmoComboBox;
class UGUIButton;

UCLASS()
class AA29_API UAARealHeroBrief : public UAAMainSubPanel
{
	GENERATED_BODY()
public:
	UAARealHeroBrief();

	UPROPERTY(EditAnywhere)			UAARealHeroBriefSubPanel*			ActiveSubPanel;				//var AARealHeroBriefSubPanel ActiveSubPanel;
	UPROPERTY(EditAnywhere)			TArray<UAARealHeroBriefSubPanel*>	rhbsp_SubPanels;			//var TArray<AARealHeroBriefSubPanel> rhbsp_SubPanels;
	UPROPERTY(EditAnywhere)			UmoComboBox*						co_RealHero;				//var() automated XInterface.moComboBox co_RealHero;
	UPROPERTY(EditAnywhere)			TArray<UGUIButton*>					b_SubPanelButtons;			//var() automated TArray<GUIButton> b_SubPanelButtons;
	UPROPERTY(EditAnywhere)			TArray<FString>						RealHeroStatsClasses;		//var TArray<FString> RealHeroStatsClasses;
	UPROPERTY(EditAnywhere)			UAARealHeroStats*					MyRealHeroStatsClass;		//var class<AARealHeroStats> MyRealHeroStatsClass;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitSubPanels();
	void RepopulateComboBoxes();
	void ShowSubPanel(int32 WhichPanel);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	void SetRealHeroStatsClassByIndex(int32 NewRealHeroStatsClassIndex);
	void SetRealHeroStatsClassByName(FString NewRealHeroStatsClassName);
	void SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass);
};
