// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AADeploy_Services.generated.h"

class UGUIContentBox;

UCLASS()
class AA29_API UAADeploy_Services : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_Services();

	UPROPERTY(EditAnywhere)			UGUIContentBox* guicbPanel;				//var() automated GUIContentBox guicbPanel;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
