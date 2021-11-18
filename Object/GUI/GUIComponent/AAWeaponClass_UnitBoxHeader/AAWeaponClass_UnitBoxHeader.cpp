// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/AAWeaponClass_UnitBoxHeader/AAWeaponClass_UnitBoxHeader.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAAWeaponClass_UnitBoxHeader::UAAWeaponClass_UnitBoxHeader()
{
	ColumnHeadings = { "Class","Player Name","" };
	ColumnWidths = {0.1f, 0.3f, 0.6};
	BarStyleName = "SectionHeaderBar";
	StyleName = "ScoreboardHeader";
	RenderWeight = 2;
	bRequiresStyle = true;
}
void UAAWeaponClass_UnitBoxHeader::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local GUI.eFontScale X;
	local int i;
	local float AW;
	InitComponent(MyController, MyOwner);
	if (BarStyleName != "")
	{
		BarStyle = Controller.GetStyle(BarStyleName, X);
	}
	AW = ActualWidth();
	for (i = 0; i < ColumnWidths.Length; i++)
	{
		ColumnWidths[i] *= AW;
	}
	*/
}