// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2StatsPrompt.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UUT2StatsPrompt : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2StatsPrompt();

	void OnStatsConfigured();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void ReOpen();
};
