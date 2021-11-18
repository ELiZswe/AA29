// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAFavoritesOperationModalDialog/AAFavoritesOperationModalDialog.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAFavoritesOperationModalDialog::UAAFavoritesOperationModalDialog()
{
	UGUIButton* CloseButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CloseButton->Caption = "Close";
	CloseButton->FontScale = EFontScale::FNS_Small;
	CloseButton->WinTop = 0.8;
	CloseButton->WinLeft = 0.4375;
	CloseButton->WinWidth = 0.155;
	CloseButton->WinHeight = 0.08;
	CloseButton->bBoundToParent = true;
	CloseButton->bScaleToParent = true;
	//CloseButton->OnClick=AAFavoritesOperationModalDialog.InternalOnClick;
	//CloseButton->OnKeyEvent=CloseButton.InternalOnKeyEvent;
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->VertAlign = ETextAlign::TXTA_Center;
	DialogText->FontScale = EFontScale::FNS_Large;
	DialogText->StyleName = "TextButton";
	DialogText->WinTop = 0.389843;
	DialogText->WinLeft = 0.056771;
	DialogText->WinWidth = 0.884722;
	DialogText->WinHeight = 0.042149;
	UGUILabel* DialogText2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText2->TextAlign = ETextAlign::TXTA_Center;
	DialogText2->bMultiLine = true;
	DialogText2->StyleName = "TextLabel";
	DialogText2->WinTop = 0.431249;
	DialogText2->WinLeft = 0.04375;
	DialogText2->WinWidth = 0.9125;
	DialogText2->WinHeight = 0.126524;
	l_Text = DialogText;
	l_Text2 = DialogText2;
	MinimumAppearanceDuration = 2;
	b_Close = CloseButton;
	//OnOpen = AAFavoritesOperationModalDialog.InternalOnOpen;
	//OnCanClose = AAFavoritesOperationModalDialog.InternalOnCanClose;
	//OnTimer = AAFavoritesOperationModalDialog.InternalOnTimer;
	//OnKeyEvent = AAFavoritesOperationModalDialog.InternalOnKeyEvent;
}

void UAAFavoritesOperationModalDialog::HandleParameters(FString Param1, FString Param2)
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
	*/
}

void UAAFavoritesOperationModalDialog::InternalOnOpen()
{
	/*
	AppearanceDuration = 0;
	CloseRequested = false;
	SetTimer(0.1, true);
	b_Close.SetVisibility(false);
	*/
}

void UAAFavoritesOperationModalDialog::InternalOnTimer(UGUIComponent* Sender)
{
	/*
	(AppearanceDuration += 0.1);
	if (AppearanceDuration > 5)
	{
		b_Close.SetVisibility(true);
	}
	if (CloseRequested && (AppearanceDuration >= MinimumAppearanceDuration))
	{
		if (None != AAFavoritesOperationModalDialog(Controller.TopPage()))
		{
			Controller.CloseMenu();
		}
	}
	*/
}

bool UAAFavoritesOperationModalDialog::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_Close:
		Controller.CloseMenu(true);
		return true;
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool UAAFavoritesOperationModalDialog::InternalOnCanClose(bool Cancelled)
{
	/*
	if ((AppearanceDuration >= MinimumAppearanceDuration) || Cancelled)
	{
		return true;
	}
	CloseRequested = true;
	*/
	return false;
}

bool UAAFavoritesOperationModalDialog::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	return true;
}