// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AARealHeroesSubPanel.generated.h"

class UGUIContentBox;
class UGUIButton;

UCLASS()
class AA29_API UAARealHeroesSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAARealHeroesSubPanel();

	UPROPERTY(EditAnywhere)			UGUIButton*			btnVisitVRO;			//var() automated XInterface.GUIButton btnVisitVRO;
	UPROPERTY(EditAnywhere)			UGUIContentBox*		guicbPanel;				//var() automated GUIContentBox guicbPanel;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);
};
