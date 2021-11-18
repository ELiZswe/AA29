// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_ServersList/AABrowser_ServersList.h"

UAABrowser_ServersList::UAABrowser_ServersList()
{
	//Icons(0) = Texture'T_AA2_UI.HUD.hud_group_army';
	//Icons(1) = Texture'T_AA2_UI.HUD.hud_group_honor';
	//Icons(2) = Texture'T_AA2_UI.HUD.hud_group_PLP_a';
	//Icons(3) = Texture'T_AA2_UI.HUD.hud_group_miles';
	//Icons(4) = Texture'T_AA2_UI.HUD.hud_icon_punkbuster';
	//Icons(5) = Texture'T_AA2_UI.HUD.hud_group_locked';
	//Icons(6) = Texture'T_AA2_UI.HUD.hud_group_eta';

	IconDescriptions = { "Official", "Honor (Leased)", "Authorized", "MILES", "PunkBuster", "Password", "Instant Action" };

	//TourIcons(0) = Texture'T_AA2_UI.HUD.menu_touricon_Basic_sm';
	//TourIcons(1) = Texture'T_AA2_UI.HUD.menu_touricon_Basic_sm';
	//TourIcons(2) = Texture'T_AA2_UI.HUD.menu_touricon_172nd_sm';
	//TourIcons(3) = Texture'T_AA2_UI.HUD.menu_touricon_10th_mtn_sm';
	//TourIcons(4) = Texture'T_AA2_UI.HUD.menu_touricon_Marksmanship_sm';
	//TourIcons(5) = Texture'T_AA2_UI.HUD.menu_touricon_AirBorne_school_sm';
	//TourIcons(6) = Texture'T_AA2_UI.HUD.menu_touricon_82nd_sm';
	//TourIcons(7) = Texture'T_AA2_UI.HUD.menu_touricon_Ranger_sm';
	//TourIcons(8) = Texture'T_AA2_UI.HUD.menu_touricon_Ranger_75th_sm';
	//TourIcons(9) = Texture'T_AA2_UI.HUD.menu_touricon_CombatMedic_sm';
	//TourIcons(10) = Texture'T_AA2_UI.HUD.menu_touricon_SF_sm';
	//TourIcons(11) = Texture'T_AA2_UI.HUD.menu_touricon_SF_sm';
	//TourIcons(12) = Texture'T_AA2_UI.HUD.menu_touricon_SF_sm';
	//FlagIcons = CountryFlags'AGP_Interface.AABrowser_ServersList.FlagsObject';

	ColumnHeadings = { "Icons", "Server Name", "Map", "Players", "Ping", "Avg Honor" };
	InitColumnPerc = { 0.09, 0.35, 0.25, 0.11, 0.11, 0.09 };
	SortColumn = 4;
	ExpandLastColumn = true;
	//__OnDrawItem__Delegate = "AABrowser_ServersList.MyOnDrawItem";
	WinHeight = 1;
	//__OnDblClick__Delegate = "AABrowser_ServersList.MyOnDblClick";
}

//const COLUMN_ICONS = 0;
//const COLUMN_SERVER_NAME = 1;
//const COLUMN_MAP_NAME = 2;
//const COLUMN_NUM_PLAYERS = 3;
//const COLUMN_PING = 4;
//const COLUMN_AVERAGE_HONOR = 5;


void UAABrowser_ServersList::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	/*
	if (bIsLAN)
	{
		InitColumnPerc[2] += InitColumnPerc[5];
		InitColumnPerc.remove(5, 1);
		ColumnHeadings.remove(5, 1);
	}
	InitComponent(InController, InOwner);
	*/
}

int32 UAABrowser_ServersList::CurrentListId()
{
	if (Index < 0)
	{
		return -1;
	}
	return 0;
}

void UAABrowser_ServersList::AddPingReport(int32 Id, FString S)
{
	/*
	local int32 i;
	if (!bDebugging)
	{
		Return;
	}
	for (i = 0; i < reports.Length; i++)
	{
		if (reports[i].ListID == Id)
		{
			Log("Warning, overwriting existing ping report (" $ i $ ") for listid:" $ Id @ S);
			reports[i].Ping = S;
			Return;
		}
		if (reports[i].ListID > Id)
		{
		}
	}
	reports.insert(i, 1);
	reports[i].ListID = Id;
	reports[i].Ping = S;
	*/
}

