// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/MessageWindow.h"
#include "AAGenerateKeyModalDialog.generated.h"

class UGUILabel;
class UKeyGenerator;

UCLASS()
class AA29_API UAAGenerateKeyModalDialog : public UMessageWindow
{
	GENERATED_BODY()
public:
	UAAGenerateKeyModalDialog();

	UPROPERTY(EditAnywhere)		UGUILabel*		l_Text;				//var() automated XInterface.GUILabel l_Text;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_Text2;			//var() automated XInterface.GUILabel l_Text2;
	UPROPERTY()					UKeyGenerator*	KeyGenerator;		//var DBAuth.KeyGenerator KeyGenerator;

	void HandleParameters(FString Param1, FString Param2);
	void InternalOnOpen();
	void InternalOnTimer(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	bool InternalOnCanClose(bool bCancelled);
	void InternalOnClose(bool bCancelled);
};
