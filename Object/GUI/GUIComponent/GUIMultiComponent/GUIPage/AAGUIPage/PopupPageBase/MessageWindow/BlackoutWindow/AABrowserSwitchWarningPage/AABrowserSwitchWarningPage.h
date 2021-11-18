// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/BlackoutWindow.h"
#include "AABrowserSwitchWarningPage.generated.h"

class UGUIButton;
class UGUILabel;
class UmoCheckBox;

UCLASS()
class AA29_API UAABrowserSwitchWarningPage : public UBlackoutWindow
{
	GENERATED_BODY()
public:
	UAABrowserSwitchWarningPage();

	UPROPERTY(EditAnywhere)				UGUIButton*		YesButton;				//var() automated XInterface.GUIButton YesButton;
	UPROPERTY(EditAnywhere)				UGUIButton*		NoButton;				//var() automated XInterface.GUIButton NoButton;
	UPROPERTY(EditAnywhere)				UGUILabel*		WarningMessage;			//var() automated XInterface.GUILabel WarningMessage;
	UPROPERTY(EditAnywhere)				UmoCheckBox*	DisableWarning;			//var() automated XInterface.moCheckBox DisableWarning;
	UPROPERTY(EditAnywhere, config)		bool			b_OK;					//var config bool Disabled;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
