// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploymentDetailsSubPanel.h"
#include "AADeploy_Details_UserCreated.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAADeploy_Details_UserCreated : public UAADeploymentDetailsSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_Details_UserCreated();

	void InternalOnChange(UGUIComponent* Sender);
	bool ButtonClick(UGUIComponent* Sender);
	void SetDeployButtonToDCDS();
	void SetDeployButtonToDeploy();
	int32 MyCompareItem(FGUIListElem ElemA, FGUIListElem ElemB);
	void PopulateComboBox();
};
