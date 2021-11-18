// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/AAWeaponClass_UnitBox/AAWeaponClass_UnitBox.h"
#include "AA29/Object/GUI/GUIComponent/AAWeaponClass_UnitBoxHeader/AAWeaponClass_UnitBoxHeader.h"

UAAWeaponClass_UnitBox::UAAWeaponClass_UnitBox()
{
	UAAWeaponClass_UnitBoxHeader* aMyHeader = NewObject<UAAWeaponClass_UnitBoxHeader>(UAAWeaponClass_UnitBoxHeader::StaticClass());
	Header = aMyHeader;
	//FireTeamListClass = "AGP_Interface.AAWeaponClass_FireTeamList";
	bScaleItemsToWidth = true;
}

void UAAWeaponClass_UnitBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
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

void UAAWeaponClass_UnitBox::Timer()
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

void UAAWeaponClass_UnitBox::InitFireTeams(AAGP_TeamInfo* NewTeam)
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
		FireTeams[i] = AAWeaponClass_FireTeamList(addItem(FireTeamListClass));
		FireTeams[i].InitList(Team, i);
	}
	*/
}