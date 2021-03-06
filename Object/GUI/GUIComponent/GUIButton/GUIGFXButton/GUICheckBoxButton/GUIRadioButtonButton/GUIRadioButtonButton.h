// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUICheckBoxButton.h"
#include "GUIRadioButtonButton.generated.h"

class UGUIRadioButtonGroup;

class UGUIComponent;
UCLASS()
class UGUIRadioButtonButton : public UGUICheckBoxButton
{
	GENERATED_BODY()
public:
	UGUIRadioButtonButton();

	UPROPERTY()														UGUIRadioButtonGroup* Group;								//var GUIRadioButtonGroup Group;

	bool InternalOnClick(UGUIComponent* Sender);

};