void UAABrowser_ServersList::AddReceiveReport(int32 Id, FString S)
{
	/*
	local int32 i;
	if (!bDebugging)
	{
		Return;
	}
	for (i = 0; i < reports.Length; i++)
	{
		if (reports[i].ListID == Id)
		{
			reports[i].receive = S;
			Return;
		}
		if (reports[i].ListID > Id)
		{
		}
	}
	Log("Warning, no matching ping report found for listid:" $ Id @ S);
	reports.insert(i, 1);
	reports[i].ListID = Id;
	reports[i].receive = S;
	*/
}

FString UAABrowser_ServersList::getreportsortstring(int32 idx)
{
	/*
	local int32 i;
	local FString S;
	local FString Port;
	local array<String> Parts;
	Divide(reports[idx].Ping, ":", S, Port);
	Split(S, ".", Parts);
	for (i = 0; i < 4; i++)
	{
		PadLeft(Parts[i], 4, "0");
	}
	PadLeft(Port, 5, "0");
	return JoinArray(Parts, ".") $ Port;
	*/
	return "FAKE";     //FAKE   /ELiZ
}

void UAABrowser_ServersList::logall()
{
	/*
	local int32 i;
	local int32 Id;
	local FString idx;
	local FString ListID;
	local FString outping;
	local FString inping;
	local XInterface.GUIMultiColumnList Temp;
	if (!bDebugging)
	{
		Return;
	}
	idx = "Index";
	ListID = "ListID";
	outping = "Address Pinged";
	inping = "Received";
	PadRight(idx, 8);
	PadRight(ListID, 8);
	PadRight(outping, 22);
	Temp = new (None) classClass'GUIMultiColumnList';
	Temp.SortColumn = 0;
	Temp.__GetSortString__Delegate = getreportsortstring;
	for (i = 0; i < reports.Length; i++)
	{
		Temp.AddedItem();
	}
	Temp.Sort();
	Log(idx $ ListID $ outping $ inping);
	for (i = 0; i < reports.Length; i++)
	{
		Id = Temp.SortData[i].SortItem;
		idx = Id;
		ListID = reports[Id].ListID;
		outping = reports[Id].Ping;
		inping = reports[Id].receive;
		PadRight(idx, 8);
		PadRight(ListID, 8);
		PadRight(outping, 22);
		Log(idx $ ListID $ outping $ inping);
	}
	*/
}

void UAABrowser_ServersList::Clear()
{
	/*
	PingStart = 0;
	StopPings();
	Servers.remove(0, Servers.Length);
	ItemCount = 0;
	Clear();
	*/
}

void UAABrowser_ServersList::CopyServerToClipboard()
{
	/*
	local FString URL;
	local IpDrv.ServerBrowserBase sbBase;
	local FGameSpyServerItem ServerItem;
	if (IsValid())
	{
		sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
		if (sbBase != None)
		{
			sbBase.GetSpecificServer(Index, ServerItem);
		}
		URL = PlayerOwner().GetURLProtocol() $ "://" $ sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
		if (Default.ServerPassword != "")
		{
			URL = URL $ "?Password=" $ Default.ServerPassword;
		}
		PlayerOwner().CopyToClipboard(URL);
	}
	*/
}

