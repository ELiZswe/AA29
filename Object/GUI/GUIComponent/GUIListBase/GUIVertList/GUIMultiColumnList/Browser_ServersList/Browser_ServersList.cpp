// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_ServersList/Browser_ServersList.h"

UBrowser_ServersList::UBrowser_ServersList()
{
	IconDescriptions = { "Passworded", "Stats Enabled", "Latest Version", "Listen Server", "Instagib", "Standard Server", "UT Classic" };
	ColumnHeadings = {"", "Server Name", "Map", "Players", "Ping"};
	InitColumnPerc = { 0.1, 0.37, 0.25, 0.13, 0.15 };
	SortColumn = 4;
}

void UBrowser_ServersList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int32 i;
	MyPlayersList.MyServersList = Self;
	MyRulesList.MyServersList = Self;
	__OnDrawItem__Delegate = MyOnDrawItem;
	__OnChange__Delegate = MyOnChange;
	__OnDblClick__Delegate = MyOnDblClick;
	InitComponent(MyController, MyOwner);
	SelStyle = Controller.GetStyle("SquareButton", FontScale);
	if (Controller.MaxSimultaneousPings == 0)
	{
		i = Class'Player'.Default.ConfiguredInternetSpeed;
		if (i <= 2600)
		{
			UseSimultaneousPings = 10;
		}
		else
		{
			if (i <= 5000)
			{
				UseSimultaneousPings = 15;
			}
			else
			{
				if (i <= 10000)
				{
					UseSimultaneousPings = 20;
				}
				else
				{
					UseSimultaneousPings = 35;
				}
			}
		}
	}
	else
	{
		UseSimultaneousPings = Controller.MaxSimultaneousPings;
	}
	*/
}

void UBrowser_ServersList::Clear()
{
	/*
	PingStart = 0;
	StopPings();
	Servers.remove(0, Servers.Length);
	ItemCount = 0;
	Clear();
	*/
}

void UBrowser_ServersList::CopyServerToClipboard()
{
	/*
	local string URL;
	if (Index >= 0)
	{
		URL = PlayerOwner().GetURLProtocol() $ "://" $ Servers[SortData[Index].SortItem].IP $ ":" $ Servers[SortData[Index].SortItem].Port;
		PlayerOwner().CopyToClipboard(URL);
	}
	*/
}

void UBrowser_ServersList::Connect(bool Spectator)
{
	/*
	local string URL;
	if (Index >= 0)
	{
		URL = PlayerOwner().GetURLProtocol() $ "://" $ Servers[SortData[Index].SortItem].IP $ ":" $ Servers[SortData[Index].SortItem].Port;
		if (Spectator)
		{
			URL = URL $ "?SpectatorOnly=1";
		}
		if (MyPage.ConnectLAN)
		{
			URL = URL $ "?LAN";
		}
		Controller.CloseAll(False);
		PlayerOwner().ClientTravel(URL, 0, False);
	}
	*/
}

void UBrowser_ServersList::AddFavorite(AServerBrowser* Browser)
{
	/*
	if (Index >= 0)
	{
		Browser.OnAddFavorite(Servers[SortData[Index].SortItem]);
	}
	*/
}

bool UBrowser_ServersList::MyOnDblClick(UGUIComponent* Sender)
{
	//Connect(False);
	return true;
}

bool UBrowser_ServersList::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (InternalOnKeyEvent(Key, State, Delta))
	{
		Return True;
	}
	if (State == 1)
	{
		Switch(Key)
		{
				case 13:
					Connect(False);
					Return True;
					break;
				case 116:
					MyPage.RefreshList();
					Return True;
					break;
				case 67:
					if (Controller.CtrlPressed)
					{
						CopyServerToClipboard();
						Return True;
					}
					break;
				default:
		}
	}
	*/
	return false;
}

void UBrowser_ServersList::MyOnReceivedServer(FServerResponseLine S)
{
	/*
	local int32 i;
	i = Servers.Length;
	Servers.Length = i + 1;
	Servers[i] = S;
	if (Servers[i].Ping == 0)
	{
		Servers[i].Ping = 9999;
	}
	ItemCount++;
	AddedItem();
	*/
}

