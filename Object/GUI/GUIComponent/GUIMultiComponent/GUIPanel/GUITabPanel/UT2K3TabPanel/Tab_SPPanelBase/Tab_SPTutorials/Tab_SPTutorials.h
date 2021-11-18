// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPPanelBase.h"
#include "Tab_SPTutorials.generated.h"

class UGUIImage;
class UGUILabel;
class UGUIButton;

UCLASS(Config = Game)
class AA29_API UTab_SPTutorials : public UTab_SPPanelBase
{
	GENERATED_BODY()
public:
	UTab_SPTutorials();

	UPROPERTY()			TArray<UGUIImage*>		TutImages;				//var TArray<GUIImage> TutImages;
	UPROPERTY()			TArray<UGUIImage*>		TutBorders;				//var TArray<GUIImage> TutBorders;
	UPROPERTY()			TArray<UGUILabel*>		TutLabels;				//var TArray<GUILabel> TutLabels;
	UPROPERTY()			TArray<UGUIButton*>		TutButtons;				//var TArray<GUIButton> TutButtons;
	UPROPERTY()			FString					SelectMessage;			//var localized FString SelectMessage;
	UPROPERTY(config)	bool					bTDMUnlocked;			//var config bool bTDMUnlocked;
	UPROPERTY(config)	bool					bDOMUnlocked;			//var config bool bDOMUnlocked;
	UPROPERTY(config)	bool					bCTFUnlocked;			//var config bool bCTFUnlocked;
	UPROPERTY(config)	bool					bBRUnlocked;			//var config bool bBRUnlocked;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	bool InternalOnClick(UGUIComponent* Sender);
	bool CanShowPanel();
};
