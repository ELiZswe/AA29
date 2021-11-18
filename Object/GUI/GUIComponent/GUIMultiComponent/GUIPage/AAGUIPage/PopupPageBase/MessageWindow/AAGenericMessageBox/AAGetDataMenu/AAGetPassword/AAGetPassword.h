// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetDataMenu.h"
#include "AAGetPassword.generated.h"

class UExtendedConsole;

UCLASS()
class AA29_API UAAGetPassword : public UAAGetDataMenu
{
	GENERATED_BODY()
public:
	UAAGetPassword();

	UPROPERTY()		FString RetryURL;				//var FString RetryURL;
	UPROPERTY()		FString IncorrectPassword;		//var localized FString IncorrectPassword;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void HandleParameters(FString URL, FString FailCode);
	bool InternalOnClick(UGUIComponent* Sender);
	void RetryPassword();
	void SavePassword(UExtendedConsole* InConsole, FString InPassword);
};
