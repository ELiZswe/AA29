// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_RulesList/Browser_RulesList.h"

UBrowser_RulesList::UBrowser_RulesList()
{
	TrueString = "Enabled";
	FalseString = "Disabled";
	ServerModeString = "Server Mode";
	DedicatedString = "Dedicated";
	NonDedicatedString = "Non-Dedicated";
	AdminNameString = "Server Admin";
	AdminEmailString = "Admin Email";
	PasswordString = "Requires Password";
	GameStatsString = "UT2004 Stats";
	GameSpeedString = "Game Speed";
	MutatorString = "Mutator";
	BalanceTeamsString = "Bots Balance Teams";
	PlayersBalanceTeamsString = "Balance Teams";
	FriendlyFireString = "Friendly Fire";
	GoalScoreString = "Goal Score";
	TimeLimitString = "Time Limit";
	MinPlayersString = "Minimum Players (bots)";
	TranslocatorString = "Translocator";
	WeaponStayString = "Weapons Stay";
	ColumnHeadings = { "Setting", "Value" };
	InitColumnPerc = { 0.25, 0.25 };
	ExpandLastColumn = true;
}

void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	__OnDrawItem__Delegate = MyOnDrawItem;
	__OnKeyEvent__Delegate = InternalOnKeyEvent;
	InitComponent(MyController, MyOwner);
	*/
}

void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	GetCellLeftWidth(0, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, LocalizeRules(MyServersList.Servers[listitem].ServerInfo[i].Key), FontScale);
	GetCellLeftWidth(1, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, LocalizeRules(MyServersList.Servers[listitem].ServerInfo[i].Value), FontScale);
	*/
}

bool InternalOnKeyEvent(uint8 &Key, uint8 &State, float Delta)
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
					MyServersList.Connect(False);
					Return True;
					break;
				case 116:
					MyPage.RefreshList();
					Return True;
					break;
				default:
		}
	}
	*/
	return false;
}

FString LocalizeRules(FString Code)
{
	/*
	switch(Caps(Code))
	{
			case "TRUE":
				return TrueString;
			case "FALSE":
				return FalseString;
			case "SERVERMODE":
				return ServerModeString;
			case "DEDICATED":
				return DedicatedString;
			case "NON-DEDICATED":
				return NonDedicatedString;
			case "ADMINNAME":
				return AdminNameString;
			case "ADMINEMAIL":
				return AdminEmailString;
			case "PASSWORD":
				return PasswordString;
			case "GAMESTATS":
				return GameStatsString;
			case "GAMESPEED":
				return GameSpeedString;
			case "MUTATOR":
				return MutatorString;
			case "BALANCETEAMS":
				return BalanceTeamsString;
			case "PLAYERSBALANCETEAMS":
				return PlayersBalanceTeamsString;
			case "FRIENDLYFIRE":
				return FriendlyFireString;
			case "GOALSCORE":
				return GoalScoreString;
			case "TIMELIMIT":
				rturn TimeLimitString;
			case "MINPLAYERS":
				return MinPlayersString;
			case "TRANSLOCATOR":
				return TranslocatorString;
			case "WEAPONSTAY":
				return WeaponStayString;
			default:
				return Code;
	}
	*/
	return "FAKE";     //FAKE    /ELiZ
}