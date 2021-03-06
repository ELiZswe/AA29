// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_SPPanelBase.generated.h"

class UGameProfile;
class UGUITabControl;

UCLASS()
class UTab_SPPanelBase : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_SPPanelBase();

	void OnProfileUpdated();
	void OnMatchUpdated(int32 iLadder, int32 iMatch);
	UGameProfile* GetProfile();
	UGUITabControl* MyTabControl();
	void ProfileUpdated();
	void MatchUpdated(int32 iLadder, int32 iMatch);
};
