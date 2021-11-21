// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2MidGameMenu/UT2MidGameMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UUT2MidGameMenu::UUT2MidGameMenu()
{
	UGUIButton* BrowserButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserButton->Caption = "SERVER BROWSER";
	BrowserButton->StyleName = "MidGameButton";
	//BrowserButton->OnClick=UT2MidGameMenu.InternalOnClick;
	//BrowserButton->OnKeyEvent=BrowserButton.InternalOnKeyEvent;
	UGUIButton* AddFavoriteButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AddFavoriteButton->Caption = "ADD FAVORITE";
	AddFavoriteButton->StyleName = "MidGameButton";
	//AddFavoriteButton->OnClick=UT2MidGameMenu.InternalOnClick;
	//AddFavoriteButton->OnKeyEvent=AddFavoriteButton.InternalOnKeyEvent;
	UGUIButton* ChangeTeamButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ChangeTeamButton->Caption = "CHANGE TEAM";
	ChangeTeamButton->StyleName = "MidGameButton";
	//ChangeTeamButton->OnClick=UT2MidGameMenu.InternalOnClick;
	//ChangeTeamButton->OnKeyEvent=ChangeTeamButton.InternalOnKeyEvent;
	UGUIButton* SettingsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SettingsButton->Caption = "SETTINGS";
	SettingsButton->StyleName = "MidGameButton";
	//SettingsButton->OnClick=UT2MidGameMenu.InternalOnClick;
	//SettingsButton->OnKeyEvent=SettingsButton.InternalOnKeyEvent;
	UGUIButton* LeaveMatchButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LeaveMatchButton->StyleName = "MidGameButton";
	//LeaveMatchButton->OnClick=UT2MidGameMenu.InternalOnClick;
	//LeaveMatchButton->OnKeyEvent=LeaveMatchButton.InternalOnKeyEvent;
	UGUIButton* QuitGameButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitGameButton->Caption = "EXIT UT2003";
	QuitGameButton->StyleName = "MidGameButton";
	//QuitGameButton->OnClick=UT2MidGameMenu.InternalOnClick;
	//QuitGameButton->OnKeyEvent=QuitGameButton.InternalOnKeyEvent;
	UGUIButton* ContMatchButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ContMatchButton->Caption = "CONTINUE";
	ContMatchButton->StyleName = "MidGameButton";
	//ContMatchButton->OnClick=UT2MidGameMenu.InternalOnClick;
	//ContMatchButton->OnKeyEvent=ContMatchButton.InternalOnKeyEvent;
	UGUIButton* QuitBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitBackground->StyleName = "SquareBar";
	QuitBackground->bAcceptsInput = false;
	QuitBackground->bNeverFocus = true;
	//QuitBackground->OnKeyEvent=QuitBackground.InternalOnKeyEvent;
	bIgnoreEsc = true;
	LeaveMPButtonText = "DISCONNECT";
	LeaveSPButtonText = "FORFEIT";
	LeaveEntryButtonText = "SERVER BROWSER";
	ButtonWidth = 0.27;
	ButtonHeight = 0.04;
	ButtonHGap = 0.02;
	ButtonVGap = 0.02;
	BarHeight = 0.21;
	BarVPos = 0.5;
	bRequire640x480 = false;
	bAllowedAsLast = true;
	Controls = { QuitBackground,ContMatchButton,QuitGameButton,LeaveMatchButton,SettingsButton,ChangeTeamButton,AddFavoriteButton,BrowserButton };
}

