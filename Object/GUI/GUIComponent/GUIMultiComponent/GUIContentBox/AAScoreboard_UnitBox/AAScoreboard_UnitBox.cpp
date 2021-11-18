// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/AAScoreboard_UnitBox/AAScoreboard_UnitBox.h"
#include "AA29/Object/GUI/GUIComponent/AAScoreboard_UnitBoxHeader/AAScoreboard_UnitBoxHeader.h"

UAAScoreboard_UnitBox::UAAScoreboard_UnitBox()
{
	UAAScoreboard_UnitBoxHeader* aMyHeader = NewObject<UAAScoreboard_UnitBoxHeader>(UAAScoreboard_UnitBoxHeader::StaticClass());
	Header = aMyHeader;
	//FireTeamListClass = "AGP_Interface.AAScoreboard_FireTeamList";
	bScaleItemsToWidth = true;
}

void UAAScoreboard_UnitBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	if (Team != None)
	{
		InitFireTeams(Team);
	}
	SetTimer(0.1, True);
	*/
}

void UAAScoreboard_UnitBox::Timer()
{
	/*
	local AGP_Gameplay.AGP_TeamInfo CurrentTeam;
	CurrentTeam = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	if (CurrentTeam != Team)
	{
		InitFireTeams(CurrentTeam);
	}
	*/
}

void UAAScoreboard_UnitBox::InitFireTeams(AAGP_TeamInfo* NewTeam)
{
	/*
	local int i;
	for (i = 0; i < FireTeams.Length; i++)
	{
		RemoveItem(FireTeams[i]);
	}
	Team = NewTeam;
	for (i = 0; i < 5; i++)
	{
		if (Team.FTCount[i] <= 0)
		{
		}
		FireTeams[i] = AAScoreboard_FireTeamList(addItem(FireTeamListClass));
		FireTeams[i].InitList(Team, i);
	}
	*/
}