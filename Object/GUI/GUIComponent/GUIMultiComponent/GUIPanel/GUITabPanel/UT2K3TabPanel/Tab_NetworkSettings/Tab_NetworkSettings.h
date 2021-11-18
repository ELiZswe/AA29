// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_NetworkSettings.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTab_NetworkSettings : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_NetworkSettings();

	UPROPERTY()			TArray<FString>		NetSpeedText;		//var localized FString NetSpeedText[4];
	UPROPERTY()			FString				StatsURL;			//var localized FString StatsURL;
	UPROPERTY()			FString				EpicIDMsg;			//var localized FString EpicIDMsg;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString FormatID(FString Id);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	bool ValidStatConfig();
	void ApplyStatConfig();
	void InternalOnChange(UGUIComponent* Sender);
	bool OnViewStats(UGUIComponent* Sender);
};
