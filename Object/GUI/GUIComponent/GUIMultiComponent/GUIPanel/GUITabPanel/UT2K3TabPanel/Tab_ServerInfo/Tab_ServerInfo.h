// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_ServerInfo.generated.h"

class UGUIScrollTextBox;

UCLASS()
class AA29_API UTab_ServerInfo : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_ServerInfo();

	UPROPERTY()			bool					bClean;					//var bool bClean;
	UPROPERTY()			UGUIScrollTextBox*		MyScrollText;			//var GUIScrollTextBox MyScrollText;
	UPROPERTY()			FString					DefaultText;			//var localized FString DefaultText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ProcessRule(FString NewRule);

};
