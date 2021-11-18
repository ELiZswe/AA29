// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "VoiceChatKeyBindPage.generated.h"

class UGUILabel;
class UmoEditBox;
class UGUIButton;

UCLASS()
class AA29_API UVoiceChatKeyBindPage : public ULargeWindow
{
	GENERATED_BODY()
public:
	UVoiceChatKeyBindPage();

	UPROPERTY(EditAnywhere)		UGUILabel*			l_PageTitle;			//var() automated XInterface.GUILabel l_PageTitle;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_KeyLabel1;			//var() automated XInterface.GUILabel l_KeyLabel1;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_KeyLabel2;			//var() automated XInterface.GUILabel l_KeyLabel2;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_Key1;					//var() automated XInterface.GUILabel l_Key1;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_Key2;					//var() automated XInterface.GUILabel l_Key2;
	UPROPERTY(EditAnywhere)		UmoEditBox*			ed_ChannelName;			//var() automated XInterface.moEditBox ed_ChannelName;
	UPROPERTY(EditAnywhere)		UGUIButton*			b_OK;					//var() automated XInterface.GUIButton b_OK;
	UPROPERTY()					FString				NoneText;				//var localized FString NoneText;
	UPROPERTY()					FString				AnyKeyText;				//var localized FString AnyKeyText;
	UPROPERTY()					FString				Channel;				//var FString Channel;
	UPROPERTY()					TArray<FString>		Keys;					//var TArray<FString> Keys;
	UPROPERTY()					TArray<FString>		LocalizedKeys;			//var TArray<FString> LocalizedKeys;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void HandleParameters(FString Value, FString Nothing);
	void GetBinds();
	bool CloseClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	bool KeyClick(UGUIComponent* Sender);
	void UpdateLabel(UGUILabel* Label, bool bWaitingForRawInput);
	bool RawKeyPress(uint8 NewKey);
};
