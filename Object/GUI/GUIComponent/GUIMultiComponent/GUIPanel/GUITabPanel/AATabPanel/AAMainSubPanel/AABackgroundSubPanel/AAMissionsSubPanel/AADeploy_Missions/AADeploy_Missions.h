// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAMissionsSubPanel/AAMissionsSubPanel.h"
#include "AADeploy_Missions.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAADeploy_Missions : public UAAMissionsSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_Missions();

	bool UseTraining(int32 Tour);
	void SetStatusCaption(int32 Status);
	bool ButtonClick(UGUIComponent* Sender);

};