void UAABrowser_ServersList::Connect(bool Spectator,FString AdminPassword,bool bPlayerAdminPassword)
{
	/*
	local FString URL;
	local FString ETACommand;
	local IpDrv.ServerBrowserBase sbBase;
	local FGameSpyServerItem ServerItem;
	if (IsValid())
	{
		if (!CanConnect())
		{
			Return;
		}
		sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
		if (sbBase != None)
		{
			sbBase.GetSpecificServer(Index, ServerItem);
		}
		if (ServerItem.bExploreTheArmy == 1)
		{
			ETACommand = "ETAJoinServer" @ sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port) @ StudentController(PlayerOwner()).sETAUserSelectedSurName @ StudentController(PlayerOwner()).sETAUserSelectedNickName;
			if (ServerItem.bPassword == 1 && Default.ServerPassword != "")
			{
				ETACommand = ETACommand @ Default.ServerPassword;
			}
			PlayerOwner().ConsoleCommand(ETACommand);
		}
		else
		{
			URL = PlayerOwner().GetURLProtocol() $ "://" $ sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
			if (Len(AdminPassword) > 0)
			{
				if (bPlayerAdminPassword)
				{
					URL = URL $ "?PAPassword=" $ AdminPassword;
				}
				else
				{
					URL = URL $ "?Password=" $ AdminPassword;
				}
			}
			else
			{
				if (ServerItem.bPassword == 1 && Default.ServerPassword != "")
				{
					URL = URL $ "?Password=" $ Default.ServerPassword;
				}
			}
			if (Spectator)
			{
				URL = URL $ "?SpectatorOnly=1";
			}
			if (bIsLAN)
			{
				URL = URL $ "?LAN";
				if (ServerItem.bRequiresAuthorization == 0 && 0 == Len(HumanController(PlayerOwner()).GetAuthUserName()) || "UserName" ~= HumanController(PlayerOwner()).GetAuthUserName())
				{
					HumanController(PlayerOwner()).UserName = HumanController(PlayerOwner()).LANPlayerName;
					Class'HumanController'.Default.UserName = HumanController(PlayerOwner()).LANPlayerName;
					HumanController(PlayerOwner()).SaveConfig();
				}
			}
			PlayerOwner().ClientTravel(URL, 0, False);
		}
	}
	*/
}

bool UAABrowser_ServersList::MyOnDblClick(UGUIComponent* Sender)
{
	//Connect(False);
	return true;
}

bool UAABrowser_ServersList::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (InternalOnKeyEvent(Key, State, Delta))
	{
		return true;
	}
	if (State == 3)
	{
		Switch(Key)
		{
				case 13:
					Connect(False);
					return true;
				case 116:
					return true;
				case 67:
					if (Controller.CtrlPressed)
					{
						CopyServerToClipboard();
						return true;
					}
					break;
				default:
		}
	}
	*/
	return false;
}

void UAABrowser_ServersList::MyOnReceivedServer(FServerResponseLine S)
{
}

void UAABrowser_ServersList::MyOnReceivedSB(int32 Data)
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != None)
	{
		ItemCount = sbBase.GetNumServers();
		if (ItemCount == 0 && !bRetrievalFailed)
	}
	{
		bRetrievalFailed = False;
	}
	*/
}

void UAABrowser_ServersList::MyOnUpdateServerListFailed(FString Reason)
{
	//bRetrievalFailed = True;
	//Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Internet Servers Failure", Reason);
}

void UAABrowser_ServersList::MyPingTimeout(int32 ListID, EPingCause PingCause)
{
	/*
	local int32 i;
	AddReceiveReport(ListID, "TIMEOUT");
	if (ListID < 0 || ListID >= Servers.Length)
	{
		PingStart = 0;
		Return;
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
	if (Servers[ListID].Ping == 9999)
	{
		Servers[ListID].Ping = 20000;
		UpdatedItem(ListID);
	}
	if (PingCause == 2)
	{
		NumReceivedPings++;
		NeedsSorting = True;
		AutopingServers();
	}
	*/
}

void UAABrowser_ServersList::MyReceivedPingInfo(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
	/*
	local int32 i;
	local int32 Flags;
	local bool bFound;
	if (ListID < 0 || ListID >= Servers.Length)
	{
		PingStart = 0;
		AddReceiveReport(ListID, S.IP $ ":" $ S.Port);
		Return;
	}
	else
	{
		AddReceiveReport(ListID, S.IP $ ":" $ S.Port);
	}
	Flags = Servers[ListID].Flags;
	Servers[ListID] = S;
	Servers[ListID].Flags = Flags;
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
			bFound = True;
			OutstandingPings.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	UpdatedItem(ListID);
	if (IsValid() && ListID == SortData[Index].SortItem)
	{
		OnChange(None);
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

void UAABrowser_ServersList::RePingServers()
{
	//InvalidatePings();
	//AutopingServers();
}

void UAABrowser_ServersList::FakeFinished()
{
	/*
	local int32 i;
	for (i = 0; i < Servers.Length; i++)
	{
		AddedItem();
	}
	RePingServers();
	SetTimer(5, True);
	*/
}

