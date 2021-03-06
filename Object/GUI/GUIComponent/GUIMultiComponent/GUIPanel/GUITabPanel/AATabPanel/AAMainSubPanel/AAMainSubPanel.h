// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATabPanel.h"
#include "AAMainSubPanel.generated.h"

class UAAGUITabControl;

class UGUIComponent;
class UGUIController;
UCLASS()
class UAAMainSubPanel : public UAATabPanel
{
	GENERATED_BODY()
public:
	UAAMainSubPanel();

	UPROPERTY(EditAnywhere)			UAAGUITabControl*		c_Tab;						//var() automated AAGUITabControl c_Tab;
	UPROPERTY()						TArray<FString>			PanelClasses;				//var TArray<FString> PanelClasses;
	UPROPERTY()						TArray<FString>			PanelCaptions;				//var localized TArray<FString> PanelCaptions;
	UPROPERTY()						TArray<FString>			PanelHints;					//var localized TArray<FString> PanelHints;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
