// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_VideoSettings.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTab_VideoSettings : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_VideoSettings();

	UPROPERTY()			bool					ShowSShot;			//var bool ShowSShot;
	UPROPERTY()			TArray<FDisplayMode>	DisplayModes;		//var DisplayMode DisplayModes[19];
	UPROPERTY()			TArray<FString>			BitDepthText;		//var localized FString BitDepthText[2];

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void CheckSupportedResolutions();
	void Refresh();
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	FString InternalOnSaveINI(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	bool ApplyChanges(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
};
