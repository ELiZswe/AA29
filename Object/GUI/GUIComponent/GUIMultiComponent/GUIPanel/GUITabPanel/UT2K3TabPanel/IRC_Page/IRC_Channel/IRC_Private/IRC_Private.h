// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Channel/IRC_Channel.h"
#include "IRC_Private.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UIRC_Private : public UIRC_Channel
{
	GENERATED_BODY()
public:
	UIRC_Private();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ProcessInput(FString Text);
	void ChangedNick(FString OldNick, FString NewNick);
	void UserQuit(FString Nick, FString Reason);
	void PrivateText(FString Nick, FString Text);
	void PrivateAction(FString Nick, FString Text);
	void IsAway(FString Nick, FString Message);
};
