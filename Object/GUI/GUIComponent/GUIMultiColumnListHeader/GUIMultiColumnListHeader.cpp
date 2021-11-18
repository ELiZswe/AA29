// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiColumnListHeader/GUIMultiColumnListHeader.h"

UGUIMultiColumnListHeader::UGUIMultiColumnListHeader()
{
	SizingCol = -1;
	ClickingCol = -1;
	BarStyleName = "SectionHeaderBar";
	StyleName = "SectionHeaderTop";
	bAcceptsInput = true;
	bRequiresStyle = true;
}



void UGUIMultiColumnListHeader::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local GUI.eFontScale X;
	InitComponent(MyController, MyOwner);
	if (BarStyleName != "")
	{
		BarStyle = Controller.GetStyle(BarStyleName, X);
	}
	*/
}