// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetDataMenu.h"
#include "AAIRC_NewNick.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UAAIRC_NewNick : public UAAGetDataMenu
{
	GENERATED_BODY()
public:
	UAAIRC_NewNick();

	UPROPERTY()		FString		EditCaption;	//var localized FString EditCaption;
	UPROPERTY()		FString		EditHint;		//var localized FString EditHint;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Owner);
};
