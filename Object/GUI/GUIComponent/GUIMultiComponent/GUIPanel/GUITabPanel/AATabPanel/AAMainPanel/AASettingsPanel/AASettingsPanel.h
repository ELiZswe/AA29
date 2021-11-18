// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAMainPanel.h"
#include "AASettingsPanel.generated.h"

class UGUIButton;
class USettings_Tabs;

UCLASS(Config = Game)
class AA29_API UAASettingsPanel : public UAAMainPanel
{
	GENERATED_BODY()
public:
	UAASettingsPanel();

	UPROPERTY(EditAnywhere, config)		bool						bApplyImmediately;			//var() config bool bApplyImmediately;
	UPROPERTY(EditAnywhere)				float						SavedPitch;					//var() editconst noexport float SavedPitch;
	UPROPERTY(EditAnywhere)				FString						PageCaption;				//var() FString PageCaption;
	UPROPERTY(EditAnywhere)				UGUIButton*					SizingButton;				//var() XInterface.GUIButton SizingButton;
	UPROPERTY(EditAnywhere)				USettings_Tabs*				ActivePanel;				//var() Settings_Tabs ActivePanel;
	UPROPERTY()							FString						InvalidStats;				//var localized FString InvalidStats;
};
