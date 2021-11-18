// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AAExploreTheArmySubPanel.generated.h"

class UGUIButton;
class UGUIContentBox;

UCLASS()
class AA29_API UAAExploreTheArmySubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAAExploreTheArmySubPanel();

	UPROPERTY(EditAnywhere)			UGUIButton*			btnVisitVRO;				//var() automated XInterface.GUIButton btnVisitVRO;
	UPROPERTY(EditAnywhere)			UGUIButton*			btnPlayNow;					//var() automated XInterface.GUIButton btnPlayNow;
	UPROPERTY(EditAnywhere)			UGUIContentBox*		guicbPanel;					//var() automated GUIContentBox guicbPanel;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);
	void InstantActionFilterConfiguration();
	void DisplayBrowser();
	void DisplayLANBrowser();

};
