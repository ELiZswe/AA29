// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/AAMultiColumnListBox/AAMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"

UAAMultiColumnListBox::UAAMultiColumnListBox()
{
	//DefaultListClass = "AGP_Interface.AAMultiColumnList";
}

FString UAAMultiColumnListBox::OnGetSortString(UGUIComponent* Sender, int32 Item, int32 Column)
{
	return "FAKE";    //FAKE   /EliZ
}

void UAAMultiColumnListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	InitBaseList(LocalList);
	AAMultiColumnList(List).__OnGetSortString__Delegate = InternalOnGetSortString;
	*/
}

FString UAAMultiColumnListBox::InternalOnGetSortString(UGUIComponent* Sender, int32 Item, int32 Column)
{
	return OnGetSortString(this, Item, Column);
}
