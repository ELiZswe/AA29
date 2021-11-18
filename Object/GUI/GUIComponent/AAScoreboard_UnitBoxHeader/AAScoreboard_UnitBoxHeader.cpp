// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/AAScoreboard_UnitBoxHeader/AAScoreboard_UnitBoxHeader.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAAScoreboard_UnitBoxHeader::UAAScoreboard_UnitBoxHeader()
{
	ColumnHeadings = { "","Class","Player Name","Score","Goals","Leader","Enemy","KIA","ROE","Ping","",""	};
	ColumnWidths = { 0.025f,0.1f,0.3f,0.075f,0.075f,0.075f,0.075f,0.075f,0.075f,0.05f,0.05f,0.025f };
	BarStyleName = "SectionHeaderBar";
	StyleName = "ScoreboardHeader";
	RenderWeight = 2;
	bRequiresStyle = true;
}


void UAAScoreboard_UnitBoxHeader::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
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