// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AATeamList.h"

UAATeamList::UAATeamList()
{
	//Icons(0) = Texture'T_AA2_UI.HUD.hud_icon_dev';
	//Icons(1) = Texture'T_AA2_UI.HUD.hud_icon_dev_army';
	//Icons(2) = Texture'T_AA2_UI.HUD.hud_icon_beta';
	//Icons(3) = Texture'T_AA2_UI.HUD.hud_icon_army_active';
	//Icons(4) = Texture'T_AA2_UI.HUD.hud_icon_navy';
	//Icons(5) = Texture'T_AA2_UI.HUD.hud_icon_airforce';
	//Icons(6) = Texture'T_AA2_UI.HUD.hud_icon_marine';
	//Icons(7) = Texture'T_AA2_UI.HUD.hud_group_coastguard';
	//Icons(8) = Texture'T_AA2_UI.HUD.hud_icon_punkbuster';
	//Icons(9) = Texture'T_AA2_UI.HUD.hud_group_aacm';
	//Icons(10) = Texture'T_AA2_UI.HUD.hud_group_volunteer';
	IconDescriptions = { "Dev Team Member", "Army Dev Team", "Beta Tester", "U.S. Army Active", "U.S. Navy", "U.S. Air Force", "U.S. Marine", "U.S. Coast Guard", "EvenBalance", "AACM", "Volunteers" };
	//rank(0) = Texture'T_AA2_UI.HUD.hud_icon_msg';
	//rank(1) = Texture'T_AA2_UI.HUD.hud_icon_sfc';
	//rank(2) = Texture'T_AA2_UI.HUD.hud_icon_ssgt';
	//rank(3) = Texture'T_AA2_UI.HUD.hud_icon_sgt';
	//rank(4) = Texture'T_AA2_UI.HUD.hud_icon_cpl';
	//rank(5) = Texture'T_AA2_UI.HUD.hud_icon_pvt';
	RankDescriptions = {"Master Sergeant", "Sergeant First Class", "Staff Sergeant", "Sergeant", "Corporal", "Private"};
	//Class(0) = Texture'T_AA2_UI.HUD.hud_icon_r'
	//Class(1) = Texture'T_AA2_UI.HUD.hud_icon_g'
	//Class(2) = Texture'T_AA2_UI.HUD.hud_icon_ar'
	//Class(3) = Texture'T_AA2_UI.HUD.hud_icon_s'
	//Class(4) = Texture'T_AA2_UI.HUD.hud_icon_vip'
	ClassDescriptions = { "Rifleman", "Grenadier", "Automatic Rifleman", "Advanced Marksman", "VIP" };
	//SubClass(0) = Texture'T_AA2_UI.HUD.hud_icon_medic'
	SubClassDescriptions = { "Medic" };
	//SpecialForces(0) = Texture'T_AA2_UI.HUD.hud_icon_18_b'
	//SpecialForces(1) = Texture'T_AA2_UI.HUD.hud_icon_18_c'
	//SpecialForces(2) = Texture'T_AA2_UI.HUD.hud_icon_18_z'
	SpecialForcesDescriptions = { "SF Weapons Sgt (SPR)", "SF Engineer (SOPMOD M4 Carbine)", "SF Operations Sgt (M249 SAW)" };
	//ExtraSpecialForces(0) = Texture'T_AA2_UI.HUD.hud_icon_18_a'
	//ExtraSpecialForces(1) = Texture'T_AA2_UI.HUD.hud_icon_18_b'
	//ExtraSpecialForces(2) = Texture'T_AA2_UI.HUD.hud_icon_18_c'
	//ExtraSpecialForces(3) = Texture'T_AA2_UI.HUD.hud_icon_18_d'
	//ExtraSpecialForces(4) = Texture'T_AA2_UI.HUD.hud_icon_18_e'
	//ExtraSpecialForces(5) = Texture'T_AA2_UI.HUD.hud_icon_18_f'
	//ExtraSpecialForces(6) = Texture'T_AA2_UI.HUD.hud_icon_18_z'
	ExtraSpecialForcesDescriptions = { "SF 18A Officer", "SF 18B Weapons Sgt", "SF 18C Engineer Sgt", "SF 18D Medical Sgt", "SF 18E Commo Sgt", "SF 18F Intel Sgt", "SF 18Z Team Sgt" };
	//Guerrilla(0) = Texture'T_AA2_UI.HUD.hud_icon_ind_74'
	//Guerrilla(1) = Texture'T_AA2_UI.HUD.hud_icon_ind_rpg'
	//Guerrilla(2) = Texture'T_AA2_UI.HUD.hud_icon_ind_vss'
	//Guerrilla(3) = Texture'T_AA2_UI.HUD.hud_icon_ind_rpk'
	//Guerrilla(4) = Texture'T_AA2_UI.HUD.hud_icon_ind_ak'
	//Guerrilla(5) = Texture'T_AA2_UI.HUD.hud_icon_ind_vip'
	GuerrillaDescriptions = { "Indigenous Forces AK-74", "Indigenous Forces RPG", "Indigenous Forces VSS", "Indigenous Forces RPK", "Indigenous Forces AK-47", "Indigenous Forces VIP" };
	//Group(0) = class'None'
	//Group(1) = Texture'T_AA2_UI.HUD.hud_icon_dev'
	//Group(2) = Texture'T_AA2_UI.HUD.hud_icon_dev_army'
	//Group(3) = class'None'
	//Group(4) = Texture'T_AA2_UI.HUD.hud_icon_beta'
	//Group(5) = Texture'T_AA2_UI.HUD.hud_icon_army_active'
	//Group(6) = class'None'
	//Group(7) = class'None'
	//Group(8) = class'None'
	//Group(9) = Texture'T_AA2_UI.HUD.hud_icon_navy'
	//Group(10) = Texture'T_AA2_UI.HUD.hud_icon_airforce'
	//Group(11) = Texture'T_AA2_UI.HUD.hud_icon_marine'
	//Group(12) = Texture'T_AA2_UI.HUD.hud_group_coastguard'
	//Group(13) = class'None'
	//Group(14) = class'None'
	//Group(15) = class'None'
	//Group(16) = class'None'
	//Group(17) = class'None'
	//Group(18) = class'None'
	//Group(19) = class'None'
	//Group(20) = class'None'
	//Group(21) = class'None'
	//Group(22) = Texture'T_AA2_UI.HUD.hud_icon_punkbuster'
	//Group(23) = Texture'T_AA2_UI.HUD.hud_group_aacm'
	//Group(24) = Texture'T_AA2_UI.HUD.hud_group_volunteer'
	GroupDescriptions = { "", "Dev Team", "Army Dev Team", "", "Beta Tester", "U.S. Army Active", "", "", "", "U.S. Navy", "U.S. Air Force", "U.S. Marine", "U.S. Coast Guard", "", "", "", "", "", "", "", "", "", "EvenBalance", "AACM", "Volunteers" };
	//Invalid = Texture'T_AAO_UI.HUD.hud_icon_pow';
	//tFT(0) = Texture'T_AA2_UI.HUD.hud_fireteam_a';
	//tFT(1) = Texture'T_AA2_UI.HUD.hud_fireteam_b';
	//tFT(2) = Texture'T_AA2_UI.HUD.hud_fireteam_c';
	//tFT(3) = Texture'T_AA2_UI.HUD.hud_fireteam_d';
	StyleName = "RosterUnitText";
}


