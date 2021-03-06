// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiOptionListBox/GUIMultiOptionListBox.h"
#include "AAGUIExclusiveMultiOptionListBox.generated.h"

class UGUIMenuOption;
class UGUIMultiOptionList;
UCLASS()
class UAAGUIExclusiveMultiOptionListBox : public UGUIMultiOptionListBox
{
	GENERATED_BODY()
public:
	UAAGUIExclusiveMultiOptionListBox();

	void ListCreateComponent(UGUIMenuOption* NewComp, UGUIMultiOptionList* Sender);
};
