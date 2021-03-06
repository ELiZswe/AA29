// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIScrollButtonBase.h"
#include "GUIVertScrollButton.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UGUIVertScrollButton : public UGUIScrollButtonBase
{
	GENERATED_BODY()
public:
	UGUIVertScrollButton();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
