// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupportContentSubPanel.h"
#include "AASupport_Help.generated.h"

class UAAIRC_Panel;

UCLASS()
class AA29_API UAASupport_Help : public UAASupportContentSubPanel
{
	GENERATED_BODY()
public:
	UAASupport_Help();

	UPROPERTY()			UAAIRC_Panel* aaircp;						//var AAIRC_Panel aaircp;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3);
	void Timer();
	bool IsInSupportChannel();

};
