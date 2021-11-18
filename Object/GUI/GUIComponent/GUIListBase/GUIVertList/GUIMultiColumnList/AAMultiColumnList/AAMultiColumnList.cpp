// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAMultiColumnList/AAMultiColumnList.h"

UAAMultiColumnList::UAAMultiColumnList()
{
	//__GetSortString__Delegate = "AAMultiColumnList.InternalGetSortString"
}

void UAAMultiColumnList::OnGetSortString(AGUIComponent* Sender, int32 Item, int32 Column)
{
}

void UAAMultiColumnList::InternalGetSortString(int32 i)
{
	//Return OnGetSortString(Self, i, SortColumn);
}
