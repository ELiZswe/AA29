// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2BadCDKeyMsg/UT2BadCDKeyMsg.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2BadCDKeyMsg::UUT2BadCDKeyMsg()
{
	UGUIButton* BadCDOk = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BadCDOk->Caption = "OK";
	BadCDOk->StyleName = "MidGameButton";
	BadCDOk->WinTop = 0.675;
	BadCDOk->WinLeft = 0.375;
	BadCDOk->WinWidth = 0.25;
	BadCDOk->WinHeight = 0.05;
	BadCDOk->bBoundToParent = true;
	//BadCDOk->OnClick=UT2BadCDKeyMsg.InternalOnClick;
	//BadCDOk->OnKeyEvent=BadCDOk.InternalOnKeyEvent;
	UGUIButton* BadCDBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BadCDBackground->StyleName = "SquareBar";
	BadCDBackground->WinTop = 0.375;
	BadCDBackground->WinHeight = 0.25;
	BadCDBackground->bAcceptsInput = false;
	BadCDBackground->bNeverFocus = true;
	//BadCDBackground->OnKeyEvent=BadCDBackground.InternalOnKeyEvent;
	UGUILabel* BadCDLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BadCDLabel->Caption = "Your CD key is invalid or in use by another player";
	BadCDLabel->TextAlign = ETextAlign::TXTA_Center;
	BadCDLabel->TextColor = FColor(255, 255, 255, 255);
	BadCDLabel->TextFont = "UT2HeaderFont";
	BadCDLabel->bMultiLine = true;
	BadCDLabel->WinTop = 0.125;
	BadCDLabel->WinHeight = 0.5;
	BadCDLabel->bBoundToParent = true;
	bIgnoreEsc = true;
	bRequire640x480 = false;
	Controls = { BadCDBackground,BadCDOk,BadCDLabel };
	WinTop = 0.375;
	WinHeight = 0.25;
}

bool UUT2BadCDKeyMsg::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == Controls[1])
	{
		Controller.ReplaceMenu("xinterface.UT2MainMenu");
	}
	*/
	return true;
}