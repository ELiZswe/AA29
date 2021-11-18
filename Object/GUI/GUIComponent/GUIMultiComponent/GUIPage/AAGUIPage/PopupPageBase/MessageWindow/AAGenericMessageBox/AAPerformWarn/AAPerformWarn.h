// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGenericMessageBox.h"
#include "AAPerformWarn.generated.h"

class UmoCheckBox;

UCLASS()
class AA29_API UAAPerformWarn : public UAAGenericMessageBox
{
	GENERATED_BODY()
public:
	UAAPerformWarn();

	UPROPERTY(EditAnywhere)		UmoCheckBox* ch_NeverShowAgain;				//var() automated XInterface.moCheckBox ch_NeverShowAgain;

	void HandleParameters(FString Param1, FString Param2);
	void Timer();
	bool InternalOnClick(UGUIComponent* Sender);
	void CheckBoxClick(UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString Value);
};
