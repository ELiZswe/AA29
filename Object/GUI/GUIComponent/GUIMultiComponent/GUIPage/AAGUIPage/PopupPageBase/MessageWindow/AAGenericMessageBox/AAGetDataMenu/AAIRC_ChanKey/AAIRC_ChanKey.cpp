// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAIRC_ChanKey/AAIRC_ChanKey.h"

UAAIRC_ChanKey::UAAIRC_ChanKey()
{
	EditCaption = "Channel key: ";
	EditHint = "Enter the channel key";
	msgCaption = "%chan% is protected with a key.";
	//OnCreateComponent = AAIRC_ChanKey.InternalOnCreateComponent;
}

void UAAIRC_ChanKey::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
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

void UAAIRC_ChanKey::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Owner)
{
	/*
	if (moEditBox(NewComp) != None)
	{
		moEditBox(NewComp).LabelJustification = 2;
		moEditBox(NewComp).CaptionWidth = 0.55;
		moEditBox(NewComp).ComponentWidth = -1;
	}
	*/
}

void UAAIRC_ChanKey::HandleParameters(FString A, FString B)
{
	/*
	kchan = A;
	l_Text.Caption = Repl(msgCaption, "%chan%", A);
	*/
}

FString UAAIRC_ChanKey::GetDataString()
{
	//return kchan @ ed_Data.GetText();
	return "FAKE";    //FAKE   /ELiZ
}