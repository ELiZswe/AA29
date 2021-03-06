// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moRadioButtonGroup.generated.h"

class UGUIRadioButtonGroup;
class UmoRadioButton;

class UGUIComponent;
class UGUIController;
UCLASS()
class UmoRadioButtonGroup : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoRadioButtonGroup();

	UPROPERTY()		UGUIRadioButtonGroup*		MyRadioButtonGroup;				//var UGUIRadioButtonGroup* MyRadioButtonGroup;
	UPROPERTY()		UmoRadioButton*				SelectedButton;					//var UmoRadioButton* SelectedButton;
	UPROPERTY()		FString						_iTracerGroupNameTagCount;		//var localized FString GroupNameTag;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
