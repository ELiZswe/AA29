// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAMissionsSubPanel/AAMissionsDetailsSubPanel/AAMissionsDetailsSubPanel.h"
#include "AADeploy_Details.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAADeploy_Details : public UAAMissionsDetailsSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_Details();

	bool UseTraining(int32 Tour);
	void SetStatusCaption(int32 Status);
	bool ButtonClick(UGUIComponent* Sender);

};
