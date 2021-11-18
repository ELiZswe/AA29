// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_BuddyList/Browser_BuddyList.h"

UBrowser_BuddyList::UBrowser_BuddyList()
{
	ColumnHeadings = { "Buddy Name" };
	InitColumnPerc = { 1 };
	ExpandLastColumn = true;
}

void UBrowser_BuddyList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	__OnDrawItem__Delegate = MyOnDrawItem;
	SelStyle = Controller.GetStyle("SquareButton", FontScale);
	*/
}
void UBrowser_BuddyList::MyOnDrawItem(UCanvas* Canvas, int i32, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	if (bSelected)
	{
		SelStyle.Draw(Canvas, 3, X, Y - 2, W, H + 2);
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, MyBuddyPage.Buddies[i], FontScale);
	*/
}