void UBrowser_ServersList::MyPingTimeout(int32 ListID, EPingCause PingCause)
{
	/*
	local int32 i;
	if (ListID >= Servers.Length)
	{
		Return;
	}
	if (Servers[ListID].Ping == 9999)
	{
		Servers[ListID].Ping = 10000;
		UpdatedItem(ListID);
	}
	i = 0;
	if (i < OutstandingPings.Length)
	{
		if (OutstandingPings[i] == ListID)
		{
			OutstandingPings.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	if (PingCause == 2)
	{
		NumReceivedPings++;
		NeedsSorting = True;
		AutopingServers();
	}
	*/
}

void UBrowser_ServersList::MyReceivedPingInfo(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
	/*
	local int32 i;
	if (ListID < 0)
	{
		PingStart = 0;
		Return;
	}
	Servers[ListID] = S;
	i = PingStart;
	if (i < ListID && i < Servers.Length)
	{
		if (Servers[i].Ping == 9999)
		{
		}
		i++;
	}
	if (i < ListID)
	{
		PingStart = ListID;
	}
	i = 0;
	if (i < OutstandingPings.Length)
	{
		if (OutstandingPings[i] == ListID)
		{
			OutstandingPings.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	UpdatedItem(ListID);
	if (Index >= 0 && ListID == SortData[Index].SortItem)
	{
		MyOnChange(None);
	}
	if (PingCause == 2)
	{
		NumReceivedPings++;
		NumPlayers += S.CurrentPlayers;
		NeedsSorting = True;
		AutopingServers();
	}
	*/
}

void UBrowser_ServersList::RePingServers()
{
	InvalidatePings();
	AutopingServers();
}

void UBrowser_ServersList::MyQueryFinished(EResponseInfo ResponseInfo, int32 Info)
{
	/*
	if (ResponseInfo == 3)
	{
		RePingServers();
	}
	*/
}

void UBrowser_ServersList::InvalidatePings()
{
	/*
	local int32 i;
	StopPings();
	PingStart = 0;
	NumReceivedPings = 0;
	NumPlayers = 0;
	for (i = 0; i < Servers.Length; i++)
	{
		Servers[i].Ping = 9999;
		UpdatedItem(i);
	}
	*/
}

void UBrowser_ServersList::AutopingServers()
{
	/*
	local int32 i;
	local int32 j;
	i = PingStart;
	if (i < Servers.Length && OutstandingPings.Length < UseSimultaneousPings)
	{
		if (Servers[i].Ping == 9999)
		{
			for (j = 0; j < OutstandingPings.Length; j++)
			{
				if (OutstandingPings[j] == i)
				{
				}
			}
			if (j == OutstandingPings.Length)
			{
				MyPage.PingServer(i, 2, Servers[i]);
				j = OutstandingPings.Length;
				OutstandingPings.Length = j + 1;
				OutstandingPings[j] = i;
			}
		}
		i++;
	}
	if (OutstandingPings.Length == 0)
	{
		NumReceivedPings = Servers.Length;
	}
	*/
}

void UBrowser_ServersList::StopPings()
{
	/*
	OutstandingPings.remove(0, OutstandingPings.Length);
	MyPage.CancelPings();
	*/
}

void UBrowser_ServersList::Timer()
{
	/*
	if (Index >= 0)
	{
		MyOnChange(Self);
	}
	*/
}

void UBrowser_ServersList::MyOnChange(UGUIComponent* Sender)
{
	/*
	MyRulesList.Clear();
	MyPlayersList.Clear();
	if (Index >= 0)
	{
		if (Sender != None)
		{
			MyPage.PingServer(SortData[Index].SortItem, 1, Servers[SortData[Index].SortItem]);
		}
		MyRulesList.ItemCount = Servers[SortData[Index].SortItem].ServerInfo.Length;
		MyRulesList.listitem = SortData[Index].SortItem;
		MyPlayersList.ItemCount = Servers[SortData[Index].SortItem].PlayerInfo.Length;
		MyPlayersList.listitem = SortData[Index].SortItem;
		SetTimer(5, False);
	}
	else
	{
		MyRulesList.ItemCount = 0;
		MyPlayersList.ItemCount = 0;
	}
	*/
}

