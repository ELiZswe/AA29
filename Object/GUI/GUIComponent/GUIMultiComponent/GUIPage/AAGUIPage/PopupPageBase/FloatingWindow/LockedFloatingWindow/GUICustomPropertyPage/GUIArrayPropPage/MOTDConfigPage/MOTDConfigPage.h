// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/GUIArrayPropPage/GUIArrayPropPage.h"
#include "MOTDConfigPage.generated.h"

class UGUIMenuOption;

UCLASS()
class AA29_API UMOTDConfigPage : public UGUIArrayPropPage
{
	GENERATED_BODY()
public:
	UMOTDConfigPage();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetOwner(UGUIComponent* NewOwner);
	FString GetDataString();
	void SetItemOptions(UGUIMenuOption* mo);
};