void UAABrowser_ServersList::MyQueryFinished(EResponseInfo ResponseInfo, int32 Info)
{
	/*
	local int32 i;
	if (ResponseInfo == 3)
	{
		if (bPresort)
		{
			if (ItemCount > 0)
			{
				Log(Name @ "RECEIVED QUERYFINISHED NOTICE WITH ITEMCOUNT > 0!!! ITEMCOUNT:" $ ItemCount @ "Info:" $ Info);
				Return;
			}
			for (i = 0; i < Servers.Length; i++)
			{
				AddedItem();
			}
		}
		RePingServers();
		SetTimer(5, True);
	}
	*/
}

void UAABrowser_ServersList::InvalidatePings()
{
	/*
	local int32 i;
	reports.remove(0, reports.Length);
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

void UAABrowser_ServersList::AutopingServers()
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
				OutstandingPings[j] = i;
				AddPingReport(i, Servers[i].IP $ ":" $ Servers[i].Port);
			}
		}
		i++;
	}
	if (OutstandingPings.Length == 0)
	{
		logall();
	}
	*/
}

void UAABrowser_ServersList::StopPings()
{
	//OutstandingPings.remove(0, OutstandingPings.Length);
}

void UAABrowser_ServersList::RemoveServerAt(int32 pos)
{
	/*
	local int32 i;
	if (!IsValidIndex(pos))
	{
		return -1;
	}
	i = Servers.Length - 1;
	if (pos < i)
	{
		Servers[pos] = Servers[i];
	}
	Servers.remove(i, 1);
	if (i == Index)
	{
	}
	RemovedItem(i);
	SetIndex(Index);
	NeedsSorting = True;
	return pos;
	*/
}

int32 UAABrowser_ServersList::RemoveCurrentServer()
{
	/*
	local int32 OldItem;
	if (IsValid())
	{
		OldItem = SortData[Index].SortItem;
		if (RemoveServerAt(Index) != -1)
		{
			return OldItem;
		}
	}
	*/
	return -1;
}

FString UAABrowser_ServersList::GetSortString(int32 i)
{
	FString S="";
	FString t="";
	/*
	Switch(SortColumn)
	{
			case 0:
				S = BuildFlagString(Servers[i].Flags) $ i;
				break;
			case 1:
				S = Left(Caps(Servers[i].ServerName), 8);
				break;
			case 2:
				S = Left(Caps(Servers[i].MapName), 8);
				break;
			case 3:
				S = Servers[i].CurrentPlayers;
				PadLeft(S, 4, "0");
				t = Servers[i].MaxPlayers & 255;
				PadLeft(t, 4, "0");
				S $ = t $ i;
				break;
			default:
				S = Servers[i].Ping;
				PadLeft(S, 5, "0");
				S $ = i;
				break;
	}
	*/
	return S;
}

FString UAABrowser_ServersList::Get(bool bGuarantee)
{
	FString S="";
	/*
	if (Servers.Length <= 0)
	{
		return "";
	}
	if (IsValid())
	{
		S = Servers[CurrentListId()].IP $ ":" $ Servers[CurrentListId()].Port;
	}
	else
	{
		if (Servers.Length > 0 && bGuarantee)
		{
			S = Servers[SortData[0].SortItem].IP $ ":" $ Servers[SortData[0].SortItem].Port;
		}
	}
	*/
	return S;
}

bool UAABrowser_ServersList::GetCurrent(FServerResponseLine& S)
{
	/*
	if (!IsValid())
	{
		return false;
	}
	S = Servers[CurrentListId()];
	*/
	return true;
}

int32 UAABrowser_ServersList::FindIndex(FString IP,FString Port)
{
	/*
	local int32 i;
	for (i = 0; i < Servers.Length; i++)
	{
		if (Servers[i].IP == IP && Port == "" || Servers[i].Port == Port)
		{
			return i;
		}
	}
	*/
	return -1;
}

bool UAABrowser_ServersList::IsValid()
{
	return Index >= 0;
}

bool UAABrowser_ServersList::IsValidIndex(int32 Test)
{
	return Test >= 0;
}

void UAABrowser_ServersList::Opened(UGUIComponent* Sender)
{
	/*
	Opened(Sender);
	if (bInitialized)
	{
		AutopingServers();
	}
	else
	{
		bInitialized = True;
	}
	*/
}

