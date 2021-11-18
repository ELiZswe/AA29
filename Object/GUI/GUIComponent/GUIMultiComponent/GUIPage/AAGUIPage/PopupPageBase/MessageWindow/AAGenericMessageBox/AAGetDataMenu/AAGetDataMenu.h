// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGenericMessageBox.h"
#include "AAGetDataMenu.generated.h"

class UGUIButton;
class UmoEditBox;

UCLASS()
class AA29_API UAAGetDataMenu : public UAAGenericMessageBox
{
	GENERATED_BODY()
public:
	UAAGetDataMenu();

	UPROPERTY(EditAnywhere)		UGUIButton*	b_Cancel;				//var() automated XInterface.GUIButton b_Cancel;
	UPROPERTY(EditAnywhere)		UmoEditBox*	ed_Data;				//var() automated XInterface.moEditBox ed_Data;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void HandleParameters(FString A, FString B);
	FString GetDataString();
	void SetDataString(FString str);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	bool InternalOnPreDraw(UCanvas* C);
};
