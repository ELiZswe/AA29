// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATabPanel.h"
#include "AAIRC_Page.generated.h"

class UmoEditBox;
class UGUISplitter;
class UGUIScrollTextBox;

UCLASS(Config = Game)
class AA29_API UAAIRC_Page : public UAATabPanel
{
	GENERATED_BODY()
public:
	UAAIRC_Page();

	UPROPERTY(EditAnywhere)					UmoEditBox*					ed_TextEntry;					//var() automated XInterface.moEditBox ed_TextEntry;
	UPROPERTY(EditAnywhere)					UGUISplitter*				sp_Main;						//var() automated XInterface.GUISplitter sp_Main;
	UPROPERTY(EditAnywhere, config)			float						MainSplitterPosition;			//var() config float MainSplitterPosition;
	UPROPERTY()								UGUIScrollTextBox*			lb_TextDisplay;					//var XInterface.GUIScrollTextBox lb_TextDisplay;
	UPROPERTY()								FString						HasLeftText;					//var localized FString HasLeftText;
	UPROPERTY()								FString						HasJoinedText;					//var localized FString HasJoinedText;
	UPROPERTY()								FString						WasKickedByText;				//var localized FString WasKickedByText;
	UPROPERTY()								FString						NowKnownAsText;					//var localized FString NowKnownAsText;
	UPROPERTY()								FString						QuitText;						//var localized FString QuitText;
	UPROPERTY()								FString						SetsModeText;					//var localized FString SetsModeText;
	UPROPERTY()								FString						NewTopicText;					//var localized FString NewTopicText;
	UPROPERTY(config)						int32						MaxChatScrollback;				//var config int32 MaxChatScrollback;
	UPROPERTY(config)						int32						InputHistorySize;				//var config int32 InputHistorySize;
	UPROPERTY(globalconfig)					bool						bIRCTextToSpeechEnabled;		//var globalconfig bool bIRCTextToSpeechEnabled;
	UPROPERTY()								TArray<FString>				InputHistory;					//var transient TArray<String> InputHistory;
	UPROPERTY()								int32						InputHistoryPos;				//var transient int32 InputHistoryPos;
	UPROPERTY()								bool						bDoneInputScroll;				//var transient bool bDoneInputScroll;
	UPROPERTY(config)						FColor						IRCTextColor;					//var config Color IRCTextColor;
	UPROPERTY(config)						FColor						IRCNickColor;					//var config Color IRCNickColor;
	UPROPERTY(config)						FColor						IRCActionColor;					//var config Color IRCActionColor;
	UPROPERTY(config)						FColor						IRCInfoColor;					//var config Color IRCInfoColor;
	UPROPERTY(config)						FColor						IRCLinkColor;					//var config Color IRCLinkColor;

	void ProcessInput(FString Text);
	void Free();
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	FString ColorizeLinks(FString InString);
	bool IRCTextDblClick(UGUIComponent* Sender);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InterpretColorCodes(FString& Text);
	FColor DecodeColor(int32 ColorCode);
};
