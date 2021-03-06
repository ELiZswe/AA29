// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGripButtonBase/GUIGripButtonBase.h"
#include "GUIVertGripButton.generated.h"

class UGUIController;

class UGUIComponent;
UCLASS()
class UGUIVertGripButton : public UGUIGripButtonBase
{
	GENERATED_BODY()
public:
	UGUIVertGripButton();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyComponent);
};
