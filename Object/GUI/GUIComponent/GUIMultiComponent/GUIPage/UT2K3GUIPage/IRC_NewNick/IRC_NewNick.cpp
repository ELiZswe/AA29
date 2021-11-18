// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/IRC_NewNick/IRC_NewNick.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UIRC_NewNick::UIRC_NewNick()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.75;
	OkButton->WinLeft = 0.4;
	OkButton->WinWidth = 0.2;
	OkButton->bBoundToParent = true;
	//OkButton->OnClick=IRC_NewNick.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UmoEditBox* NewNickEntry = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	NewNickEntry->LabelJustification = EeTextAlign::TXTA_Right;
	NewNickEntry->CaptionWidth = 0.55;
	NewNickEntry->Caption = "New Nickname: ";
	NewNickEntry->LabelFont = "UT2SmallFont";
	NewNickEntry->LabelColor = FColor(255, 255, 255, 255);
	//NewNickEntry->OnCreateComponent=NewNickEntry.InternalOnCreateComponent;
	NewNickEntry->WinTop = 0.466667;
	NewNickEntry->WinLeft = 0.16;
	NewNickEntry->WinHeight = 0.05;
	UGUIButton* VidOKBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VidOKBackground->StyleName = "SquareBar";
	VidOKBackground->WinHeight = 1;
	VidOKBackground->bBoundToParent = true;
	VidOKBackground->bScaleToParent = true;
	VidOKBackground->bAcceptsInput = false;
	VidOKBackground->bNeverFocus = true;
	//VidOKBackground->OnKeyEvent=VidOKBackground.InternalOnKeyEvent;
	UGUILabel* NickMesg = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NickMesg->TextAlign = ETextAlign::TXTA_Center;
	NickMesg->TextColor = FColor(0, 200, 230, 255);
	NickMesg->TextFont = "UT2HeaderFont";
	NickMesg->WinTop = 0.4;
	NickMesg->WinHeight = 32;
	Controls = { VidOKBackground,NewNickEntry,NickMesg,OkButton };
	WinTop = 0.375;
	WinHeight = 0.25;
}

void UIRC_NewNick::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyNewNick = moEditBox(Controls[1]);
	NewNickPrompt = GUILabel(Controls[2]);
	MyNewNick.SetText("");
	*/
}

bool UIRC_NewNick::InternalOnClick(UGUIComponent* Sender)
{
	/*
	FString NewNick = "";
	if (Sender == Controls[3])
	{
		NewNick = MyNewNick.GetText();
		if (NewNick == "")
		{
			return true;
		}
		Log("NewNick " $ NewNick);
		SystemPage.link.SendCommandText("NICK " $ NewNick);
	}
	Controller.CloseMenu(false);
	*/
	return true;
}