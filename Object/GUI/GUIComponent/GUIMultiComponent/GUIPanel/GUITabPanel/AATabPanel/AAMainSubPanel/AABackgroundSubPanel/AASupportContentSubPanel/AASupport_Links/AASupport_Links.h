// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupportContentSubPanel.h"
#include "AASupport_Links.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAASupport_Links : public UAASupportContentSubPanel
{
	GENERATED_BODY()
public:
	UAASupport_Links();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3);

};
