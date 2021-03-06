// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetDataMenu.h"
#include "AAChatPassword.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UAAChatPassword : public UAAGetDataMenu
{
	GENERATED_BODY()
public:
	UAAChatPassword();

	UPROPERTY()		FString ChatRoomTitle;				//var FString ChatRoomTitle;
	UPROPERTY()		FString IncorrectPassword;			//var localized FString IncorrectPassword;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void HandleParameters(FString Title, FString FailCode);
	bool InternalOnClick(UGUIComponent* Sender);
	void RetryPassword();
};
