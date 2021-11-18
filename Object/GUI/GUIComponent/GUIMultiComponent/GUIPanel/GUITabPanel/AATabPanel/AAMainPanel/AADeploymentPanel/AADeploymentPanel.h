// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAMainPanel.h"
#include "AADeploymentPanel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAADeploymentPanel : public UAAMainPanel
{
	GENERATED_BODY()
public:
	UAADeploymentPanel();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);

};
