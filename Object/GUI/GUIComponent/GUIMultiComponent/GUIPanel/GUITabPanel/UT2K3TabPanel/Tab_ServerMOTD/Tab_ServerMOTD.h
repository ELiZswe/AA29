// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_ServerMOTD.generated.h"

class UGUIScrollTextBox;
class UmoEditBox;

/**
 * 
 */
UCLASS()
class AA29_API UTab_ServerMOTD : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_ServerMOTD();

	UPROPERTY()			UGUIScrollTextBox*	MyScrollText;		//var GUIScrollTextBox MyScrollText;
	UPROPERTY()			UmoEditBox*			AdminName;			//var moEditBox AdminName;
	UPROPERTY()			UmoEditBox*			AdminEmail;			//var moEditBox AdminEmail;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
