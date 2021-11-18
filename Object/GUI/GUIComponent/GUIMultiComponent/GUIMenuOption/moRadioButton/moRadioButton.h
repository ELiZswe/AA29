// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moRadioButton.generated.h"

class UGUIRadioButtonButton;
class UmoRadioButtonGroup;

UCLASS()
class AA29_API UmoRadioButton : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoRadioButton();


	UPROPERTY()						UGUIRadioButtonButton*		MyRadioButton;			//var GUIRadioButtonButton MyRadioButton;
	UPROPERTY()						UmoRadioButtonGroup*		Group;					//var moRadioButtonGroup Group;
	UPROPERTY()						bool						bSelected;				//var bool bSelected;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool IsSelected();
	bool Select(bool S);
	
};
