// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIVertScrollButton/GUIVertScrollButton.h"
#include "GUIComboButton.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UGUIComboButton : public UGUIVertScrollButton
{
	GENERATED_BODY()
public:
	UGUIComboButton();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
