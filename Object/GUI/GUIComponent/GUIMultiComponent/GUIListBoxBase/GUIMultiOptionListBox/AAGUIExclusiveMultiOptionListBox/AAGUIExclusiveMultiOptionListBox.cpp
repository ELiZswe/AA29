// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiOptionListBox/AAGUIExclusiveMultiOptionListBox/AAGUIExclusiveMultiOptionListBox.h"

UAAGUIExclusiveMultiOptionListBox::UAAGUIExclusiveMultiOptionListBox()
{
	DefaultListClass = "AGP_Interface.AAGUIExclusiveMultiOptionList";
	bVisibleWhenEmpty = true;
}

void UAAGUIExclusiveMultiOptionListBox::ListCreateComponent(UGUIMenuOption* NewComp, UGUIMultiOptionList* Sender)
{
	/*
	ListCreateComponent(NewComp, Sender);
	NewComp.bFlipped = True;
	NewComp.ComponentJustification = 0;
	NewComp.LabelJustification = 2;
	NewComp.bAutoSizeCaption = False;
	NewComp.FontScale = 0;
	NewComp.ComponentClassName = "AGP_Interface.AAGUIExclusiveMultiOptionListItem";
	NewComp.StyleName = "AAGUITreeListItem";
	*/
}