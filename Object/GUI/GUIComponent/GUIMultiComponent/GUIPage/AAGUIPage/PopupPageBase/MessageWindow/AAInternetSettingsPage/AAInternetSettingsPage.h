// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/MessageWindow.h"
#include "AAInternetSettingsPage.generated.h"

class UGUIButton;
class UmoEditBox; 
class UmoComboBox;

UCLASS()
class AA29_API UAAInternetSettingsPage : public UMessageWindow
{
	GENERATED_BODY()
public:
	UAAInternetSettingsPage();

	UPROPERTY(EditAnywhere)		UGUIButton*		b_OK;					//var() automated XInterface.GUIButton b_OK;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_Cancel;				//var() automated XInterface.GUIButton b_Cancel;
	UPROPERTY(EditAnywhere)		UmoEditBox*		ed_PlayerName;			//var() automated XInterface.moEditBox ed_PlayerName;
	UPROPERTY(EditAnywhere)		UmoComboBox*	co_Netspeed;			//var() automated XInterface.moComboBox co_Netspeed;


	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	void SetupPlayerName();
	void SetupNetspeedCombo();
	bool InternalOnClick(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	FString GetNetspeedValue(int32 i);
	int32 GetNetspeedIndex(int32 Netspeed);
};
