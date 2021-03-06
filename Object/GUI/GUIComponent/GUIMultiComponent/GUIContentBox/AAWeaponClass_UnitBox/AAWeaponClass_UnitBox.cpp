// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/AAWeaponClass_UnitBox/AAWeaponClass_UnitBox.h"
#include "AA29/Object/GUI/GUIComponent/AAWeaponClass_UnitBoxHeader/AAWeaponClass_UnitBoxHeader.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAAWeaponClass_UnitBox::UAAWeaponClass_UnitBox()
{
	UAAWeaponClass_UnitBoxHeader* MyHeader2 = NewObject<UAAWeaponClass_UnitBoxHeader>(UAAWeaponClass_UnitBoxHeader::StaticClass());
	Header = MyHeader2;
	FireTeamListClass = "AGP_Interface.AAWeaponClass_FireTeamList";
	bScaleItemsToWidth = true;
}

void UAAWeaponClass_UnitBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	Team = Cast<AGP_TeamInfo>(PlayerOwner().PlayerReplicationInfo.Team);
	if (Team != nullptr)
	{
		InitFireTeams(Team);
	}
	SetTimer(0.1, true);
	*/
}

void UAAWeaponClass_UnitBox::Timer()
{
	AAGP_TeamInfo* CurrentTeam = nullptr;
	/*
	CurrentTeam = Cast<AGP_TeamInfo>(PlayerOwner().PlayerReplicationInfo.Team);
	if (CurrentTeam != Team)
	{
		InitFireTeams(CurrentTeam);
	}
	*/
}

void UAAWeaponClass_UnitBox::InitFireTeams(AAGP_TeamInfo* NewTeam)
{
	int32 i = 0;
	/*
	for (i = 0; i < FireTeams.Num(); i++)
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
