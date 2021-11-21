// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2QuitPage/UT2QuitPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2QuitPage::UUT2QuitPage()
{
	UGUIButton* NoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	NoButton->Caption = "NO";
	NoButton->WinTop = 0.75;
	NoButton->WinLeft = 0.65;
	NoButton->WinWidth = 0.2;
	NoButton->bBoundToParent = true;
	//NoButton->OnClick=UT2QuitPage.InternalOnClick;
	//NoButton->OnKeyEvent=NoButton.InternalOnKeyEvent;
	UGUIButton* YesButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	YesButton->Caption = "YES";
	YesButton->WinTop = 0.75;
	YesButton->WinLeft = 0.125;
	YesButton->WinWidth = 0.2;
	YesButton->bBoundToParent = true;
	//YesButton->OnClick=UT2QuitPage.InternalOnClick;
	//YesButton->OnKeyEvent=YesButton.InternalOnKeyEvent;
	UGUIButton* QuitBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitBackground->StyleName = "SquareBar";
	QuitBackground->WinHeight = 1;
	QuitBackground->bBoundToParent = true;
	QuitBackground->bScaleToParent = true;
	QuitBackground->bAcceptsInput = false;
	QuitBackground->bNeverFocus = true;
	//QuitBackground->OnKeyEvent=QuitBackground.InternalOnKeyEvent;
	UGUILabel* QuitDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	QuitDesc->Caption = "Are you sure you wish to quit?";
	QuitDesc->TextAlign = ETextAlign::TXTA_Center;
	QuitDesc->TextColor = FColor(0, 180, 220, 255);
	QuitDesc->TextFont = "UT2HeaderFont";
	QuitDesc->WinTop = 0.4;
	QuitDesc->WinHeight = 32;
	bRequire640x480 = false;
	Controls = { QuitBackground,YesButton,NoButton,QuitDesc };
	WinTop = 0.375;
	WinHeight = 0.25;
}

bool UUT2QuitPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == Controls[1])
	{
		if (PlayerOwner().Level.IsDemoBuild())
		{
			Controller.ReplaceMenu("XInterface.UT2DemoQuitPage");
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