void UAATeamList::SetTeam(ATeamInfo* TI)
{
	/*
	if (AGP_TeamInfo(TI) != None)
	{
		Team = AGP_TeamInfo(TI);
	}
	*/
}

void UAATeamList::GetGroupIcon(AAA2_PlayerState* PRI)
{
	/*
	if (PRI != None)
	{
		if (PRI.GetGroup() < Group.Length)
		{
			Return Group[PRI.GetGroup()];
		}
	}
	Return None;
	*/
}

void UAATeamList::GetSubClassIcon(AAA2_PlayerState* PRI)
{
	/*
	local TeamInfo ViewerTeam;
	ViewerTeam = Controller.ViewportOwner.Actor.PlayerReplicationInfo.Team;
	if (PRI != None && ViewerTeam == PRI.Team || ViewerTeam.TeamIndex == 255)
	{
		if (bScores)
		{
			if (PRI.bIsMedic)
			{
				Return SubClass[0];
			}
		}
		else
		{
			if (PRI.bWillBeMedic)
			{
				Return SubClass[0];
			}
		}
	}
	Return None;
	*/
}

UMaterialInstance* UAATeamList::GetRankIcon(AAGP_PlayerStart* PS)
{
	/*
	if (PS.bSquadLeader)
	{
		Return GetIcon(rank[2], PS);
	}
	else
	{
		if (PS.bFTLeader)
		{
			Return GetIcon(rank[3], PS);
		}
		else
		{
			Return GetIcon(rank[5], PS);
		}
	}
	*/
	return nullptr;     //FAKE  /ELiZ
}

