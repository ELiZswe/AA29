// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/AAMultiColumnListBox/AAMultiColumnListBox.h"

UAAMultiColumnListBox::UAAMultiColumnListBox()
{
	//DefaultListClass = "AGP_Interface.AAMultiColumnList";
}

void UAAMultiColumnListBox::OnGetSortString(UGUIComponent* Sender, int32 Item, int32 Column)
{
}

void UAAMultiColumnListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	InitBaseList(LocalList);
	AAMultiColumnList(List).__OnGetSortString__Delegate = InternalOnGetSortString;
	*/
}

void UAAMultiColumnListBox::InternalOnGetSortString(UGUIComponent* Sender, int32 Item, int32 Column)
{
	//Return OnGetSortString(Self, Item, Column);
}