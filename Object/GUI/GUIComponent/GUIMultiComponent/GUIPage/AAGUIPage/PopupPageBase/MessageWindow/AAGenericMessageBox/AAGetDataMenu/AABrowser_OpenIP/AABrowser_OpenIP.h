// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetDataMenu.h"
#include "AABrowser_OpenIP.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_OpenIP : public UAAGetDataMenu
{
	GENERATED_BODY()
public:
	UAABrowser_OpenIP();

	UPROPERTY()		FString OKButtonHint;				//var localized FString OKButtonHint;
	UPROPERTY()		FString CancelButtonHint;			//var localized FString CancelButtonHint;
	UPROPERTY()		FString EditBoxHint;				//var localized FString EditBoxHint;

	void InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner);
	void HandleParameters(FString S, FString s2);
	bool InternalOnClick(UGUIComponent* Sender);
	void Execute();
	void ApplyURL(FString URL);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	FString StripProtocol(FString S);
};
