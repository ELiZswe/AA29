// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAMultiColumnList/AAMultiColumnList.h"

UAAMultiColumnList::UAAMultiColumnList()
{
	//__GetSortString__Delegate = "AAMultiColumnList.InternalGetSortString"
}

FString UAAMultiColumnList::OnGetSortString(AGUIComponent* Sender, int32 Item, int32 Column)
{
	return "";
}

FString UAAMultiColumnList::InternalGetSortString(int32 i)
{
	//return OnGetSortString(this, i, SortColumn);
	return "FAKE";    //FAKE  /ELiZ
}
