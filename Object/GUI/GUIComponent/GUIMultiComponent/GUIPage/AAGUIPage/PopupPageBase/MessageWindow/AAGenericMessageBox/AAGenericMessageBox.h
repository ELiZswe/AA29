// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/MessageWindow.h"
#include "AAGenericMessageBox.generated.h"

class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAAGenericMessageBox : public UMessageWindow
{
	GENERATED_BODY()
public:
	UAAGenericMessageBox();

	UPROPERTY(EditAnywhere)		UGUIButton*	b_OK;				//var() automated XInterface.GUIButton b_OK;
	UPROPERTY(EditAnywhere)		UGUILabel*	l_Text;				//var() automated XInterface.GUILabel l_Text;
	UPROPERTY(EditAnywhere)		UGUILabel*	l_Text2;			//var() automated XInterface.GUILabel l_Text2;

	bool InternalOnClick(UGUIComponent* Sender);
	void HandleParameters(FString Param1, FString Param2);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
