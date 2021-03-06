// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/GUIArrayPropPage/MOTDConfigPage/MOTDConfigPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/AltSectionBackground/AltSectionBackground.h"

UMOTDConfigPage::UMOTDConfigPage()
{
	Delim = "|";
	WinTop = 0.21875;
	WinLeft = 0.166992;
	WinWidth = 0.68457;
	WinHeight = 0.509375;
}

void UMOTDConfigPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	sb_Bk1->WinWidth = 0.621875;
	sb_Bk1->WinHeight = 0.340625;
	sb_Bk1->WinLeft = 0.04375;
	sb_Bk1->WinTop = 0.116666;
	sb_Bk1->TopPadding = 0.01;
	sb_Bk1->LeftPadding = 0.01;
	sb_Bk1->RightPadding = 0.01;
}

void UMOTDConfigPage::SetOwner(UGUIComponent* NewOwner)
{
	Super::SetOwner(NewOwner);
	PropValue.SetNum(4);
}

FString UMOTDConfigPage::GetDataString()
{
	return FString::Join(PropValue, TEXT("|"));
}

void UMOTDConfigPage::SetItemOptions(UGUIMenuOption* mo)
{
	UmoEditBox* ed = nullptr;
	ed = Cast<UmoEditBox>(mo);
	if (ed != nullptr)
	{
		ed->MyEditBox->MaxWidth = 60;
	}
}
