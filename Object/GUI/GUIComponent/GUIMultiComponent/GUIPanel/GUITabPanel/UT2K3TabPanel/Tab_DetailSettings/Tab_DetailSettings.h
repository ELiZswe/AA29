// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_DetailSettings.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTab_DetailSettings : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_DetailSettings();

	UPROPERTY()			bool						bExpert;				//var config bool bExpert;
	UPROPERTY()			TArray<FString>				DetailLevels;			//var localized FString DetailLevels[7];
	UPROPERTY()			bool						bPlayedSound;			//var bool bPlayedSound;
	UPROPERTY()			int32						prevWorldDetail;		//var int32 prevWorldDetail;
	UPROPERTY()			int32						prevTextureDetail;		//var int32 prevTextureDetail;
	UPROPERTY()			int32						prevCharDetail;			//var int32 prevCharDetail;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	FString InternalOnSaveINI(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);

};
