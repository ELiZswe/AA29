// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_ServersList/AABrowser_ServersList.h"
#include "AA29/Object/CountryFlags/CountryFlags.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "AA29/Object/Favorites/Favorites.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "Engine/Canvas.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetDataMenu.h"

UAABrowser_ServersList::UAABrowser_ServersList()
{

	UCountryFlags* FlagsObject = NewObject<UCountryFlags>(UCountryFlags::StaticClass());
	Icons = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_army_Mat.hud_group_army_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_honor_Mat.hud_group_honor_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_PLP_a_Mat.hud_group_PLP_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_miles_Mat.hud_group_miles_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_punkbuster_Mat.hud_icon_punkbuster_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_locked_Mat.hud_group_locked_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_eta_Mat.hud_group_eta_Mat'"), NULL, LOAD_None, NULL)
	};
	IconDescriptions = { "Official", "Honor (Leased)", "Authorized", "MILES", "PunkBuster", "Password", "Instant Action" };

	TourIcons = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_Basic_sm_Mat.menu_touricon_Basic_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_Basic_sm_Mat.menu_touricon_Basic_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_172nd_sm_Mat.menu_touricon_172nd_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_10th_mtn_sm_Mat.menu_touricon_10th_mtn_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_Marksmanship_sm_Mat.menu_touricon_Marksmanship_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_AirBorne_school_sm_Mat.menu_touricon_AirBorne_school_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_82nd_sm_Mat.menu_touricon_82nd_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_Ranger_sm_Mat.menu_touricon_Ranger_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_Ranger_75th_sm_Mat.menu_touricon_Ranger_75th_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_CombatMedic_sm_Mat.menu_touricon_CombatMedic_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_SF_sm_Mat.menu_touricon_SF_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_SF_sm_Mat.menu_touricon_SF_sm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/menu_touricon_SF_sm_Mat.menu_touricon_SF_sm_Mat'"), NULL, LOAD_None, NULL),
	};
	FlagIcons = { FlagsObject };

	ColumnHeadings = { "Icons", "Server Name", "Map", "Players", "Ping", "Avg Honor" };
	InitColumnPerc = { 0.09, 0.35, 0.25, 0.11, 0.11, 0.09 };

	SortColumn = 4;
	ExpandLastColumn = true;
	//OnDrawItem = AABrowser_ServersList.MyOnDrawItem;
	WinHeight = 1;
	//OnDblClick = AABrowser_ServersList.MyOnDblClick;

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
		InitColumnPerc.RemoveAt(5, 1);
		ColumnHeadings.RemoveAt(5, 1);
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
	int32 i = 0;
	if (!bDebugging)
	{
		return;
	}
	for (i = 0; i < reports.Num(); i++)
	{
		if (reports[i].ListID == Id)
		{
			Log("Warning, overwriting existing ping report (" + i + ") for listid:" + Id @ S);
			reports[i].Ping = S;
			return;
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
	int32 i = 0;
	if (!bDebugging)
	{
		return;
	}
	for (i = 0; i < reports.Num(); i++)
	{
		if (reports[i].ListID == Id)
		{
			reports[i].receive = S;
			return;
		}
		if (reports[i].ListID > Id)
		{
		}
	}
	Log("Warning, no matching ping report found for listid:" + Id @ S);
	reports.insert(i, 1);
	reports[i].ListID = Id;
	reports[i].receive = S;
	*/
}

FString UAABrowser_ServersList::getreportsortstring(int32 idx)
{
	int32 i = 0;
	FString S = "";
	FString Port = "";
	TArray<FString> Parts = {};
	/*
	Divide(reports[idx].Ping, ":", S, Port);
	Split(S, ".", Parts);
	for (i = 0; i < 4; i++)
	{
		PadLeft(Parts[i], 4, "0");
	}
	PadLeft(Port, 5, "0");
	return JoinArray(Parts, ".") + Port;
	*/
	return "FAKE";     //FAKE   /ELiZ
}

void UAABrowser_ServersList::logall()
{
	int32 i = 0;
	int32 Id = 0;
	FString idx = "";
	FString ListID = "";
	FString outping = "";
	FString inping = "";
	UGUIMultiColumnList* Temp = nullptr;
	if (!bDebugging)
	{
		return;
	}
	idx = "Index";
	ListID = "ListID";
	outping = "Address Pinged";
	inping = "Received";
	/*
	PadRight(idx, 8);
	PadRight(ListID, 8);
	PadRight(outping, 22);
	Temp = new (None) UGUIMultiColumnList::StaticClass();
	Temp.SortColumn = 0;
	Temp.__GetSortString__Delegate = getreportsortstring;
	for (i = 0; i < reports.Num(); i++)
	{
		Temp.AddedItem();
	}
	Temp.Sort();
	Log(idx + ListID + outping + inping);
	for (i = 0; i < reports.Num(); i++)
	{
		Id = Temp.SortData[i].SortItem;
		idx = Id;
		ListID = reports[Id].ListID;
		outping = reports[Id].Ping;
		inping = reports[Id].receive;
		PadRight(idx, 8);
		PadRight(ListID, 8);
		PadRight(outping, 22);
		Log(idx + ListID + outping + inping);
	}
	*/
}

void UAABrowser_ServersList::Clear()
{
	/*
	PingStart = 0;
	StopPings();
	Servers.RemoveAt(0, Servers.Num());
	ItemCount = 0;
	Clear();
	*/
}

void UAABrowser_ServersList::CopyServerToClipboard()
{
	FString URL = "";
	AServerBrowserBase* sbBase = nullptr;
	FGameSpyServerItem ServerItem;
	/*
	if (IsValid())
	{
		sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
		if (sbBase != nullptr)
		{
			sbBase.GetSpecificServer(Index, ServerItem);
		}
		URL = PlayerOwner().GetURLProtocol() + "://" + sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
		if (Default.ServerPassword != "")
		{
			URL = URL + "?Password=" + Default.ServerPassword;
		}
		PlayerOwner().CopyToClipboard(URL);
	}
	*/
}

void UAABrowser_ServersList::Connect(bool Spectator,FString AdminPassword,bool bPlayerAdminPassword)
{
	FString URL = "";
	FString ETACommand = "";
	AServerBrowserBase* sbBase = nullptr;
	FGameSpyServerItem ServerItem;
	/*
	if (IsValid())
	{
		if (!CanConnect())
		{
			return;
		}
		sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
		if (sbBase != nullptr)
		{
			sbBase.GetSpecificServer(Index, ServerItem);
		}
		if (ServerItem.bExploreTheArmy == 1)
		{
			ETACommand = "ETAJoinServer" @ sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port) @ Cast<AStudentController>(PlayerOwner()).sETAUserSelectedSurName @ Cast<AStudentController>(PlayerOwner()).sETAUserSelectedNickName;
			if (ServerItem.bPassword == 1 && Default.ServerPassword != "")
			{
				ETACommand = ETACommand @ Default.ServerPassword;
			}
			PlayerOwner().ConsoleCommand(ETACommand);
		}
		else
		{
			URL = PlayerOwner().GetURLProtocol() + "://" + sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
			if (Len(AdminPassword) > 0)
			{
				if (bPlayerAdminPassword)
				{
					URL = URL + "?PAPassword=" + AdminPassword;
				}
				else
				{
					URL = URL + "?Password=" + AdminPassword;
				}
			}
			else
			{
				if (ServerItem.bPassword == 1 && Default.ServerPassword != "")
				{
					URL = URL + "?Password=" + Default.ServerPassword;
				}
			}
			if (Spectator)
			{
				URL = URL + "?SpectatorOnly=1";
			}
			if (bIsLAN)
			{
				URL = URL + "?LAN";
				if (ServerItem.bRequiresAuthorization == 0 && 0 == Len(Cast<AHumanController>(PlayerOwner())->GetAuthUserName()) || "UserName" ~= Cast<AHumanController>(PlayerOwner())->GetAuthUserName())
				{
					Cast<AHumanController>(PlayerOwner())->UserName = Cast<AHumanController>(PlayerOwner())->LANPlayerName;
					AHumanController::StaticClass().Default.UserName = Cast<AHumanController>(PlayerOwner())->LANPlayerName;
					Cast<AHumanController>(PlayerOwner())->SaveConfig();
				}
			}
			PlayerOwner().ClientTravel(URL, 0, false);
		}
	}
	*/
}

bool UAABrowser_ServersList::MyOnDblClick(UGUIComponent* Sender)
{
	//Connect(false);
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
		switch(Key)
		{
				case 13:
					Connect(false);
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
	AServerBrowserBase* sbBase = nullptr;
	/*
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != nullptr)
	{
		ItemCount = sbBase.GetNumServers();
		if (ItemCount == 0 && !bRetrievalFailed)
	}
	{
		bRetrievalFailed = false;
	}
	*/
}

void UAABrowser_ServersList::MyOnUpdateServerListFailed(FString Reason)
{
	//bRetrievalFailed = true;
	//Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Internet Servers Failure", Reason);
}

void UAABrowser_ServersList::MyPingTimeout(int32 ListID, EPingCause PingCause)
{
	/*
	int32 i = 0;
	AddReceiveReport(ListID, "TIMEOUT");
	if (ListID < 0 || ListID >= Servers.Num())
	{
		PingStart = 0;
		return;
	}
	i = 0;
	if (i < OutstandingPings.Num())
	{
		if (OutstandingPings[i] == ListID)
		{
			OutstandingPings.RemoveAt(i, 1);
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
		NeedsSorting = true;
		AutopingServers();
	}
	*/
}

void UAABrowser_ServersList::MyReceivedPingInfo(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
	int32 i = 0;
	int32 Flags = 0;
	bool bFound = false;
	/*
	if (ListID < 0 || ListID >= Servers.Num())
	{
		PingStart = 0;
		AddReceiveReport(ListID, S.IP + ":" + S.Port);
		return;
	}
	else
	{
		AddReceiveReport(ListID, S.IP + ":" + S.Port);
	}
	Flags = Servers[ListID].Flags;
	Servers[ListID] = S;
	Servers[ListID].Flags = Flags;
	i = PingStart;
	if (i < ListID && i < Servers.Num())
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
	if (i < OutstandingPings.Num())
	{
		if (OutstandingPings[i] == ListID)
		{
			bFound = true;
			OutstandingPings.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	UpdatedItem(ListID);
	if (IsValid() && ListID == SortData[Index].SortItem)
	{
		OnChange(nullptr);
	}
	if (PingCause == 2)
	{
		NumReceivedPings++;
		NumPlayers += S.CurrentPlayers;
		NeedsSorting = true;
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
	int32 i = 0;
	for (i = 0; i < Servers.Num(); i++)
	{
		AddedItem();
	}
	RePingServers();
	SetTimer(5, true);
	*/
}

void UAABrowser_ServersList::MyQueryFinished(EResponseInfo ResponseInfo, int32 Info)
{
	/*
	int32 i = 0;
	if (ResponseInfo == 3)
	{
		if (bPresort)
		{
			if (ItemCount > 0)
			{
				Log(Name @ "RECEIVED QUERYFINISHED NOTICE WITH ITEMCOUNT > 0!!! ITEMCOUNT:" + ItemCount @ "Info:" + Info);
				return;
			}
			for (i = 0; i < Servers.Num(); i++)
			{
				AddedItem();
			}
		}
		RePingServers();
		SetTimer(5, true);
	}
	*/
}

void UAABrowser_ServersList::InvalidatePings()
{
	/*
	int32 i = 0;
	reports.RemoveAt(0, reports.Num());
	StopPings();
	PingStart = 0;
	NumReceivedPings = 0;
	NumPlayers = 0;
	for (i = 0; i < Servers.Num(); i++)
	{
		Servers[i].Ping = 9999;
		UpdatedItem(i);
	}
	*/
}

void UAABrowser_ServersList::AutopingServers()
{
	int32 i = 0;
	int32 j = 0;
	i = PingStart;
	/*
	if (i < Servers.Num() && OutstandingPings.Num() < UseSimultaneousPings)
	{
		if (Servers[i].Ping == 9999)
		{
			for (j = 0; j < OutstandingPings.Num(); j++)
			{
				if (OutstandingPings[j] == i)
				{
				}
			}
			if (j == OutstandingPings.Num())
			{
				OutstandingPings[j] = i;
				AddPingReport(i, Servers[i].IP + ":" + Servers[i].Port);
			}
		}
		i++;
	}
	if (OutstandingPings.Num() == 0)
	{
		logall();
	}
	*/
}

void UAABrowser_ServersList::StopPings()
{
	//OutstandingPings.RemoveAt(0, OutstandingPings.Num());
}

int32 UAABrowser_ServersList::RemoveServerAt(int32 pos)
{
	int32 i = 0;
	/*
	if (!IsValidIndex(pos))
	{
		return -1;
	}
	i = Servers.Num() - 1;
	if (pos < i)
	{
		Servers[pos] = Servers[i];
	}
	Servers.RemoveAt(i, 1);
	if (i == Index)
	{
	}
	RemovedItem(i);
	SetIndex(Index);
	*/
	NeedsSorting = true;
	return pos;
}

int32 UAABrowser_ServersList::RemoveCurrentServer()
{
	int32 OldItem = 0;
	if (IsValid())
	{
		OldItem = SortData[Index].SortItem;
		if (RemoveServerAt(Index) != -1)
		{
			return OldItem;
		}
	}
	return -1;
}

FString UAABrowser_ServersList::GetSortString(int32 i)
{
	FString S="";
	FString t="";
	/*
	switch(SortColumn)
	{
			case 0:
				S = BuildFlagString(Servers[i].Flags) + i;
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
				S += t + i;
				break;
			default:
				S = Servers[i].Ping;
				PadLeft(S, 5, "0");
				S += i;
				break;
	}
	*/
	return S;
}

FString UAABrowser_ServersList::Get(bool bGuarantee)
{
	FString S="";
	/*
	if (Servers.Num() <= 0)
	{
		return "";
	}
	if (IsValid())
	{
		S = Servers[CurrentListId()].IP + ":" + Servers[CurrentListId()].Port;
	}
	else
	{
		if (Servers.Num() > 0 && bGuarantee)
		{
			S = Servers[SortData[0].SortItem].IP + ":" + Servers[SortData[0].SortItem].Port;
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
	int32 i = 0;
	for (i = 0; i < Servers.Num(); i++)
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
		bInitialized = true;
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
	int32 Value = 0;
	Value = 9999;
	/*
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
	AServerBrowserBase* sbBase = nullptr;
	FGameSpyServerItem ServerItem;
	FString sVersion = "";
	int32 TourID = 0;
	int32 MissionID = 0;
	FString missionFile = "";
	FString MissionName = "";
	bool bPB = false;
	/*
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != nullptr)
	{
		sbBase.GetSpecificServer(Index, ServerItem);
	}
	sVersion = GetVersionAGPMajor() + "." + GetVersionAGPMinor() + "." + GetVersionAGPTiny() + "." + GetVersionAGPSubTiny();
	if (ServerItem.GameVer != sVersion)
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "You can only play on version " + sVersion + " servers.");
		return false;
	}
	MissionName = ServerItem.MapName;
	TourID = ServerItem.Tour;
	PlayerOwner().Level.GetLevelMissionPrivate(MissionName, TourID, missionFile);
	PlayerOwner().Level.GetLevelTourAndMissionPrivate(missionFile, TourID, MissionID);
	if (ServerItem.bExploreTheArmy == 1)
	{
		if (0 == Len(Cast<AStudentController>(PlayerOwner()).sETAUserSelectedNickName) || 0 == Len(Cast<AStudentController>(PlayerOwner()).sETAUserSelectedSurName))
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Instant Action Names Not Selected", "");
			return false;
		}
	}
	if (!bIsLAN)
	{
		if (0 == ServerItem.bExploreTheArmy && Cast<AHumanController>(PlayerOwner()) != nullptr)
		{
			Cast<AHumanController>(PlayerOwner())->LoadJacket();
			if (Cast<AHumanController>(PlayerOwner())->UserName ~= "UserName" || Cast<AHumanController>(PlayerOwner())->UserPassword ~= "UserPassword" || Len(Cast<AHumanController>(PlayerOwner())->UserPassword) == 0)
			{
				Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Profile Not Found", "You must load your profile by logging in to the Personnel Jacket in order to play online.");
				return false;
			}
		}
		if (Cast<AHumanController>(PlayerOwner()) != nullptr && Cast<AHumanController>(PlayerOwner())->iCompleted[1] != 15 && !TourID == 1 || TourID == 2 || TourID == 3 || TourID == 6 || TourID == 7 || TourID == 8 || TourID == 11)
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
				if (0 == Len(Cast<AHumanController>(PlayerOwner())->GetAuthUserName()) || "UserName" ~= Cast<AHumanController>(PlayerOwner())->GetAuthUserName())
				{
					Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Profile Not Found", "This server requires authorization. You must load your profile by logging in to the Personnel Jacket in order to play on this LAN server.");
					return false;
				}
			}
			else
			{
				if (0 == Len(Cast<AHumanController>(PlayerOwner())->GetAuthUserName()) || "UserName" ~= Cast<AHumanController>(PlayerOwner())->GetAuthUserName() && 0 == Len(Cast<AHumanController>(PlayerOwner())->LANPlayerName))
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
		SetServerPassword(Cast<UAAGetDataMenu>(Controller.ActivePage).ed_Data.GetText());
		Connect(false);
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
	UFavorites* Favorites = nullptr;
	FFavoriteServer Server;
	FString IPAddress = "";
	/*
	IPAddress = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser().IpAddrToString(ServerItem.IP, 0);
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
	float CellLeft = 0;
	float CellWidth = 0;
	float DrawX = 0;
	float IconPosX = 0;
	float IconPosY = 0;
	float TotalIconWidth = 0;
	FString ServerName = "";
	FString Ping = "";
	FString AverageHonor = "";
	UGUIStyles* DStyle = nullptr;
	AServerBrowserBase sbBase;
	FGameSpyServerItem ServerItem;
	FFloatBox FlagRenderData = FFloatBox({});
	/*
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != nullptr)
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
			DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
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
				DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
				Canvas.SetPos(IconPosX, IconPosY);
				Canvas.DrawTile(Icons[1], DrawX, 14, 0, 0, 31, 31);
				IconPosX += 14;
				TotalIconWidth += 14;
			}
		}
		if (!ServerItem.bOfficial == 1 || ServerItem.bLeased == 1)
		{
			DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
			Canvas.SetPos(IconPosX, IconPosY);
			Canvas.DrawTile(Icons[2], DrawX, 14, 0, 0, Icons[2].MaterialUSize(), Icons[2].MaterialVSize());
			IconPosX += 14;
			TotalIconWidth += 14;
		}
	}
	else
	{
		DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(Icons[6], DrawX, 14, 0, 0, Icons[6].MaterialUSize(), Icons[6].MaterialVSize());
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (ServerItem.bMiles == 1 && TotalIconWidth < CellWidth)
	{
		DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(Icons[3], DrawX, 14, 0, 0, 31, 31);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (ServerItem.bPassword == 1 && TotalIconWidth < CellWidth)
	{
		DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(Icons[5], DrawX, 14, 0, 0, 31, 31);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (ServerItem.bPunkBuster == 1 && TotalIconWidth < CellWidth)
	{
		DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(Icons[4], DrawX, 14, 0, 0, 31, 31);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (ServerItem.Tour >= 0 && ServerItem.Tour < 32 && ServerItem.Tour < TourIcons.Num() && TourIcons[ServerItem.Tour] != nullptr && TotalIconWidth < CellWidth)
	{
		DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(TourIcons[ServerItem.Tour], DrawX, 14, 0, 0, 31, 31);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	if (FlagIcons.GetRenderData(FlagRenderData, ServerItem.Locale) && TotalIconWidth < CellWidth)
	{
		DrawX = FMath::Min(14, X + CellLeft + CellWidth - IconPosX);
		Canvas.SetPos(IconPosX, IconPosY);
		Canvas.DrawTile(FlagIcons.FlagTexture, DrawX, 14, FlagRenderData.X1, FlagRenderData.Y1, FlagRenderData.X2, FlagRenderData.Y2);
		IconPosX += 14;
		TotalIconWidth += 14;
	}
	ServerName = ServerItem.Name;
	if (Cast<AHumanController>(PlayerOwner())->bDisableServerColorsInBrowser)
	{
		ServerName = StripColorCodes(ServerName);
	}
	GetCellLeftWidth(1, CellLeft, CellWidth);
	DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, ServerName, FontScale);
	GetCellLeftWidth(2, CellLeft, CellWidth);
	DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, ServerItem.MapName, FontScale);
	GetCellLeftWidth(3, CellLeft, CellWidth);
	DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, ServerItem.NumPlayers + "/" + ServerItem.MaxPlayers & 255, FontScale);
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
	Ping += "/" + Eval(ServerItem.AveragePlayerPing >= 0 && ServerItem.AveragePlayerPing < 9999, ServerItem.AveragePlayerPing, "?");
	DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, Ping, FontScale);
	if (!bIsLAN)
	{
		GetCellLeftWidth(5, CellLeft, CellWidth);
		AverageHonor = Eval(ServerItem.AverageHonor != -1, ServerItem.AverageHonor, "N/A");
		DStyle.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, AverageHonor, FontScale);
	}
	*/
}

bool UAABrowser_ServersList::TestGroups(FString Groups)
{
	bool bLegalList = false;
	int32 PlayerGroup = 0;
	FString sTemp = "";
	int32 iPos = 0;
	FString test_string = "";
	int32 test_group = 0;
	/*
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
			bLegalList = true;
		}
	}
	*/
	if (bLegalList)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void UAABrowser_ServersList::SBRePingAllServers()
{
	AServerBrowserBase* sbBase = nullptr;
	/*
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != nullptr)
	{
		sbBase.RePingAllServers();
	}
	*/
}

void UAABrowser_ServersList::OnSortChanged()
{
	FString sField = "";
	EGameSpyCompareMode eCompareCode = EGameSpyCompareMode::SORT_INT;
	AServerBrowserBase* sbBase = nullptr;
	/*
	switch(SortColumn)
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
			break;
	}
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase == nullptr)
	{
		return;
	}
	sbBase.SortServers(sField, !SortDescending, eCompareCode);
	*/
}
