// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2DeferChangeRes/UT2DeferChangeRes.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2DeferChangeRes::UUT2DeferChangeRes()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.55;
	OkButton->WinLeft = 0.4;
	OkButton->WinWidth = 0.2;
	//OkButton->OnClick=UT2DeferChangeRes.InternalOnClick;
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
	DialogText->Caption = "The resolution you have chosen is lower than the minimum menu resolution.";
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->TextColor = FColor(0, 180, 220, 255);
	DialogText->WinTop = 0.4;
	DialogText->WinHeight = 32;
	UGUILabel* DialogText2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText2->Caption = "It will be applied when you next enter gameplay.";
	DialogText2->TextAlign = ETextAlign::TXTA_Center;
	DialogText2->TextColor = FColor(0, 180, 220, 255);
	DialogText2->WinTop = 0.45;
	DialogText2->WinHeight = 32;
	bRequire640x480 = false;
	Controls = { DialogBackground,OkButton,DialogText,DialogText2 };
	WinTop = 0.375;
	WinHeight = 0.25;
}

bool UUT2DeferChangeRes::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}