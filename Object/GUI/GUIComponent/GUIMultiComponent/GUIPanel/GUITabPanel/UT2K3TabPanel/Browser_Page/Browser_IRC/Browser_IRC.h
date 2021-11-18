// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_Page.h"
#include "Browser_IRC.generated.h"

class UIRC_System;
class UGUITabControl;
class UGUIButton;

UCLASS()
class AA29_API UBrowser_IRC : public UBrowser_Page
{
	GENERATED_BODY()
public:
	UBrowser_IRC();

	UPROPERTY()								UIRC_System* SystemPage;					//var IRC_System SystemPage;
	UPROPERTY()								UGUITabControl* ChannelTabs;				//var GUITabControl ChannelTabs;
	UPROPERTY()								FString SystemLabel;						//var localized FString SystemLabel;
	UPROPERTY()								bool bIrcIsInitialised;						//var bool bIrcIsInitialised;
	UPROPERTY()								UGUIButton* LeaveButton;					//var GUIButton LeaveButton;
	UPROPERTY()								UGUIButton* BackButton;						//var GUIButton BackButton;
	UPROPERTY()								UGUIButton* ChangeNickButton;				//var GUIButton ChangeNickButton;
	UPROPERTY()								FString LeaveChannelCaption;				//var localized FString LeaveChannelCaption;
	UPROPERTY()								FString LeavePrivateCaptionHead;			//var localized FString LeavePrivateCaptionHead;
	UPROPERTY()								FString LeavePrivateCaptionTail;			//var localized FString LeavePrivateCaptionTail;
	UPROPERTY()								FString ChooseNewNickText;					//var localized FString ChooseNewNickText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool BackClick(UGUIComponent* Sender);
	bool ChangeNickClick(UGUIComponent* Sender);
	void TabChange(UGUIComponent* Sender);
	bool LeaveChannelClick(UGUIComponent* Sender);
};
