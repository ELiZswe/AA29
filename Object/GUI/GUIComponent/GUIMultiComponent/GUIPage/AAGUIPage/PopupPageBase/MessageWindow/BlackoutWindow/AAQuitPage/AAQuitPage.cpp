// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AAQuitPage/AAQuitPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAQuitPage::UAAQuitPage()
{
	UGUIButton* cNoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cNoButton->Caption = "NO";
	cNoButton->StyleName = "SquareMenuButton";
	cNoButton->WinTop = 0.51;
	cNoButton->WinLeft = 0.6;
	cNoButton->WinWidth = 0.2;
	cNoButton->WinHeight = 0.053476;
	cNoButton->TabOrder = 1;
	//cNoButton->OnClick=AAQuitPage.InternalOnClick;
	//cNoButton->OnKeyEvent=cNoButton.InternalOnKeyEvent;
	UGUIButton* cYesButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cYesButton->Caption = "YES";
	cYesButton->StyleName = "SquareMenuButton";
	cYesButton->WinTop = 0.51;
	cYesButton->WinLeft = 0.2;
	cYesButton->WinWidth = 0.2;
	cYesButton->WinHeight = 0.053476;
	cYesButton->TabOrder = 0;
	//cYesButton->OnClick=AAQuitPage.InternalOnClick;
	//cYesButton->OnKeyEvent=cYesButton.InternalOnKeyEvent;
	UGUILabel* cQuitDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cQuitDesc->Caption = "Are you sure you wish to exit?";
	cQuitDesc->TextAlign = ETextAlign::TXTA_Center;
	cQuitDesc->TextColor = FColor(0, 180, 220, 255);
	cQuitDesc->TextFont = "AAFontHeader";
	cQuitDesc->WinTop = 0.25;
	cQuitDesc->WinHeight = 32;
	cQuitDesc->RenderWeight = 4;
	YesButton = cYesButton;
	NoButton = cNoButton;
	QuitDesc = cQuitDesc;
	//OnKeyEvent = AAQuitPage.InternalOnKeyEvent;
}

bool UAAQuitPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == YesButton)
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

bool UAAQuitPage::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (State == 3)
	{
		if (Key == 11)
		{
			InternalOnClick(NoButton);
		}
		else
		{
			if (Key == 13)
			{
				InternalOnClick(YesButton);
			}
		}
	}
	*/
	return false;
}
