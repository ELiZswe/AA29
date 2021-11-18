// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_RulesList/AABrowser_RulesList.h"

UAABrowser_RulesList::UAABrowser_RulesList()
{
	HostnameString = "Hostname";
	AddressString = "Address";
	MapNameString = "Map Name";
	GametypeString = "Gametype";
	TourString = "Tour";
	PlayersString = "Players";
	PingString = "Ping";
	AverageHonorString = "Avg Honor";
	CurrentRoundString = "Round";
	MissionTimeRemainingString = "Time Left";
	OfficialString = "Official";
	HonorString = "Honor";
	LocaleString = "Locale";
	PunkBusterString = "PunkBuster";
	MinHonorString = "Min Honor";
	MaxHonorString = "Max Honor";
	CheatsString = "Cheats";
	TournamentString = "Tournament";
	MILESString = "MILES";
	OperatingSystemString = "OS";
	ColumnHeadings = { "Setting", "Value" };
	InitColumnPerc = { 0.4, 0.6 };
	ExpandLastColumn = true;
}


void UAABrowser_RulesList::OnGetServerRules(int32& ItemIndex, FGameSpyServerItem& ServerItem)
{
}

void UAABrowser_RulesList::Clear()
{
	//ItemCount = 0;
	//Clear();
}

FString UAABrowser_RulesList::TwoDigitString(int32 Num)
{
	/*
	if (Num < 10 && Num >= 0)
	{
		Return "0" $ Num;
	}
	else
	{
		Return Num;
	}
	*/
	return "00";     //FAKE   /ELiZ
}

void UAABrowser_RulesList::FormatTime(int32 Seconds)
{
	//Return Seconds / 60 $ ":" $ TwoDigitString(Seconds % 60);
}

void UAABrowser_RulesList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	local XInterface.GUIStyles DrawStyle;
	local IpDrv.ServerBrowserBase sbBase;
	local ServerBrowserBase.GameSpyServerItem ServerItem;
	local int ItemIndex;
	local string sRule;
	local string sValue;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase == None)
	{
		Return;
	}
	if (!OnGetServerRules(ItemIndex, ServerItem))
	{
		Return;
	}
	if ("GameSpy" ~= AGP_HUD(PlayerOwner().myHUD).ServerBrowser && i >= 12)
	{
		++i;
	}
	Switch(i)
	{
			case 0:
				sRule = HostnameString;
				if (HumanController(PlayerOwner()).bDisableServerColorsInBrowser)
				{
					sValue = StripColorCodes(ServerItem.Name);
					break;
				}
				sValue = ServerItem.Name;
	}
	GOTO JL04B1;
		case 1:
			sRule = AddressString;
			sValue = sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
			GOTO JL04B1;
		case 2:
			sRule = MapNameString;
			sValue = ServerItem.MapName;
			GOTO JL04B1;
		case 3:
			sRule = GametypeString;
			sValue = Eval(ServerItem.bCoop == 1, "CO", "MP");
			GOTO JL04B1;
		case 4:
			sRule = TourString;
			sValue = PlayerOwner().Level.GetTourName(ServerItem.Tour);
			GOTO JL04B1;
		case 5:
			sRule = PlayersString;
			sValue = ServerItem.NumPlayers $ "/" $ ServerItem.MaxPlayers;
			GOTO JL04B1;
		case 6:
			sRule = PingString;
			sValue = Eval(ServerItem.Ping == 9999, "?", ServerItem.Ping);
			GOTO JL04B1;
		case 7:
			sRule = AverageHonorString;
			sValue = Eval(ServerItem.AverageHonor != -1, ServerItem.AverageHonor, "N/A");
			GOTO JL04B1;
		case 8:
			sRule = CurrentRoundString;
			sValue = ServerItem.CurrentRound $ "/" $ ServerItem.RoundsPerMatch;
			GOTO JL04B1;
		case 9:
			sRule = MissionTimeRemainingString;
			sValue = FormatTime(ServerItem.MissionTimeRemaining);
			GOTO JL04B1;
		case 10:
			sRule = OfficialString;
			sValue = Eval(ServerItem.bOfficial == 1, "Yes", "No");
			GOTO JL04B1;
		case 11:
			sRule = HonorString;
			sValue = Eval(0 == ServerItem.bExploreTheArmy && ServerItem.bOfficial == 1 || ServerItem.bLeased == 1, "Yes", "No");
			GOTO JL04B1;
		case 12:
			sRule = LocaleString;
			sValue = ServerItem.Locale;
			GOTO JL04B1;
		case 13:
			sRule = PunkBusterString;
			sValue = Eval(ServerItem.bPunkBuster == 1, "Enabled", "Disabled");
			GOTO JL04B1;
		case 14:
			sRule = MinHonorString;
			sValue = ServerItem.MinHonor;
			GOTO JL04B1;
		case 15:
			sRule = MaxHonorString;
			sValue = ServerItem.MaxHonor;
			GOTO JL04B1;
		case 16:
			sRule = CheatsString;
			sValue = Eval(ServerItem.bCheats == 1, "Enabled", "Disabled");
			GOTO JL04B1;
		case 17:
			sRule = TournamentString;
			sValue = Eval(ServerItem.bTournament == 1, "Yes", "No");
			GOTO JL04B1;
		case 18:
			sRule = MILESString;
			sValue = Eval(ServerItem.bMiles == 1, "Yes", "No");
			GOTO JL04B1;
		case 19:
			sRule = OperatingSystemString;
			sValue = ServerItem.OperatingSystem;
			GOTO JL04B1;
		default:
		JL04B1:
			if (bSelected)
			{
				SelectedStyle.Draw(Canvas, 3, X, Y - 2, W, H + 2);
				DrawStyle = SelectedStyle;
			}
			else
			{
				DrawStyle = Style;
			}
			GetCellLeftWidth(0, CellLeft, CellWidth);
			Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, sRule, FontScale);
			GetCellLeftWidth(1, CellLeft, CellWidth);
			Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, sValue, FontScale);
		}
	*/
}