void UUT2MidGameMenu::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	__OnKeyEvent__Delegate = InternalOnKeyEvent;
	__OnClose__Delegate = InternalOnClose;
	Controls[0].WinHeight = BarHeight;
	Controls[0].WinWidth = 1;
	Controls[0].WinTop = (BarVPos - (0.5 * BarHeight));
	Controls[0].WinLeft = 0;
	Controls[1].WinTop = ((BarVPos - ButtonVGap) - (1.5 * ButtonHeight));
	Controls[1].WinLeft = (0.5 - (0.5 * ButtonWidth));
	Controls[2].WinTop = (BarVPos - (0.5 * ButtonHeight));
	Controls[2].WinLeft = ((0.5 - (1.5 * ButtonWidth)) - ButtonHGap);
	Controls[3].WinTop = Controls[1].WinTop;
	Controls[3].WinLeft = Controls[2].WinLeft;
	Controls[4].WinTop = Controls[1].WinTop;
	Controls[4].WinLeft = ((0.5 + (0.5 * ButtonWidth)) + ButtonHGap);
	Controls[5].WinTop = Controls[2].WinTop;
	Controls[5].WinLeft = Controls[4].WinLeft;
	Controls[6].WinTop = Controls[2].WinTop;
	Controls[6].WinLeft = Controls[1].WinLeft;
	Controls[7].WinTop = ((BarVPos + ButtonVGap) + (0.5 * ButtonHeight));
	Controls[7].WinLeft = Controls[1].WinLeft;
	for (i = 1; i < 8; i++)
	{
		Controls[i].WinWidth = ButtonWidth;
		Controls[i].WinHeight = ButtonHeight;
	}
	Controls[5].bVisible = PlayerOwner().GameReplicationInfo.bTeamGame;
	if ((PlayerOwner().Level.Game != None) && (PlayerOwner().Level.Game.CurrentGameProfile != None))
	{
		Controls[5].bVisible = false;
	}
	if (PlayerOwner().Level.NetMode != NM_Standalone)
	{
		GUIButton(Controls[3]).Caption = LeaveMPButtonText;
	}
	else
	{
		GUIButton(Controls[3]).Caption = LeaveSPButtonText;
	}
	if ((PlayerOwner().Level.NetMode == NM_Client) && (!CurrentServerIsInFavorites()))
	{
		Controls[6].bVisible = true;
	}
	else
	{
		Controls[6].bVisible = false;
	}
	*/
}

bool UUT2MidGameMenu::CurrentServerIsInFavorites()
{
	/*
	FString Address = "";
	FString IPString = "";
	FString portString = "";
	int32 colonPos = 0;
	int32 portNum = 0;
	int32 i = 0;
	Address = PlayerOwner().GetServerNetworkAddress();
	if (Address == "")
	{
		return true;
	}
	colonPos = InStr(Address, ":");
	if (colonPos < 0)
	{
		IPString = Address;
		portNum = 7777;
	}
	else
	{
		IPString = Left(Address, colonPos);
		portString = Mid(Address, (colonPos + 1));
		portNum = int(portString);
	}
	for (i = 0; i<class'XInterface.Browser_ServerListPageFavorites'.Default.Favorites.Length; i++)
	{
		if ((class'XInterface.Browser_ServerListPageFavorites'.Default.Favorites[i].IP == IPString) && (class'XInterface.Browser_ServerListPageFavorites'.Default.Favorites[i].Port == portNum))
		{
			return true;
		}
	}
	*/
	return false;
}

bool UUT2MidGameMenu::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (bIgnoreEsc && (Key == 27))
	{
		bIgnoreEsc = false;
		return true;
	}
	*/
	return false;     //FAKE    /ELiZ
}

void UUT2MidGameMenu::InternalOnClose(bool bCanceled)
{
	/*
	local PlayerController PC;
	PC = PlayerOwner();
	if ((PC != None) && (PC.Level.Pauser != None))
	{
		PC.SetPause(false);
	}
	OnClose(bCanceled);
	*/
}

bool UUT2MidGameMenu::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == Controls[2])
	{
		Controller.OpenMenu("xinterface.UT2QuitPage");
	}
	else
	{
		if (Sender == Controls[3])
		{
			PlayerOwner().ConsoleCommand("DISCONNECT");
			if (PlayerOwner().Level.Game.CurrentGameProfile != None)
			{
				PlayerOwner().Level.Game.CurrentGameProfile.ContinueSinglePlayerGame(PlayerOwner().Level, true);
			}
			else
			{
				Controller.CloseMenu();
			}
		}
		else
		{
			if (Sender == Controls[1])
			{
				Controller.CloseMenu();
			}
			else
			{
				if (Sender == Controls[4])
				{
					Controller.OpenMenu("xinterface.UT2SettingsPage");
				}
				else
				{
					if ((Sender == Controls[5]) && Controls[5].bVisible)
					{
						PlayerOwner().SwitchTeam();
						Controller.CloseMenu();
					}
					else
					{
						if ((Sender == Controls[6]) && Controls[6].bVisible)
						{
							PlayerOwner().ConsoleCommand("ADDCURRENTTOFAVORITES");
							Controller.CloseMenu();
						}
						else
						{
							if (Sender == Controls[7])
							{
								Controller.OpenMenu("xinterface.ServerBrowser");
							}
						}
					}
				}
			}
		}
	}
	*/
	return true;
}