void UAABrowser_ServersList::Closed(UGUIComponent* Sender, bool bCancelled)
{
	//Closed(Sender, bCancelled);
	//StopPings();
}

FString UAABrowser_ServersList::BuildFlagString(int32 Flags)
{
	FString Result="";
	/*
	local int32 Value;
	Value = 9999;
	if (Flags & 32)
	{
		Value = 1000;
	}
	if (Flags & 4)
	{
		Value -= 90;
	}
	if (!Flags & 8)
	{
		Value -= 85;
	}
	if (Flags & 2)
	{
		Value -= 10;
	}
	Result = Value;
	PadLeft(Result, 4, "0");
	*/
	return Result;
}

bool UAABrowser_ServersList::CanConnect()
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	local FGameSpyServerItem ServerItem;
	local FString sVersion;
	local int32 TourID;
	local int32 MissionID;
	local FString missionFile;
	local FString MissionName;
	local bool bPB;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != None)
	{
		sbBase.GetSpecificServer(Index, ServerItem);
	}
	sVersion = GetVersionAGPMajor() $ "." $ GetVersionAGPMinor() $ "." $ GetVersionAGPTiny() $ "." $ GetVersionAGPSubTiny();
	if (ServerItem.GameVer != sVersion)
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "You can only play on version " $ sVersion $ " servers.");
		return false;
	}
	MissionName = ServerItem.MapName;
	TourID = ServerItem.Tour;
	PlayerOwner().Level.GetLevelMissionPrivate(MissionName, TourID, missionFile);
	PlayerOwner().Level.GetLevelTourAndMissionPrivate(missionFile, TourID, MissionID);
	if (ServerItem.bExploreTheArmy == 1)
	{
		if (0 == Len(StudentController(PlayerOwner()).sETAUserSelectedNickName) || 0 == Len(StudentController(PlayerOwner()).sETAUserSelectedSurName))
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Instant Action Names Not Selected", "");
			return false;
		}
	}
	if (!bIsLAN)
	{
		if (0 == ServerItem.bExploreTheArmy && HumanController(PlayerOwner()) != None)
		{
			HumanController(PlayerOwner()).LoadJacket();
			if (HumanController(PlayerOwner()).UserName ~= "UserName" || HumanController(PlayerOwner()).UserPassword ~= "UserPassword" || Len(HumanController(PlayerOwner()).UserPassword) == 0)
			{
				Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Profile Not Found", "You must load your profile by logging in to the Personnel Jacket in order to play online.");
				return false;
			}
		}
		if (HumanController(PlayerOwner()) != None && HumanController(PlayerOwner()).iCompleted[1] != 15 && !TourID == 1 || TourID == 2 || TourID == 3 || TourID == 6 || TourID == 7 || TourID == 8 || TourID == 11)
		{
			if (!PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), TourID, MissionID))
			{
				Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Required Training Not Complete", "You must complete the proper training for this mission.");
				return false;
			}
		}
		if (GetMilesOnly() && ServerItem.bMiles == 0)
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Your Parental Control Settings Warning:", "You can only play MILES missions.");
			return false;
		}
		if (!TestGroups(ServerItem.Groups))
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "This server only allows certain groups to join.");
			return false;
		}
	}
	else
	{
		if (0 == ServerItem.bExploreTheArmy)
		{
			if (1 == ServerItem.bRequiresAuthorization)
			{
				if (0 == Len(HumanController(PlayerOwner()).GetAuthUserName()) || "UserName" ~= HumanController(PlayerOwner()).GetAuthUserName())
				{
					Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Profile Not Found", "This server requires authorization. You must load your profile by logging in to the Personnel Jacket in order to play on this LAN server.");
					return false;
				}
			}
			else
			{
				if (0 == Len(HumanController(PlayerOwner()).GetAuthUserName()) || "UserName" ~= HumanController(PlayerOwner()).GetAuthUserName() && 0 == Len(HumanController(PlayerOwner()).LANPlayerName))
				{
					Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "LAN Player Name Not Found", "Please either load your profile by logging in to the Personnel Jacket, or enter a LAN Player Name.");
					return false;
				}
			}
		}
	}
	if (ServerItem.bPassword == 1 && Default.ServerPassword == "")
	{
		if (Controller.OpenMenu("AGP_Interface.AAGetDataMenu", "This server requires a password.", "Please enter a valid password."))
		{
			Controller.ActivePage.__OnClose__Delegate = InternalOnCloseGetPassword;
		}
		return false;
	}
	if (ServerItem.bPunkBuster == 1)
	{
		bPB = PlayerOwner().Level.PBIsEnabled() == 1;
		if (!bPB)
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "This server requires that PunkBuster be enabled.", "Please enable PunkBuster.");
			return false;
		}
	}
	*/
	return true;
}

