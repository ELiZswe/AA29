// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_AudioSettings.generated.h"

class UmoComboBox;

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UTab_AudioSettings : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_AudioSettings();

	UPROPERTY()			TArray<FString>				AudioModes;				//var localized FString AudioModes[4];
	UPROPERTY()			TArray<FString>				VoiceModes;				//var localized FString VoiceModes[4];
	UPROPERTY()			TArray<FString>				AnnounceModes;			//var localized FString AnnounceModes[3];
	UPROPERTY()			UmoComboBox*				APack;					//var moComboBox APack;
	UPROPERTY(config)	TArray<FAPackInfo>			BonusPackInfo;			//var config GUI.APackInfo BonusPackInfo[4];
	UPROPERTY()			TArray<FAPackInfo>			PackInfo;				//var config TArray<APackInfo> PackInfo;
	UPROPERTY()			bool						bInitialized;			//var bool bInitialized;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	FString InternalOnSaveINI(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
};
