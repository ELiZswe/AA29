// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGenericMessageBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
UAAGenericMessageBox::UAAGenericMessageBox()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->FontScale = EFontScale::FNS_Small;
	OkButton->WinTop = 0.8;
	OkButton->WinLeft = 0.4375;
	OkButton->WinWidth = 0.155;
	OkButton->WinHeight = 0.08;
	OkButton->bBoundToParent = true;
	OkButton->bScaleToParent = true;
	//OkButton->OnClick=AAGenericMessageBox.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText->Caption = "WARNING";
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->VertAlign = ETextAlign::TXTA_Center;
	DialogText->FontScale = EFontScale::FNS_Large;
	DialogText->StyleName = "TextButton";
	DialogText->WinTop = 0.1;
	DialogText->WinLeft = 0.056771;
	DialogText->WinWidth = 0.884722;
	DialogText->WinHeight = 0.08;
	DialogText->bBoundToParent = true;
	DialogText->bScaleToParent = true;
	UGUILabel* DialogText2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText2->TextAlign = ETextAlign::TXTA_Center;
	DialogText2->bMultiLine = true;
	DialogText2->StyleName = "TextLabel";
	DialogText2->WinTop = 0.25;
	DialogText2->WinLeft = 0.04375;
	DialogText2->WinWidth = 0.9125;
	DialogText2->WinHeight = 0.5;
	DialogText2->bBoundToParent = true;
	DialogText2->bScaleToParent = true;
	b_OK = OkButton;
	l_Text = DialogText;
	l_Text2 = DialogText2;
	//OnKeyEvent = AAGenericMessageBox.InternalOnKeyEvent;
}

bool UAAGenericMessageBox::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}

void UAAGenericMessageBox::HandleParameters(FString Param1, FString Param2)
{
	/*
	if (Param1 != "")
	{
		l_Text.Caption = Param1;
	}
	if (Param2 != "")
	{
		l_Text2.Caption = Param2;
	}
	if (InStr(Caps(Param2), "PASSWORD") != -1)
	{
		Log("Resetting Internet server password.");
		class'AGP_Interface.AABrowser_ServersList'.SetServerPassword("");
	}
	*/
}

bool UAAGenericMessageBox::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((Key == 13) && (State == 3))
	{
		return InternalOnClick(b_OK);
	}
	*/
	return false;
}