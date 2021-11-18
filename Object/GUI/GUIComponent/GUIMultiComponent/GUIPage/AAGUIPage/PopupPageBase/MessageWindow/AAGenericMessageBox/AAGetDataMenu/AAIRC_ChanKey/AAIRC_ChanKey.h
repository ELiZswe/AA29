// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetDataMenu.h"
#include "AAIRC_ChanKey.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAIRC_ChanKey : public UAAGetDataMenu
{
	GENERATED_BODY()
public:
	UAAIRC_ChanKey();

	UPROPERTY()		FString		EditCaption;		//var localized FString EditCaption;
	UPROPERTY()		FString		EditHint;			//var localized FString EditHint;
	UPROPERTY()		FString		msgCaption;			//var localized FString msgCaption;
	UPROPERTY()		FString		kchan;				//var FString kchan;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Owner);
	void HandleParameters(FString A, FString B);
	FString GetDataString();
};
