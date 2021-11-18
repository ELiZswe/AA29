// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_ControlSettings/Tab_ControlSettings.h"
#include "Tab_SpeechBinder.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTab_SpeechBinder : public UTab_ControlSettings
{
	GENERATED_BODY()
public:
	UTab_SpeechBinder();

	UPROPERTY()			bool bNoMatureLanguage;				//var transient bool bNoMatureLanguage;
	UPROPERTY()			FString SpeechLabel;				//var localized FString SpeechLabel;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitBindings();
	void AddCommand(bool IsSection, FString KeyLabel, FString Alias);
	void LoadSpeechCommands();
};