int32 UBrowser_ServersList::RemoveCurrentServer()
{
	/*
	local int32 OldItem;
	if (Index >= 0)
	{
		OldItem = SortData[Index].SortItem;
		Servers.remove(OldItem, 1);
		ItemCount--;
		MyRulesList.ItemCount = 0;
		MyPlayersList.ItemCount = 0;
		RemovedCurrent();
		Return OldItem;
	}
	*/
	return -1;
}

void UBrowser_ServersList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	local float DrawX;
	local float IconPosX;
	local float IconPosY;
	local string Ping;
	local int32 k;
	local int32 Flags;
	local int32 checkFlag;
	if (bSelected)
	{
		SelStyle.Draw(Canvas, 3, X, Y - 2, W, H + 2);
	}
	Flags = Servers[SortData[i].SortItem].MaxPlayers;
	GetCellLeftWidth(0, CellLeft, CellWidth);
	IconPosX = CellLeft;
	IconPosY = Y;
	checkFlag = 1 << 30;
	k = 0;
	if (k < Icons.Length && IconPosX < CellLeft + CellWidth)
	{
		if (Flags & checkFlag != 0)
		{
			DrawX = Min(14, CellLeft + CellWidth - IconPosX);
			Canvas.DrawColor = Canvas.MakeColor(255, 255, 255, 255);
			Canvas.SetPos(IconPosX, IconPosY);
			Canvas.DrawTile(Icons[k], DrawX, 14, 0, 0, DrawX + 1, 15);
			IconPosX += 14;
		}
		checkFlag = checkFlag >> 1;
		k++;
	}
	GetCellLeftWidth(1, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, Servers[SortData[i].SortItem].ServerName, FontScale);
	GetCellLeftWidth(2, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, Servers[SortData[i].SortItem].MapName, FontScale);
	GetCellLeftWidth(3, CellLeft, CellWidth);
	if (Servers[SortData[i].SortItem].CurrentPlayers > 0 || Servers[SortData[i].SortItem].MaxPlayers > 0)
	{
		Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, Servers[SortData[i].SortItem].CurrentPlayers $ "/" $ Servers[SortData[i].SortItem].MaxPlayers & 255, FontScale);
	}
	GetCellLeftWidth(4, CellLeft, CellWidth);
	if (Servers[SortData[i].SortItem].Ping == 9999)
	{
		Ping = "?";
	}
	else
	{
		if (Servers[SortData[i].SortItem].Ping == 10000)
		{
			Ping = "N/A";
		}
		else
		{
			Ping = Servers[SortData[i].SortItem].Ping;
		}
	}
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, Ping, FontScale);
	*/
}

FString UBrowser_ServersList::GetSortString(int32 i)
{
	FString S="";
	FString t="";
	/*
	Switch(SortColumn)
	{
			case 0:
			case 1:
				S = Left(Caps(Servers[i].ServerName), 8);
				break;
			case 2:
				S = Left(Caps(Servers[i].MapName), 8);
				break;
			case 3:
				S = Servers[i].CurrentPlayers;
				if (Len(S) < 4)
				{
					S = "0" $ S;
				}
				t = Servers[i].MaxPlayers & 255;
				if (Len(t) < 4)
				{
					t = "0" $ t;
				}
				S = S $ t;
				GOTO JL0162;
			case 4:
				S = Servers[i].Ping;
				if (Len(S) < 5)
				{
					S = "0" $ S;
				}
				GOTO JL0162;
			default:
				S = Servers[i].Ping;
				if (Len(S) < 5)
				{
					S = "0" $ S;
				}
				GOTO JL0162;
			JL0162:
	}
	*/
	return S;
}