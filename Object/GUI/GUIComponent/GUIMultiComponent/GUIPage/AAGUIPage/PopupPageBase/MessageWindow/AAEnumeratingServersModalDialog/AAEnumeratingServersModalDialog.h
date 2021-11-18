// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/MessageWindow.h"
#include "AAEnumeratingServersModalDialog.generated.h"

class UGUILabel;

UCLASS()
class AA29_API UAAEnumeratingServersModalDialog : public UMessageWindow
{
	GENERATED_BODY()
public:
	UAAEnumeratingServersModalDialog();

	UPROPERTY(EditAnywhere)						UGUILabel*	l_Text;				//var() automated XInterface.GUILabel l_Text;
	UPROPERTY(EditAnywhere)						UGUILabel*	l_Text2;			//var() automated XInterface.GUILabel l_Text2;
	UPROPERTY()									FString		UpdateMessage;		//var localized FString UpdateMessage;

	void HandleParameters(FString Param1, FString Param2);
	void InternalOnOpen();
	void InternalOnTimer(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
