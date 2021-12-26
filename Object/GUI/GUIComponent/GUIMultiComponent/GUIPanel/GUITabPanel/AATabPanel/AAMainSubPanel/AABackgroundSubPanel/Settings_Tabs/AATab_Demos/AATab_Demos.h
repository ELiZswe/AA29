// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/Settings_Tabs.h"
#include "AATab_Demos.generated.h"

class UGUIImage;
class UmoCheckBox;
class UmoEditBox;

UCLASS()
class UAATab_Demos : public USettings_Tabs
{
	GENERATED_BODY()
public:
	UAATab_Demos();

	UPROPERTY(EditAnywhere)			UGUIImage*		i_BG1;							//var() automated XInterface.GUIImage i_BG1;
	UPROPERTY(EditAnywhere)			UGUIImage*		i_BG2;							//var() automated XInterface.GUIImage i_BG2;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_Enable;						//var() automated XInterface.moCheckBox ch_Enable;
	UPROPERTY(EditAnywhere)			UmoEditBox*		ed_TriggerTime;					//var() automated XInterface.moEditBox ed_TriggerTime;
	UPROPERTY()						FString			sTriggerTime;					//var FString sTriggerTime;
	UPROPERTY()						bool			bEnableDemos;					//var bool bEnableDemos;
	UPROPERTY(EditAnywhere)			bool			bIgnoreChange;					//var() noexport bool bIgnoreChange;
	UPROPERTY(EditAnywhere)			FString			RelaunchQuestion;				//var() localized FString RelaunchQuestion;

	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnChange(UGUIComponent* Sender);
	bool EnableDemoModeClick(uint8 Btn);
	void SaveSettings();
};
