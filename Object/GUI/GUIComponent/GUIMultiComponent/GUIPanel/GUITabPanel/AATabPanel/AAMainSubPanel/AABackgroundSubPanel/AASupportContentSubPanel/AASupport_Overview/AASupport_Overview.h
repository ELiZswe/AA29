// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupportContentSubPanel.h"
#include "AASupport_Overview.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAASupport_Overview : public UAASupportContentSubPanel
{
	GENERATED_BODY()
public:
	UAASupport_Overview();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
