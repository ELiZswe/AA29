// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_BuddyList/AABrowser_BuddyList.h"



UAABrowser_BuddyList::UAABrowser_BuddyList()
{
	ColumnHeadings = { "Buddy Name" };
	InitColumnPerc = { 1 };
	ExpandLastColumn = true;
}

void UAABrowser_BuddyList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
}

FString UAABrowser_BuddyList::GetSortString(int32 i)
{
	return "";
}
