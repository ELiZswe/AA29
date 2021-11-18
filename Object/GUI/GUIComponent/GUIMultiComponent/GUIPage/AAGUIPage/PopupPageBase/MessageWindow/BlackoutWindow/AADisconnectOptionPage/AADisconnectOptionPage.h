// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/BlackoutWindow.h"
#include "AADisconnectOptionPage.generated.h"

class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAADisconnectOptionPage : public UBlackoutWindow
{
	GENERATED_BODY()
public:
	UAADisconnectOptionPage();

	UPROPERTY(EditAnywhere)				UGUIButton*		b_MainMenu;				//var() automated XInterface.GUIButton b_MainMenu;
	UPROPERTY(EditAnywhere)				UGUIButton*		b_ServerBrowser;		//var() automated XInterface.GUIButton b_ServerBrowser;
	UPROPERTY(EditAnywhere)				UGUIButton*		b_Reconnect;			//var() automated XInterface.GUIButton b_Reconnect;
	UPROPERTY(EditAnywhere)				UGUIButton*		b_Quit;					//var() automated XInterface.GUIButton b_Quit;
	UPROPERTY(EditAnywhere)				UGUILabel*		l_Status;				//var() automated XInterface.GUILabel l_Status;
	UPROPERTY(EditAnywhere)				bool			bReconnectAllowed;		//var() bool bReconnectAllowed;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetSizingCaption();
	void HandleParameters(FString Param1, FString Param2);
	void UpdateButtons();
	void Opened(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	void UpdateStatus(FString NewStatus);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	bool NotifyLevelChange();
	bool CanClose(bool bCancelled);
	bool AllowOpen(FString MenuClass);
};
