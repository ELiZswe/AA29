// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AAEverySoldierIsASensorSubpanel.generated.h"

class UGUIComponent;
class UGUIContentBox;
class UGUIController;
UCLASS()
class UAAEverySoldierIsASensorSubpanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAAEverySoldierIsASensorSubpanel();

	UPROPERTY(EditAnywhere)			UGUIContentBox* guicbPanel;					//var() automated GUIContentBox guicbPanel;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
