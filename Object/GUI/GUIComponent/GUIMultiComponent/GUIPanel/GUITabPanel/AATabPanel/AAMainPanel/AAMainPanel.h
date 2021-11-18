// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATabPanel.h"
#include "AAMainPanel.generated.h"

class UAAGUITabControl;

UCLASS()
class AA29_API UAAMainPanel : public UAATabPanel
{
	GENERATED_BODY()
public:
	UAAMainPanel();

	UPROPERTY(EditAnywhere)			UAAGUITabControl*					c_Tabs;				//var() automated AAGUITabControl c_Tabs;
	UPROPERTY()						TArray<FString>						PanelClasses;		//var TArray<FString> PanelClasses;
	UPROPERTY()						TArray<FString>						PanelCaptions;		//var localized TArray<FString> PanelCaptions;
	UPROPERTY()						TArray<FString>						PanelHints;			//var localized TArray<FString> PanelHints;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnChange(UGUIComponent* Sender);
	void HandleParameters(FString Param1, FString Param2);
	bool GetRestoreParams(FString& Param1, FString& Param2);
};
