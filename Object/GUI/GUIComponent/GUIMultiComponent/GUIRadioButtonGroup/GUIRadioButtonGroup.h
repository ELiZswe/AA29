// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIRadioButtonGroup.generated.h"

class UGUIRadioButtonButton;

UCLASS()
class AA29_API UGUIRadioButtonGroup : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIRadioButtonGroup();

	UPROPERTY()			UGUIRadioButtonButton*		SelectedButton;						//var GUIRadioButtonButton SelectedButton;
	UPROPERTY()			FString						GroupNameTag;						//var localized FString GroupNameTag;

	void OnSelectedButtonChange();
	bool ButtonClicked(UGUIComponent* Sender);

};