UMaterialInstance* UAATeamList::GetSFIcon(AAGP_PlayerStart* PS)
{
	/*
	if (PS.bExtraSpecialForces)
	{
		if (PS.ExtraSpecialForcesLetter == "B")
		{
			Return GetIcon(ExtraSpecialForces[1], PS);
		}
		else
		{
			if (PS.ExtraSpecialForcesLetter == "C")
			{
				Return GetIcon(ExtraSpecialForces[2], PS);
			}
			else
			{
				if (PS.ExtraSpecialForcesLetter == "D")
				{
					Return GetIcon(ExtraSpecialForces[3], PS);
				}
				else
				{
					if (PS.ExtraSpecialForcesLetter == "E")
					{
						Return GetIcon(ExtraSpecialForces[4], PS);
					}
					else
					{
						if (PS.ExtraSpecialForcesLetter == "F")
						{
							Return GetIcon(ExtraSpecialForces[5], PS);
						}
						else
						{
							if (PS.ExtraSpecialForcesLetter == "Z")
							{
								Return GetIcon(ExtraSpecialForces[6], PS);
							}
							else
							{
								Return GetIcon(Invalid, PS);
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if (PS.bSpecialForces)
		{
			Switch(GetNativeWeapon(PS))
			{
					case 2:
						Return GetIcon(SpecialForces[1], PS);
					case 6:
						Return GetIcon(SpecialForces[1], PS);
					case 3:
						Return GetIcon(SpecialForces[2], PS);
					case 4:
						Return GetIcon(SpecialForces[0], PS);
					default:
						break;
			}
			if (PS.bGuerrilla && !PS.bIFVIP)
			{
				Switch(GetNativeWeapon(PS))
				{
					case 2:
						Return GetIcon(Guerrilla[0], PS);
					case 7:
						Return GetIcon(Guerrilla[1], PS);
					case 4:
						Return GetIcon(Guerrilla[2], PS);
					case 3:
						Return GetIcon(Guerrilla[3], PS);
					default:
						break;
				}
				if (PS.bIFVIP)
				{
					Return GetIcon(Class[4], PS);
					break;
				}
				Switch(GetNativeWeapon(PS))
				{
					case 2:
						Return GetIcon(Class[0], PS);
					case 6:
						Return GetIcon(Class[1], PS);
					case 3:
						Return GetIcon(Class[2], PS);
					case 4:
						Return GetIcon(Class[3], PS);
					default:
						Return GetIcon(Invalid, PS);
				}
			}
		}
	}
	*/
	return nullptr;     //FAKE  /ELiZ
}

void UAATeamList::GetNativeWeapon(AAGP_PlayerStart* PS)
{
	/*
	if (PS.GetSpawnClass() == None)
	{
		Return 1;
	}
	else
	{
		Return PS.GetSpawnClass().Default.nativeWeapon;
	}
	*/
}

UMaterialInstance* UAATeamList::GetClassIcon(AAGP_PlayerStart* PS)
{
	/*
	Switch(GetNativeWeapon(PS))
	{
		case 2:
			Return GetIcon(Class[0], PS);
		case 6:
			Return GetIcon(Class[1], PS);
		case 3:
			Return GetIcon(Class[2], PS);
		case 4:
			Return GetIcon(Class[3], PS);
		default:
			if (PS.GetSpawnClass() == Class'ClassVIP')
			{
				Return GetIcon(Class[4], PS);
				break;
			}
			Return GetIcon(Invalid, PS);
	}
	*/
	return nullptr;     //FAKE  /ELiZ
}

UMaterialInstance* UAATeamList::GetIcon(UMaterialInstance* M, AAGP_PlayerStart* PS)
{
	if (IsPSEnabled(PS))
	{
		return M;
	}
	else
	{
		return GetGray(M);
	}
}

UMaterialInstance* UAATeamList::MaybeGray(UMaterialInstance* M)
{
	if (IsEnabled())
	{
		return M;
	}
	else
	{
		return GetGray(M);
	}
}

UMaterialInstance* UAATeamList::GetGray(UMaterialInstance* M)
{
	UMaterialInstance* new_material=nullptr;
	/*
	local string new_name;
	
	new_name = M $ "_g";
	new_material = Material(DynamicLoadObject(new_name, Class'Material', True));
	if (new_material != None)
	{
		Return new_material;
	}
	else
	{
		Return M;
	}
	*/
	return nullptr;     //FAKE  /ELiZ
}

