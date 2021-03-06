// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_RulesList/Browser_RulesList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_ServersList/Browser_ServersList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "Engine/Canvas.h"

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

void UBrowser_RulesList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	__OnDrawItem__Delegate = MyOnDrawItem;
	__OnKeyEvent__Delegate = InternalOnKeyEvent;
	InitComponent(MyController, MyOwner);
	*/
}

void UBrowser_RulesList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	float CellLeft = 0;
	float CellWidth = 0;
	/*
	GetCellLeftWidth(0, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, LocalizeRules(MyServersList.Servers[listitem].ServerInfo[i].Key), FontScale);
	GetCellLeftWidth(1, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, LocalizeRules(MyServersList.Servers[listitem].ServerInfo[i].Value), FontScale);
	*/
}

bool UBrowser_RulesList::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (InternalOnKeyEvent(Key, State, Delta))
	{
		return true;
	}
	if (State == 1)
	{
		switch(Key)
		{
			case 13:
				MyServersList.Connect(false);
				return true;
				break;
			case 116:
				MyPage.RefreshList();
				return true;
				break;
			default:
		}
	}
	*/
	return false;
}

FString UBrowser_RulesList::LocalizeRules(FString Code)
{
	if(Code.ToUpper() =="TRUE")
	{
		return TrueString;
	}
	if(Code.ToUpper() =="FALSE")
	{
		return FalseString;
	}
	if(Code.ToUpper() =="SERVERMODE")
	{
		return ServerModeString;
	}
	if(Code.ToUpper() =="DEDICATED")
	{
		return DedicatedString;
	}
	if(Code.ToUpper() =="NON-DEDICATED")
	{
		return NonDedicatedString;
	}
	if(Code.ToUpper() =="ADMINNAME")
	{
		return AdminNameString;
	}
	if(Code.ToUpper() =="ADMINEMAIL")
	{
		return AdminEmailString;
	}
	if(Code.ToUpper() =="PASSWORD")
	{
		return PasswordString;
	}
	if(Code.ToUpper() =="GAMESTATS")
	{
		return GameStatsString;
	}
	if(Code.ToUpper() =="GAMESPEED")
	{
		return GameSpeedString;
	}
	if(Code.ToUpper() =="MUTATOR")
	{
		return MutatorString;
	}
	if(Code.ToUpper() =="BALANCETEAMS")
	{
		return BalanceTeamsString;
	}
	if(Code.ToUpper() =="PLAYERSBALANCETEAMS")
	{
		return PlayersBalanceTeamsString;
	}
	if(Code.ToUpper() =="FRIENDLYFIRE")
	{
		return FriendlyFireString;
	}
	if(Code.ToUpper() =="GOALSCORE")
	{
		return GoalScoreString;
	}
	if(Code.ToUpper() =="TIMELIMIT")
	{
		return TimeLimitString;
	}
	if(Code.ToUpper() =="MINPLAYERS")
	{
		return MinPlayersString;
	}
	if(Code.ToUpper() =="TRANSLOCATOR")
	{
		return TranslocatorString;
	}
	if(Code.ToUpper() =="WEAPONSTAY")
	{
		return WeaponStayString;
	}
	return Code;     //FAKE    /ELiZ
}
