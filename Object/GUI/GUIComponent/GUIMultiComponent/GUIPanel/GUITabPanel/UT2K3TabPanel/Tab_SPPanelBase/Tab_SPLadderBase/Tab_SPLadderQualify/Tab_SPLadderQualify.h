// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPLadderBase/Tab_SPLadderBase.h"
#include "Tab_SPLadderQualify.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTab_SPLadderQualify : public UTab_SPLadderBase
{
	GENERATED_BODY()
public:
	UTab_SPLadderQualify();

	UPROPERTY()			TArray<ULadderButton*> DMButtons;			//var TArray<LadderButton> DMButtons;

	void InitPanel();
	void OnProfileUpdated();
};
