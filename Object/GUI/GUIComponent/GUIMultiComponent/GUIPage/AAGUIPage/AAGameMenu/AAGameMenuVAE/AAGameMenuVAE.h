// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu/AAGameMenu.h"
#include "AAGameMenuVAE.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UAAGameMenuVAE : public UAAGameMenu
{
	GENERATED_BODY()
public:
	UAAGameMenuVAE();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);

};
