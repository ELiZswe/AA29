// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAMainPanel.h"
#include "AABrowserPanel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowserPanel : public UAAMainPanel
{
	GENERATED_BODY()
public:
	UAABrowserPanel();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);

};
