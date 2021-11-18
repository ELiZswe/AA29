// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AADisconnectOptionPage/AADisconnectOptionPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAADisconnectOptionPage::UAADisconnectOptionPage()
{
	UGUIButton* QuitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitButton->Caption = "EXIT GAME";
	QuitButton->FontScale = EFontScale::FNS_Small;
	QuitButton->WinTop = 0.57;
	QuitButton->WinLeft = 0.565;
	QuitButton->WinWidth = 0.155;
	QuitButton->WinHeight = 0.035;
	QuitButton->TabOrder = 3;
	//QuitButton->OnClick=AADisconnectOptionPage.InternalOnClick;
	//QuitButton->OnKeyEvent=QuitButton.InternalOnKeyEvent;
	UGUIButton* ServerBrowserButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ServerBrowserButton->Caption = "SERVER BROWSER";
	ServerBrowserButton->FontScale = EFontScale::FNS_Small;
	ServerBrowserButton->WinTop = 0.51;
	ServerBrowserButton->WinLeft = 0.565;
	ServerBrowserButton->WinWidth = 0.155;
	ServerBrowserButton->WinHeight = 0.035;
	ServerBrowserButton->TabOrder = 2;
	//ServerBrowserButton->OnClick=AADisconnectOptionPage.InternalOnClick;
	//ServerBrowserButton->OnKeyEvent=ServerBrowserButton.InternalOnKeyEvent;
	UGUIButton* MainMenuButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MainMenuButton->Caption = "MAIN MENU";
	MainMenuButton->FontScale = EFontScale::FNS_Small;
	MainMenuButton->WinTop = 0.57;
	MainMenuButton->WinLeft = 0.29;
	MainMenuButton->WinWidth = 0.155;
	MainMenuButton->WinHeight = 0.035;
	MainMenuButton->TabOrder = 1;
	//MainMenuButton->OnClick=AADisconnectOptionPage.InternalOnClick;
	//MainMenuButton->OnKeyEvent=MainMenuButton.InternalOnKeyEvent;
	UGUIButton* ReconnectButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ReconnectButton->Caption = "RECONNECT";
	ReconnectButton->FontScale = EFontScale::FNS_Small;
	ReconnectButton->WinTop = 0.51;
	ReconnectButton->WinLeft = 0.29;
	ReconnectButton->WinWidth = 0.155;
	ReconnectButton->WinHeight = 0.035;
	ReconnectButton->TabOrder = 0;
	//ReconnectButton->OnClick=AADisconnectOptionPage.InternalOnClick;
	//ReconnectButton->OnKeyEvent=ReconnectButton.InternalOnKeyEvent;
	UGUILabel* cNetStatLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cNetStatLabel->Caption = "Select an option";
	cNetStatLabel->TextAlign = ETextAlign::TXTA_Center;
	cNetStatLabel->bMultiLine = true;
	cNetStatLabel->FontScale = EFontScale::FNS_Large;
	cNetStatLabel->StyleName = "TextLabel";
	cNetStatLabel->WinTop = 0.4;
	cNetStatLabel->WinHeight = 0.1;
	b_MainMenu = MainMenuButton;
	b_ServerBrowser = ServerBrowserButton;
	b_Reconnect = ReconnectButton;
	b_Quit = QuitButton;
	l_Status = cNetStatLabel;
	bReconnectAllowed = true;
	bAllowedAsLast = true;
	//OnCanClose = AADisconnectOptionPage.CanClose;
	//OnKeyEvent = AADisconnectOptionPage.InternalOnKeyEvent;
}

void UAADisconnectOptionPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
	//PlayerOwner().ClearProgressMessages();
}

void UAADisconnectOptionPage::SetSizingCaption()
{
	/*
	FString S = "";
	local XInterface.GUIButton B;
	int32 i = 0;
	for (i = 0; i < Components.Length; i++)
	{
		B = GUIButton(Components[i]);
		if (B == None)
		{
		}
		if ((S == "") || (Len(B.Caption) > Len(S)))
		{
			S = B.Caption;
		}
	}
	for (i = 0; i < Components.Length; i++)
	{
		B = GUIButton(Components[i]);
		if (B == None)
		{
		}
		B.SizingCaption = S;
	}
	*/
}

void UAADisconnectOptionPage::HandleParameters(FString Param1, FString Param2)
{
	/*
	if ((Param1 != "") || (Param2 != ""))
	{
		Controller.ViewportOwner.Console.DelayedConsoleCommand("CANCEL");
	}
	if (InStr(Locs(Param1), "?failed") != -1)
	{
		bReconnectAllowed = false;
	}
	if (Param1 != "")
	{
		l_Status.Caption = Param1;
	}
	if (l_Status.Caption != "")
	{
		(l_Status.Caption $ = "|");
	}
	if (Param2 == "noreconnect")
	{
		bReconnectAllowed = false;
	}
	else
	{
		if (!(Param1 ~= Param2))
		{
			(l_Status.Caption $ = Param2);
		}
	}
	UpdateButtons();
	*/
}

void UAADisconnectOptionPage::UpdateButtons()
{
	/*
	if (bReconnectAllowed && (!PlayerOwner().Level.IsPendingConnection()))
	{
		b_Reconnect.EnableMe();
	}
	else
	{
		b_Reconnect.DisableMe();
	}
	*/
}

void UAADisconnectOptionPage::Opened(UGUIComponent* Sender)
{
	/*
	if (Controller != None)
	{
		Controller.ConsolidateMenus();
	}
	Super::Opened(Sender);
	*/
}

bool UAADisconnectOptionPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local XInterface.GUIController C;
	if (GUIButton(Sender) == None)
	{
		return false;
	}
	C = Controller;
	switch (GUIButton(Sender).Caption)
	{
	case b_MainMenu.Caption:
		AAGUIController(C).ReturnToMainMenu();
		return true;
	case b_ServerBrowser.Caption:
		if (PlayerOwner().Level.IsPendingConnection())
		{
			C.OpenMenu("AGP_Interface.AAMainMenu", AAGUIController(C).GetServerBrowserPanel());
			break;
		}
		C.CloseAll(true, true);
		C.RestoreMenus.Length = 0;
		C.OpenMenu("AGP_Interface.AAMainMenu", AAGUIController(C).GetServerBrowserPanel());
	}
	return true;
	case b_Quit.Caption:
		C.OpenMenu("AGP_Interface.AAExitPage");
		return true;
	case b_Reconnect.Caption:
		C.ViewportOwner.Console.DelayedConsoleCommand("Reconnect");
		C.CloseMenu(false);
		return true;
	default:
		return false;

	}
	*/
	return false;   //FAKE   /ELiZ
}

void UAADisconnectOptionPage::UpdateStatus(FString NewStatus)
{
	l_Status->Caption = NewStatus;
}

bool UAADisconnectOptionPage::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((Key == 13) && (State == 3))
	{
		return InternalOnClick(GUIButton(FocusedControl));
	}
	*/
	return false;
}

bool UAADisconnectOptionPage::NotifyLevelChange()
{
	return false;
}

bool UAADisconnectOptionPage::CanClose(bool bCancelled)
{
	/*
	if (((bCancelled && Controller.KeyPressed(27)) && (!PlayerOwner().Level.IsPendingConnection())) && PlayerOwner().Level.IsEntry())
	{
		return (Controller.Count() > 1);
	}
	*/
	return true;
}

bool UAADisconnectOptionPage::AllowOpen(FString MenuClass)
{
	/*
	if (MenuClass ~= "AGP_Interface.AADisconnectOptionPage")
	{
		return false;
	}
	else
	{
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ

}