// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiOptionList/GUIMultiOptionList.h"
#include "AAGUIExclusiveMultiOptionList.generated.h"

class UGUIMenuOption;

class UGUIComponent;
UCLASS()
class UAAGUIExclusiveMultiOptionList : public UGUIMultiOptionList
{
	GENERATED_BODY()
public:
	UAAGUIExclusiveMultiOptionList();

	UPROPERTY()			UGUIMenuOption*		CurrentlySelectedOption;				//var XInterface.GUIMenuOption* CurrentlySelectedOption;

	void OnItemSelection(UGUIMenuOption* Item);
	void OnItemDeselection(UGUIMenuOption* Item);
	void Clear();
	void InternalOnChange(UGUIComponent* Sender);
};
