// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AASupportSubPanel.generated.h"

class UGUIScrollTextBox;

class UGUIComponent;
class UGUIController;
UCLASS()
class UAASupportSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAASupportSubPanel();

	UPROPERTY(EditAnywhere)			UGUIScrollTextBox*		stb_Panel;						//var() automated XInterface.GUIScrollTextBox stb_Panel;
	UPROPERTY(EditAnywhere)			FString					SupportFile;					//var FString SupportFile;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
