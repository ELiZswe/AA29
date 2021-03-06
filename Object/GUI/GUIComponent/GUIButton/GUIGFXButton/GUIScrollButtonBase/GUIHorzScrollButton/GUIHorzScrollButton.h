// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIScrollButtonBase.h"
#include "GUIHorzScrollButton.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UGUIHorzScrollButton : public UGUIScrollButtonBase
{
	GENERATED_BODY()
public:
	UGUIHorzScrollButton();

	UPROPERTY()											bool LeftButton;							//var() bool LeftButton;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
