// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AAExternalLinkPage/AAExternalLinkPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAExternalLinkPage::UAAExternalLinkPage()
{
	UGUIButton* cNoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cNoButton->Caption = "CANCEL";
	cNoButton->StyleName = "SquareMenuButton";
	cNoButton->WinTop = 0.6;
	cNoButton->WinLeft = 0.599;
	cNoButton->WinWidth = 0.126;
	cNoButton->WinHeight = 0.035;
	cNoButton->TabOrder = 1;
	//cNoButton->OnClick=AAExternalLinkPage.InternalOnClick;
	//cNoButton->OnKeyEvent=cNoButton.InternalOnKeyEvent;
	UGUIButton* cYesButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cYesButton->Caption = "OK";
	cYesButton->StyleName = "SquareMenuButton";
	cYesButton->WinTop = 0.6;
	cYesButton->WinLeft = 0.275;
	cYesButton->WinWidth = 0.126;
	cYesButton->WinHeight = 0.035;
	cYesButton->TabOrder = 0;
	//cYesButton->OnClick=AAExternalLinkPage.InternalOnClick;
	//cYesButton->OnKeyEvent=cYesButton.InternalOnKeyEvent;
	UGUILabel* cLinkDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cLinkDesc->Caption = "Launch an external link in your web browser?";
	cLinkDesc->TextAlign = ETextAlign::TXTA_Center;
	cLinkDesc->TextColor = FColor(229, 248, 251, 255);
	cLinkDesc->TextFont = "AAFontHeader";
	cLinkDesc->WinTop = 0.375;
	cLinkDesc->WinHeight = 32;
	cLinkDesc->RenderWeight = 4;
	UGUILabel* cURLDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cURLDesc->TextAlign = ETextAlign::TXTA_Center;
	cURLDesc->TextColor = FColor(52, 180, 217, 255);
	cURLDesc->TextFont = "AAFontMedium";
	cURLDesc->bMultiLine = true;
	cURLDesc->WinTop = 0.425;
	cURLDesc->WinLeft = 0.2;
	cURLDesc->WinWidth = 0.6;
	cURLDesc->WinHeight = 0.75;
	cURLDesc->RenderWeight = 4;
	YesButton = cYesButton;
	NoButton = cNoButton;
	LinkDesc = cLinkDesc;
	URLDesc = cURLDesc;
	//OnKeyEvent = AAExternalLinkPage.InternalOnKeyEvent;
}

bool UAAExternalLinkPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == YesButton)
	{
		LaunchURL(Self);
		Controller.CloseMenu(false);
	}
	else
	{
		Controller.CloseMenu(false);
	}
	*/
	return true;
}

bool UAAExternalLinkPage::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
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

void UAAExternalLinkPage::HandleParameters(FString Param1, FString Param2)
{
	/*
	Super::HandleParameters(Param1, Param2);
	URLDesc.Caption = Param1;
	LinkURL = Param2;
	*/
}

bool UAAExternalLinkPage::LaunchURL(UGUIComponent* Sender)
{
	/*
	FString ClickString = "";
	ClickString = StripColorCodes(LinkURL);
	Controller.ConsoleCommand("start" @ ClickString);
	*/
	return true;
}