// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_HudSettings.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTab_HudSettings : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_HudSettings();

	UPROPERTY()			TArray<FString>				CrosshairNames;			//var localized FString CrosshairNames[15];

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	FString InternalOnSaveINI(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);

};
