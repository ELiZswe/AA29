// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2StatsPrompt/UT2StatsPrompt.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2StatsPrompt::UUT2StatsPrompt()
{
	UGUIButton* NoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	NoButton->Caption = "NO";
	NoButton->WinTop = 0.81;
	NoButton->WinLeft = 0.65;
	NoButton->WinWidth = 0.2;
	NoButton->bBoundToParent = true;
	//NoButton->OnClick=UT2StatsPrompt.InternalOnClick;
	//NoButton->OnKeyEvent=NoButton.InternalOnKeyEvent;
	UGUIButton* YesButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	YesButton->Caption = "YES";
	YesButton->WinTop = 0.81;
	YesButton->WinLeft = 0.125;
	YesButton->WinWidth = 0.2;
	YesButton->bBoundToParent = true;
	//YesButton->OnClick=UT2StatsPrompt.InternalOnClick;
	//YesButton->OnKeyEvent=YesButton.InternalOnKeyEvent;
	UGUIButton* PromptBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PromptBackground->StyleName = "SquareBar";
	PromptBackground->WinHeight = 1;
	PromptBackground->bBoundToParent = true;
	PromptBackground->bScaleToParent = true;
	PromptBackground->bAcceptsInput = false;
	PromptBackground->bNeverFocus = true;
	//PromptBackground->OnKeyEvent=PromptBackground.InternalOnKeyEvent;
	UGUILabel* PromptHeader = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PromptHeader->Caption = "This server has UT2003stats ENABLED!";
	PromptHeader->TextAlign = ETextAlign::TXTA_Center;
	PromptHeader->TextColor = FColor(220, 220, 220, 255);
	PromptHeader->TextFont = "UT2HeaderFont";
	PromptHeader->bMultiLine = true;
	PromptHeader->WinTop = 0.354166;
	PromptHeader->WinHeight = 0.051563;
	UGUILabel* PromptDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PromptDesc->Caption = "You will only be able to join this server by turning on \"Track Stats\" and setting a unique Stats Username and Password. Currently you will only be able to connect to servers with stats DISABLED.||Would you like to configure your Stats Username and Password now?";
	PromptDesc->TextAlign = ETextAlign::TXTA_Center;
	PromptDesc->TextColor = FColor(0, 180, 220, 255);
	PromptDesc->bMultiLine = true;
	PromptDesc->WinTop = 0.422917;
	PromptDesc->WinHeight = 0.256251;
	//OnReOpen = UT2StatsPrompt.ReOpen;
	Controls = { PromptBackground,YesButton,NoButton,PromptHeader,PromptDesc };
	WinTop = 0.325;
	WinHeight = 0.325;
}

void UUT2StatsPrompt::OnStatsConfigured()
{
}

void UUT2StatsPrompt::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	PlayerOwner().ClearProgressMessages();
	*/
}

bool UUT2StatsPrompt::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local UT2SettingsPage SettingsPage;
	local GUITabControl Tabs;
	local moCheckBox Check;
	if (Sender == Controls[1])
	{
		Controller.OpenMenu("XInterface.UT2SettingsPage");
		SettingsPage = UT2SettingsPage(Controller.ActivePage);
		Assert((SettingsPage != None));
		Tabs = GUITabControl(SettingsPage.Controls[1]);
		Tabs.ActivateTabByName(SettingsPage.NetworkTabLabel, true);
		Check = moCheckBox(SettingsPage.pNetwork.Controls[5]);
		if ((Check != None) && (!Check.IsChecked()))
		{
			Check.Checked(true);
			SettingsPage.pNetwork.Controls[2].SetFocus(None);
		}
	}
	else
	{
		Controller.CloseMenu(false);
	}
	*/
	return true;
}

void UUT2StatsPrompt::ReOpen()
{
	/*
	if ((Len(PlayerOwner().StatsUsername) >= 4) && (Len(PlayerOwner().StatsPassword) >= 6))
	{
		Controller.CloseMenu();
		OnStatsConfigured();
	}
	*/
}