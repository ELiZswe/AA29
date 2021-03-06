// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiOptionList/AAGUIExclusiveMultiOptionList/AAGUIExclusiveMultiOptionList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"

UAAGUIExclusiveMultiOptionList::UAAGUIExclusiveMultiOptionList()
{
	ItemScaling = 0.09;
	ItemStyleName = "AAGUITreeListItem";
	SelectedStyleName = "AAGUITreeListSelected";
}

void UAAGUIExclusiveMultiOptionList::OnItemSelection(UGUIMenuOption* Item)
{
}

void UAAGUIExclusiveMultiOptionList::OnItemDeselection(UGUIMenuOption* Item)
{
}

void UAAGUIExclusiveMultiOptionList::Clear()
{
	CurrentlySelectedOption = nullptr;
	Super::Clear();
}

void UAAGUIExclusiveMultiOptionList::InternalOnChange(UGUIComponent* Sender)
{
	UGUIMenuOption* PreviouslySelectedOption = nullptr;
	/*
	PreviouslySelectedOption = CurrentlySelectedOption;
	if ((CurrentlySelectedOption != nullptr) && (Sender != CurrentlySelectedOption))
	{
		CurrentlySelectedOption.SetComponentValue(string(false), true);
		OnItemDeselection(CurrentlySelectedOption);
		CurrentlySelectedOption = nullptr;
	}
	Super::InternalOnChange(Sender);
	if ((CurrentlySelectedOption != nullptr) && (Sender == CurrentlySelectedOption))
	{
		OnItemDeselection(CurrentlySelectedOption);
		CurrentlySelectedOption = nullptr;
	}
	if (Sender != PreviouslySelectedOption)
	{
		OnItemSelection(Cast<UGUIMenuOption>(Sender));
		CurrentlySelectedOption = GUIMenuOption(Sender);
	}
	*/
}
