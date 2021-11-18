// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AAExitPage/AAExitPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAExitPage::UAAExitPage()
{
	UGUIButton* cCancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cCancelButton->Caption = "CANCEL";
	cCancelButton->FontScale = EFontScale::FNS_Small;
	cCancelButton->WinTop = 0.65;
	cCancelButton->WinLeft = 0.6;
	cCancelButton->WinWidth = 0.15;
	cCancelButton->WinHeight = 0.086;
	cCancelButton->TabOrder = 0;
	cCancelButton->bBoundToParent = true;
	cCancelButton->bScaleToParent = true;
	//cCancelButton->OnClick=AAExitPage.InternalOnClick;
	//cCancelButton->OnKeyEvent=cCancelButton.InternalOnKeyEvent;
	UGUIButton* cExitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cExitButton->Caption = "EXIT";
	cExitButton->FontScale = EFontScale::FNS_Small;
	cExitButton->WinTop = 0.65;
	cExitButton->WinLeft = 0.25;
	cExitButton->WinWidth = 0.15;
	cExitButton->WinHeight = 0.086;
	cExitButton->TabOrder = 1;
	cExitButton->bBoundToParent = true;
	cExitButton->bScaleToParent = true;
	//cExitButton->OnClick=AAExitPage.InternalOnClick;
	//cExitButton->OnKeyEvent=cExitButton.InternalOnKeyEvent;
	UGUILabel* cExitDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cExitDesc->Caption = "Are you sure you wish to exit?";
	cExitDesc->TextAlign = ETextAlign::TXTA_Center;
	cExitDesc->TextColor = FColor(0, 180, 220, 255);
	cExitDesc->TextFont = "AAFontHeader";
	cExitDesc->WinTop = 0.3;
	cExitDesc->WinHeight = 32;
	cExitDesc->RenderWeight = 4;
	cExitDesc->bBoundToParent = true;
	cExitDesc->bScaleToParent = true;
	ExitButton = cExitButton;
	CancelButton = cCancelButton;
	ExitDesc = cExitDesc;
	//OnKeyEvent = AAExitPage.InternalOnKeyEvent;
}

bool UAAExitPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == ExitButton)
	{
		if (PlayerOwner().Level.IsDemoBuild())
		{
			Controller.ReplaceMenu("AGP_Interface.AADemoQuitPage");
		}
		else
		{
			PlayerOwner().ConsoleCommand("exit");
		}
	}
	else
	{
		Controller.CloseMenu(false);
	}
	*/
	return true;
}

bool UAAExitPage::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (State == 3)
	{
		if (Key == 11)
		{
			InternalOnClick(CancelButton);
		}
		else
		{
			if (Key == 13)
			{
				InternalOnClick(ExitButton);
			}
		}
	}
	*/
	return false;
}