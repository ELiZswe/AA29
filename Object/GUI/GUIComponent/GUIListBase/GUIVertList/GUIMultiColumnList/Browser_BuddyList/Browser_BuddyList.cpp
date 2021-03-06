// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_BuddyList/Browser_BuddyList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageBuddy.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "Engine/Canvas.h"

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
	float CellLeft = 0;
	float CellWidth = 0;
	/*
	if (bSelected)
	{
		SelStyle.Draw(Canvas, 3, X, Y - 2, W, H + 2);
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, MyBuddyPage.Buddies[i], FontScale);
	*/
}
