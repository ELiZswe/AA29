// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAIRC_NewNick/AAIRC_NewNick.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"

UAAIRC_NewNick::UAAIRC_NewNick()
{
	EditCaption = "New Nickname: ";
	EditHint = "Enter your desired nick, then press OK to save the changes.";
	//OnCreateComponent = AAIRC_NewNick.InternalOnCreateComponent;
}

void UAAIRC_NewNick::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	ed_Data.SetText("");
	ed_Data.WinWidth = 0.5;
	ed_Data.WinHeight = 0.047305;
	ed_Data.WinLeft = 0.25;
	ed_Data.SetCaption(EditCaption);
	ed_Data.SetHint(EditHint);
	*/
}

void UAAIRC_NewNick::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Owner)
{
	/*
	if (Cast<UmoEditBox>(NewComp) != nullptr)
	{
		Cast<UmoEditBox>(NewComp).LabelJustification = 1;
		Cast<UmoEditBox>(NewComp).ComponentJustification = 1;
		Cast<UmoEditBox>(NewComp).CaptionWidth = 0.55;
		Cast<UmoEditBox>(NewComp).ComponentWidth = -1;
	}
	*/
}
