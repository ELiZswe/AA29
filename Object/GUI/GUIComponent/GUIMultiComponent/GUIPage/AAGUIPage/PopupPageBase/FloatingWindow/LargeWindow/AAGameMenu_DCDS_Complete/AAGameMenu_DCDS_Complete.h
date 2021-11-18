// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "AAGameMenu_DCDS_Complete.generated.h"

class UAAGUILabel;
class UGUIButton;
class UGUIComponent;

UCLASS()
class AA29_API UAAGameMenu_DCDS_Complete : public ULargeWindow
{
	GENERATED_BODY()
public:
	UAAGameMenu_DCDS_Complete();

	UPROPERTY(EditAnywhere)		UAAGUILabel*	l_Heading;			//var() automated AAGUILabel l_Heading;
	UPROPERTY(EditAnywhere)		UAAGUILabel*	l_Caption;			//var() automated AAGUILabel l_Caption;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_OK;				//var() automated XInterface.GUIButton b_OK;

	void HandleParameters(FString Param1, FString Param2);
	bool InternalOnClick(UGUIComponent* Sender);
};
