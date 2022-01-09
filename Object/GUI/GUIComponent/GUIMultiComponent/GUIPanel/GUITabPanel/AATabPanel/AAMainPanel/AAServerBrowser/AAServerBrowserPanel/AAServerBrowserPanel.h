// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAServerBrowser/AAServerBrowser.h"
#include "AAServerBrowserPanel.generated.h"

UCLASS()
class UAAServerBrowserPanel : public UAAServerBrowser
{
	GENERATED_BODY()
public:
	UAAServerBrowserPanel();


	void CheckPlayerOptions();
	void CheckPunkBusterNotice();
	bool InternetOptionsConfirm(uint8 ButtonMask);

};