void UAATeamList::GetPlayerStart(AAA2_PlayerState* PlayerItem)
{
	//Return AGP_PlayerStart(PlayerItem.GetPlayerStart());
}

void UAATeamList::GetPlayerAtIndex(int32 aIndex)
{
	//Return None;
}

FString UAATeamList::GetPlayerName(AAA2_PlayerState* PRI)
{
	/*
	if (PRI != None)
	{
		Return PRI.GetHumanReadableName();
	}
	else
	{
		Return "";
	}
	*/
	return "FAKE";     //FAKE    /ELiZ
}

int32 UAATeamList::GetPlayerState(AAA2_PlayerState* PRI)
{
	/*
	if (PRI == PlayerOwner().PlayerReplicationInfo)
	{
		Return 2;
	}
	else
	{
		if (PRI != PlayerOwner().PlayerReplicationInfo && PRI.isDead())
		{
			if (PRI.Team != None && PlayerOwner().PlayerReplicationInfo.Team != None)
			{
				if (PRI.Team.TeamIndex == PlayerOwner().PlayerReplicationInfo.Team.TeamIndex)
				{
					Return 4;
				}
			}
			Return 1;
		}
		else
		{
			Return 1;
		}
	}
	*/
	return 0;      //FAKE   /ELiZ
}

bool UAATeamList::IsEnabled()
{
	return true;
}

bool UAATeamList::IsPSEnabled(AAGP_PlayerStart* PS)
{
	return true;
}

bool UAATeamList::IsQualified(AAGP_PlayerStart* PS, AAA2_PlayerState* PRI)
{
	/*
	if (PS.bSpecialForces)
	{
		if (!IsSFQualified(PRI))
		{
			Return False;
		}
	}
	if (PS.GetSpawnClass().Default.nativeWeapon == 4)
	{
		if (!IsSniperQualified(PRI))
		{
			Return False;
		}
	}
	*/
	return true;
}

bool UAATeamList::IsSFQualified(AAA2_PlayerState* PRI)
{
	/*
	if (PRI.bQualifiedSF)
	{
		Return True;
	}
	*/
	return false;
}

bool UAATeamList::IsSniperQualified(AAA2_PlayerState* PRI)
{
	/*
	if (PRI.bQualifiedSniper)
	{
		Return True;
	}
	*/
	return false;
}

bool UAATeamList::IsJavelinQualified(AAA2_PlayerState* PRI)
{
	/*
	if (PRI.bQualifiedJavelin)
	{
		Return True;
	}
	*/
	return false;
}

bool UAATeamList::IsAdmin(AAA2_PlayerState* PRI)
{
	/*
	if (PRI.bAdmin)
	{
		Return True;
	}
	*/
	return false;
}

int32 UAATeamList::GetGroup(int32 aIndex)
{
	/*
	local int i;
	local int TempCount;
	local int j;
	local bool bIsLastNonEmptyGroup;
	for (i = 0; i < Groups.Length; i++)
	{
		TempCount += Groups[i];
		if (Groups[i] != 0)
		{
			bIsLastNonEmptyGroup = True;
			for (j = i + 1; j < Groups.Length; j++)
			{
				if (Groups[j] != 0)
				{
					bIsLastNonEmptyGroup = False;
				}
			}
			if (!bIsLastNonEmptyGroup)
			{
				TempCount++;
			}
		}
		if (aIndex < TempCount)
		{
			Return i;
		}
	}
	*/
	return 0;
}

int32 UAATeamList::GetPositionInGroup(int32 aGroup, int32 aIndex)
{
	/*
	local int i;
	local int j;
	local int numSeparators;
	local int Size;
	local bool bIsLastNonEmptyGroup;
	for (i = 0; i < Groups.Length; i++)
	{
		if (i == aGroup)
		{
			for (j = 0; j < Groups[i]; j++)
			{
				if (aIndex == j + Size + numSeparators)
				{
					Return j;
				}
			}
		}
		Size += Groups[i];
		if (Groups[i] != 0)
		{
			bIsLastNonEmptyGroup = True;
			for (j = i + 1; j < Groups.Length; j++)
			{
				if (Groups[j] != 0)
				{
					bIsLastNonEmptyGroup = False;
				}
			}
			if (!bIsLastNonEmptyGroup)
			{
				numSeparators++;
			}
		}
	}
	*/
	return 0;
}