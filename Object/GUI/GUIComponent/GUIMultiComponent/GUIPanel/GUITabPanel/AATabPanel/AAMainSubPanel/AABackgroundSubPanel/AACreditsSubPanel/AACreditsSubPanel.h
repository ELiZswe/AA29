// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AACreditsSubPanel.generated.h"

class UGUIContentBox;

/**
 * 
 */
UCLASS()
class AA29_API UAACreditsSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAACreditsSubPanel();

	UPROPERTY(EditAnywhere)			UGUIContentBox*		guicbPanel;				//var() automated GUIContentBox guicbPanel;
	UPROPERTY(EditAnywhere)			FString				NMLPage;				//var FString NMLPage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
