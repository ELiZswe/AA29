// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AABrowserSwitchWarningPage/AABrowserSwitchWarningPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAABrowserSwitchWarningPage::UAABrowserSwitchWarningPage()
{
	UmoCheckBox* cDisableWarning = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	cDisableWarning->ComponentJustification = EeTextAlign::TXTA_Center;
	cDisableWarning->Caption = "Do not show this warning again";
	//cDisableWarning->OnCreateComponent=cDisableWarning.InternalOnCreateComponent;
	cDisableWarning->FontScale = EFontScale::FNS_Small;
	cDisableWarning->WinTop = 0.55;
	cDisableWarning->WinLeft = 0.35;
	cDisableWarning->WinWidth = 0.3;
	cDisableWarning->WinHeight = 0.035;
	cDisableWarning->TabOrder = 2;
	cDisableWarning->bStandardized = false;
	UGUIButton* cNoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cNoButton->Caption = "CANCEL";
	cNoButton->StyleName = "SquareMenuButton";
	cNoButton->WinTop = 0.6;
	cNoButton->WinLeft = 0.6;
	cNoButton->WinWidth = 0.126;
	cNoButton->WinHeight = 0.035;
	cNoButton->TabOrder = 1;
	//cNoButton->OnClick=AABrowserSwitchWarningPage.InternalOnClick;
	//cNoButton->OnKeyEvent=cNoButton.InternalOnKeyEvent;
	UGUIButton* cYesButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cYesButton->Caption = "OK";
	cYesButton->StyleName = "SquareMenuButton";
	cYesButton->WinTop = 0.6;
	cYesButton->WinLeft = 0.274;
	cYesButton->WinWidth = 0.126;
	cYesButton->WinHeight = 0.035;
	cYesButton->TabOrder = 0;
	//cYesButton->OnClick=AABrowserSwitchWarningPage.InternalOnClick;
	//cYesButton->OnKeyEvent=cYesButton.InternalOnKeyEvent;
	UGUILabel* cWarningMessage = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cWarningMessage->Caption = "You are about to change your current Browser.  This will change the information that is displayed on your screen, change your server filtering capabilities and may result in a change of which game servers show up in the browser. Are you sure you wish to change your Internet game browser?";
	cWarningMessage->TextAlign = ETextAlign::TXTA_Center;
	cWarningMessage->TextColor = FColor(229, 248, 251, 255);
	cWarningMessage->TextFont = "AAFontSmall";
	cWarningMessage->bMultiLine = true;
	cWarningMessage->WinTop = 0.2;
	cWarningMessage->WinLeft = 0.1;
	cWarningMessage->WinWidth = 0.8;
	cWarningMessage->WinHeight = 0.8;
	cWarningMessage->RenderWeight = 4;
	cWarningMessage->bBoundToParent = true;
	cWarningMessage->bScaleToParent = true;
	YesButton = cYesButton;
	NoButton = cNoButton;
	WarningMessage = cWarningMessage;
	DisableWarning = cDisableWarning;
	//OnKeyEvent = AABrowserSwitchWarningPage.InternalOnKeyEvent;
}

void UAABrowserSwitchWarningPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	DisableWarning.Checked(Disabled);
	*/
}

bool UAABrowserSwitchWarningPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == YesButton)
	{
		Disabled = DisableWarning.IsChecked();
		SaveConfig();
		Controller.CloseMenu(false);
	}
	else
	{
		Controller.CloseMenu(true);
	}
	*/
	return true;
}

bool UAABrowserSwitchWarningPage::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
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