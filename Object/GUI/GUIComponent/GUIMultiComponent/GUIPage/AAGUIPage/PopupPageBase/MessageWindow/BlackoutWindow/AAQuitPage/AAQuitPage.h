// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/BlackoutWindow.h"
#include "AAQuitPage.generated.h"

class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAAQuitPage : public UBlackoutWindow
{
	GENERATED_BODY()
public:
	UAAQuitPage();

	UPROPERTY(EditAnywhere)				UGUIButton* YesButton;				//var() automated XInterface.GUIButton YesButton;
	UPROPERTY(EditAnywhere)				UGUIButton* NoButton;				//var() automated XInterface.GUIButton NoButton;
	UPROPERTY(EditAnywhere)				UGUILabel* QuitDesc;				//var() automated XInterface.GUILabel QuitDesc;

	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
