// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIContentBoxHeader/GUIContentBoxHeader.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"

UGUIContentBoxHeader::UGUIContentBoxHeader()
{
	ColumnHeadings = { "Class","Player Name","" };
	ColumnWidths = { 0.1,0.3,0.6 };
	BarStyleName = "SectionHeaderBar";
	StyleName = "ScoreboardHeader";
	RenderWeight = 2;
	bRequiresStyle = true;
}

void UGUIContentBoxHeader::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	EeFontScale X = EeFontScale::FNS_Small;
	int32 i = 0;
	float AW = 0;
	Super::InitComponent(MyController, MyOwner);

	if (BarStyleName != "")
	{
		BarStyle = Controller->GetStyle(BarStyleName, X);
	}
	AW = ActualWidth(0, false);
	for (i = 0; i < ColumnWidths.Max(); i++)
	{
		ColumnWidths[i] *= AW;
	}
}
