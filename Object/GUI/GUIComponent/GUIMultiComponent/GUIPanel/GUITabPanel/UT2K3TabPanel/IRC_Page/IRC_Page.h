// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "IRC_Page.generated.h"

class UmoEditBox;
class UGUIScrollTextBox;

UCLASS(Config = Game)
class AA29_API UIRC_Page : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UIRC_Page();

	UPROPERTY()			UmoEditBox*			TextEntry;						//var moEditBox TextEntry;
	UPROPERTY()			UGUIScrollTextBox*	TextDisplay;					//var GUIScrollTextBox TextDisplay;
	UPROPERTY()			FString				HasLeftText;					//var localized FString HasLeftText;
	UPROPERTY()			FString				HasJoinedText;					//var localized FString HasJoinedText;
	UPROPERTY()			FString				WasKickedByText;				//var localized FString WasKickedByText;
	UPROPERTY()			FString				NowKnownAsText;					//var localized FString NowKnownAsText;
	UPROPERTY()			FString				QuitText;						//var localized FString QuitText;
	UPROPERTY()			FString				SetsModeText;					//var localized FString SetsModeText;
	UPROPERTY()			FString				NewTopicText;					//var localized FString NewTopicText;
	UPROPERTY(config)	int32				MaxChatScrollback;				//var config int32 MaxChatScrollback;
	UPROPERTY(config)	int32				InputHistorySize;				//var config int32 InputHistorySize;
	UPROPERTY()			TArray<FString>		InputHistory;					//var transient TArray<FString> InputHistory;
	UPROPERTY()			int32				InputHistoryPos;				//var transient int32 InputHistoryPos;
	UPROPERTY()			bool				bDoneInputScroll;				//var transient bool bDoneInputScroll;
	UPROPERTY(config)	FColor				IRCTextColor;					//var config Color IRCTextColor;
	UPROPERTY(config)	FColor				IRCNickColor;					//var config Color IRCNickColor;
	UPROPERTY(config)	FColor				IRCActionColor;					//var config Color IRCActionColor;
	UPROPERTY(config)	FColor				IRCInfoColor;					//var config Color IRCInfoColor;
	UPROPERTY(config)	FColor				IRCLinkColor;					//var config Color IRCLinkColor;


	void ProcessInput(FString Text);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	FString ColorizeLinks(FString InString);
	bool IRCTextDblClick(UGUIComponent* Sender);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
