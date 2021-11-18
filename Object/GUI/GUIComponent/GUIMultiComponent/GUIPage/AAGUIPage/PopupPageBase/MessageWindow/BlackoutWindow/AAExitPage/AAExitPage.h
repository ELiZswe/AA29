// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/BlackoutWindow.h"
#include "AAExitPage.generated.h"

class GUIButton;
class GUILabel;

UCLASS()
class AA29_API UAAExitPage : public UBlackoutWindow
{
	GENERATED_BODY()
public:
	UAAExitPage();


	UPROPERTY(EditAnywhere)				UGUIButton*		ExitButton;				//var() automated XInterface.GUIButton ExitButton;
	UPROPERTY(EditAnywhere)				UGUIButton*		CancelButton;			//var() automated XInterface.GUIButton CancelButton;
	UPROPERTY(EditAnywhere)				UGUILabel*		ExitDesc;				//var() automated XInterface.GUILabel ExitDesc;

	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
