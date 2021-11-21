// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2PerformWarn/UT2PerformWarn.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2PerformWarn::UUT2PerformWarn()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.55;
	OkButton->WinLeft = 0.4;
	OkButton->WinWidth = 0.2;
	//OkButton->OnClick=UT2PerformWarn.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUIButton* DialogBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DialogBackground->StyleName = "ListBox";
	DialogBackground->WinHeight = 1;
	DialogBackground->bBoundToParent = true;
	DialogBackground->bScaleToParent = true;
	DialogBackground->bAcceptsInput = false;
	DialogBackground->bNeverFocus = true;
	//DialogBackground->OnKeyEvent=DialogBackground.InternalOnKeyEvent;
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText->Caption = "WARNING";
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->TextColor = FColor(106, 41, 14, 255);
	DialogText->TextFont = "UT2HeaderFont";
	DialogText->WinTop = 0.4;
	DialogText->WinHeight = 32;
	UGUILabel* DialogText2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText2->Caption = "The change you are making may adversely affect your performance.";
	DialogText2->TextAlign = ETextAlign::TXTA_Center;
	DialogText2->TextColor = FColor(106, 41, 14, 255);
	DialogText2->WinTop = 0.45;
	DialogText2->WinHeight = 32;
	bRequire640x480 = false;
	Controls = { DialogBackground,OkButton,DialogText,DialogText2 };
	WinTop = 0.375;
	WinHeight = 0.25;
}

bool UUT2PerformWarn::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}