void UAABrowser_ServersList::InternalOnCloseGetPassword(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		SetServerPassword(AAGetDataMenu(Controller.ActivePage).ed_Data.GetText());
		Connect(False);
	}
	*/
}

void UAABrowser_ServersList::SetServerPassword(FString Password)
{
	/*
	Default.ServerPassword = Password;
	StaticSaveConfig();
	*/
}

bool UAABrowser_ServersList::IsOnFavoritesList(FGameSpyServerItem ServerItem)
{
	/*
	local DBAuth.Favorites Favorites;
	local Favorites.FavoriteServer Server;
	local FString IPAddress;
	IPAddress = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser().IpAddrToString(ServerItem.IP, 0);
	Server.IPAddress = Left(IPAddress, InStr(IPAddress, ":"));
	Server.Port = ServerItem.Port;
	Favorites = 'AABrowser_FavoritesPanel'.Default.Favorites;
	if (-1 == Favorites.GetIndexOfFavoriteServer(Server))
	{
		return false;
	}
	*/
	return true;
}

void UAABrowser_ServersList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	local float DrawX;
	local float IconPosX;
	local float IconPosY;
	local float TotalIconWidth;
	local FString ServerName;
	local FString Ping;
	local FString AverageHonor;
	local XInterface.GUIStyles DStyle;
	local IpDrv.ServerBrowserBase sbBase;
	local FGameSpyServerItem ServerItem;
	local Object.FloatBox FlagRenderData;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != None)
	{
		sbBase.GetSpecificServer(i, ServerItem);
	}
	if (sbBase.IsSupportsFavorites() && IsOnFavoritesList(ServerItem))
	{
		FavoritesStyle.Draw(Canvas, MenuState, X, Y, W, H);
	}
	if (bSelected)
	{
		SelectedStyle.Draw(Canvas, MenuState, X, Y, W, H + 1);
		DStyle = SelectedStyle;
	}
	else
	{
		DStyle = Style;
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	IconPosX = CellLeft;
	IconPosY = Y;
	if (ServerItem.bExploreTheArmy == 0)
	{
		if (ServerItem.bOfficial == 1 && TotalIconWidth < CellWidth)
		{
			DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
			Canvas.SetPos(IconPosX, IconPosY);
			if (ServerItem.bLeased == 1)
			{
				Canvas.DrawTile(Icons[1], DrawX, 14, 0, 0, 31, 31);
			}
			else
			{
				Canvas.DrawTile(Icons[0], DrawX, 14, 0, 0, 31, 31);
			}
			IconPosX += 14;
			TotalIconWidth += 14;
		}
		else
		{
			if (ServerItem.bLeased == 1)
			{
				DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
				Canvas.SetPos(IconPosX, IconPosY);
				Canvas.DrawTile(Icons[1], DrawX, 14, 0, 0, 31, 31);
				IconPosX += 14;
				TotalIconWidth += 14;
			}
		}
		if (!ServerItem.bOfficial == 1 || ServerItem.bLeased == 1)
		{
			DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
			Canvas.SetPos(IconPosX, IconPosY);
			Canvas.DrawTile(Icons[2], DrawX, 14, 0, 0, Icons[2].MaterialUSize(), Icons[2].MaterialVSize());
			IconPosX += 14;
			TotalIconWidth += 14;
		}
	}
	else
	{
		DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(Icons[6], DrawX, 14, 0, 0, Icons[6].MaterialUSize(), Icons[6].MaterialVSize());
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (ServerItem.bMiles == 1 && TotalIconWidth < CellWidth)
	{
		DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(Icons[3], DrawX, 14, 0, 0, 31, 31);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (ServerItem.bPassword == 1 && TotalIconWidth < CellWidth)
	{
		DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(Icons[5], DrawX, 14, 0, 0, 31, 31);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (ServerItem.bPunkBuster == 1 && TotalIconWidth < CellWidth)
	{
		DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(Icons[4], DrawX, 14, 0, 0, 31, 31);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (ServerItem.Tour >= 0 && ServerItem.Tour < 32 && ServerItem.Tour < TourIcons.Length && TourIcons[ServerItem.Tour] != None && TotalIconWidth < CellWidth)
	{
		DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(TourIcons[ServerItem.Tour], DrawX, 14, 0, 0, 31, 31);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (FlagIcons.GetRenderData(FlagRenderData, ServerItem.Locale) && TotalIconWidth < CellWidth)
	{
		DrawX = Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(FlagIcons.FlagTexture, DrawX, 14, FlagRenderData.X1, FlagRenderData.Y1, FlagRenderData.X2, FlagRenderData.Y2);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	ServerName = ServerItem.Name;
	if (HumanController(PlayerOwner()).bDisableServerColorsInBrowser)
	{
		ServerName = StripColorCodes(ServerName);
	}
	GetCellLeftWidth(1, CellLeft, CellWidth);
	DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, ServerName, FontScale);
	GetCellLeftWidth(2, CellLeft, CellWidth);
	DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, ServerItem.MapName, FontScale);
	GetCellLeftWidth(3, CellLeft, CellWidth);
	DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, ServerItem.NumPlayers $ "/" $ ServerItem.MaxPlayers & 255, FontScale);
	GetCellLeftWidth(4, CellLeft, CellWidth);
	if (ServerItem.Ping == 9999)
	{
		Ping = "?";
	}
	else
	{
		if (ServerItem.Ping > 9999)
		{
			Ping = "N/A";
		}
		else
		{
			Ping = ServerItem.Ping;
		}
	}
	Ping $ = "/" $ Eval(ServerItem.AveragePlayerPing >= 0 && ServerItem.AveragePlayerPing < 9999, ServerItem.AveragePlayerPing, "?");
	DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, Ping, FontScale);
	if (!bIsLAN)
	{
		GetCellLeftWidth(5, CellLeft, CellWidth);
		AverageHonor = Eval(ServerItem.AverageHonor != -1, ServerItem.AverageHonor, "N/A");
		DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, AverageHonor, FontScale);
	}
	*/
}

void UAABrowser_ServersList::TestGroups(FString Groups)
{
	/*
	local bool bLegalList;
	local int32 PlayerGroup;
	local FString sTemp;
	local int32 iPos;
	local FString test_string;
	local int32 test_group;
	PlayerGroup = PlayerOwner().PlayerReplicationInfo.GetGroup();
	sTemp = Groups;
	if (sTemp != "")
	{
		iPos = InStr(sTemp, " ");
		if (iPos == -1)
		{
			test_string = sTemp;
			sTemp = "";
		}
		else
		{
			test_string = Left(sTemp, iPos);
			sTemp = Right(sTemp, Len(sTemp) - iPos - 1);
		}
		test_group = test_string;
		if (test_group != 0)
		{
			if (test_group == PlayerGroup)
			{
				return true;
			}
			bLegalList = True;
		}
	}
	if (bLegalList)
	{
		return false;
	}
	else
	{
		return true;
	}
	*/
}

void UAABrowser_ServersList::SBRePingAllServers()
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != None)
	{
		sbBase.RePingAllServers();
	}
	*/
}

void UAABrowser_ServersList::OnSortChanged()
{
	/*
	local FString sField;
	local ServerBrowserBase.EGameSpyCompareMode eCompareCode;
	local IpDrv.ServerBrowserBase sbBase;
	Switch(SortColumn)
	{
			case -1:
				break;
			case 0:
				sField = "icons";
				eCompareCode = 0;
				break;
			case 1:
				sField = "hostname";
				eCompareCode = 2;
				break;
			case 2:
				sField = "mapname";
				eCompareCode = 3;
				break;
			case 3:
				sField = "numplayers";
				eCompareCode = 0;
				break;
			case 4:
				sField = "ping";
				eCompareCode = 0;
				break;
			default:
	}
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase == None)
	{
		Return;
	}
	sbBase.SortServers(sField, !SortDescending, eCompareCode);
	*/
}