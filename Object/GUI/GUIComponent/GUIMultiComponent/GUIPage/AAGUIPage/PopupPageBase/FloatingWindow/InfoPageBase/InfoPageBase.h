// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/FloatingWindow.h"
#include "InfoPageBase.generated.h"

class UGUIScrollTextBox;

UCLASS()
class AA29_API UInfoPageBase : public UFloatingWindow
{
	GENERATED_BODY()
public:
	UInfoPageBase();

	UPROPERTY(EditAnywhere)		UGUIScrollTextBox* lb_Info;				//var() automated XInterface.GUIScrollTextBox lb_Info;

	void HandleParameters(FString Param1, FString Param2);
	FString ReplaceSpaces(FString S);
};
