// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_Tournament.generated.h"

class UGUIImage;


UCLASS()
class AA29_API UAAGameMenu_Tournament : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_Tournament();

	UPROPERTY(EditAnywhere)			UGUIImage* i_Background;						//var() automated XInterface.GUIImage i_Background;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
