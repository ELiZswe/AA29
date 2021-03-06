// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiColumnListHeader/GUIMultiColumnListHeader.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"

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
	EeFontScale X = EeFontScale::FNS_Small;
	Super::InitComponent(MyController, MyOwner);
	if (BarStyleName != "")
	{
		BarStyle = Controller->GetStyle(BarStyleName, X);
	}
}
