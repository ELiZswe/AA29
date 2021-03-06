// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AATeamList.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassVIP/ClassVIP.h"

UAATeamList::UAATeamList()
{
	Icons = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_dev_Mat.hud_icon_dev_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_dev_army_Mat.hud_icon_dev_army_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_beta_Mat.hud_icon_beta_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_army_active_Mat.hud_icon_army_active_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_navy_Mat.hud_icon_navy_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_airforce_Mat.hud_icon_airforce_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_marine_Mat.hud_icon_marine_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_coastguard_Mat.hud_group_coastguard_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_punkbuster_Mat.hud_icon_punkbuster_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_aacm_Mat.hud_group_aacm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_volunteer_Mat.hud_group_volunteer_Mat'"), NULL, LOAD_None, NULL)
	};
	IconDescriptions = { "Dev Team Member", "Army Dev Team", "Beta Tester", "U.S. Army Active", "U.S. Navy", "U.S. Air Force", "U.S. Marine", "U.S. Coast Guard", "EvenBalance", "AACM", "Volunteers" };

	rank = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_msg_Mat.hud_icon_msg_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_sfc_Mat.hud_icon_sfc_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ssgt_Mat.hud_icon_ssgt_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_sgt_Mat.hud_icon_sgt_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_cpl_Mat.hud_icon_cpl_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_pvt_Mat.hud_icon_pvt_Mat'"), NULL, LOAD_None, NULL)
	};
	RankDescriptions = {"Master Sergeant", "Sergeant First Class", "Staff Sergeant", "Sergeant", "Corporal", "Private"};
	Class = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_r_Mat.hud_icon_r_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_g_Mat.hud_icon_g_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ar_Mat.hud_icon_ar_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_s_Mat.hud_icon_s_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_vip_Mat.hud_icon_vip_Mat'"), NULL, LOAD_None, NULL)
	};
	ClassDescriptions = { "Rifleman", "Grenadier", "Automatic Rifleman", "Advanced Marksman", "VIP" };
	SubClass = { LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_medic_Mat.hud_icon_medic_Mat'"), NULL, LOAD_None, NULL) };
	SubClassDescriptions = { "Medic" };
	SpecialForces = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_b_Mat.hud_icon_18_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_c_Mat.hud_icon_18_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_z_Mat.hud_icon_18_z_Mat'"), NULL, LOAD_None, NULL)
	};
	SpecialForcesDescriptions = { "SF Weapons Sgt (SPR)", "SF Engineer (SOPMOD M4 Carbine)", "SF Operations Sgt (M249 SAW)" };
	ExtraSpecialForces = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_a_Mat.hud_icon_18_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_b_Mat.hud_icon_18_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_c_Mat.hud_icon_18_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_d_Mat.hud_icon_18_d_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_e_Mat.hud_icon_18_e_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_f_Mat.hud_icon_18_f_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_z_Mat.hud_icon_18_z_Mat'"), NULL, LOAD_None, NULL)
	};
	ExtraSpecialForcesDescriptions = { "SF 18A Officer", "SF 18B Weapons Sgt", "SF 18C Engineer Sgt", "SF 18D Medical Sgt", "SF 18E Commo Sgt", "SF 18F Intel Sgt", "SF 18Z Team Sgt" };
	Guerrilla = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_74_Mat.hud_icon_ind_74_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_rpg_Mat.hud_icon_ind_rpg_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_vss_Mat.hud_icon_ind_vss_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_rpk_Mat.hud_icon_ind_rpk_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_ak_Mat.hud_icon_ind_ak_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_vip_Mat.hud_icon_ind_vip_Mat'"), NULL, LOAD_None, NULL)
	};
	GuerrillaDescriptions = { "Indigenous Forces AK-74", "Indigenous Forces RPG", "Indigenous Forces VSS", "Indigenous Forces RPK", "Indigenous Forces AK-47", "Indigenous Forces VIP" };
	Group = {
		nullptr,
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_dev_Mat.hud_icon_dev_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_dev_army_Mat.hud_icon_dev_army_Mat'"), NULL, LOAD_None, NULL),
		nullptr,
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_beta_Mat.hud_icon_beta_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_army_active_Mat.hud_icon_army_active_Mat'"), NULL, LOAD_None, NULL),
		nullptr,
		nullptr,
		nullptr,
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_navy_Mat.hud_icon_navy_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_airforce_Mat.hud_icon_airforce_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_marine_Mat.hud_icon_marine_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_coastguard_Mat.hud_group_coastguard_Mat'"), NULL, LOAD_None, NULL),
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_punkbuster_Mat.hud_icon_punkbuster_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_aacm_Mat.hud_group_aacm_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_volunteer_Mat.hud_group_volunteer_Mat'"), NULL, LOAD_None, NULL)
	};
	GroupDescriptions = { "", "Dev Team", "Army Dev Team", "", "Beta Tester", "U.S. Army Active", "", "", "", "U.S. Navy", "U.S. Air Force", "U.S. Marine", "U.S. Coast Guard", "", "", "", "", "", "", "", "", "", "EvenBalance", "AACM", "Volunteers" };
	Invalid = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/hud_icon_pow_Mat.hud_icon_pow_Mat'"), NULL, LOAD_None, NULL);
	tFT = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_a_Mat.hud_fireteam_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_b_Mat.hud_fireteam_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_c_Mat.hud_fireteam_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_d_Mat.hud_fireteam_d_Mat'"), NULL, LOAD_None, NULL)
	};
	StyleName = "RosterUnitText";
}

void UAATeamList::SetTeam(ATeamInfo* TI)
{
	/*
	if (Cast<AAGP_TeamInfo>(TI) != nullptr)
	{
		Team = Cast<AGP_TeamInfo>(TI);
	}
	*/
}

UMaterialInstance* UAATeamList::GetGroupIcon(AAA2_PlayerState* PRI)
{
	if (PRI != nullptr)
	{
		if (PRI->GetGroup() < Group.Num())
		{
			return Group[PRI->GetGroup()];
		}
	}
	return nullptr;
}

UMaterialInstance* UAATeamList::GetSubClassIcon(AAA2_PlayerState* PRI)
{
	ATeamInfo* ViewerTeam = nullptr;
	/*
	ViewerTeam = Controller.ViewportOwner.Actor.PlayerReplicationInfo.Team;
	if (PRI != nullptr && ViewerTeam == PRI.Team || ViewerTeam.TeamIndex == 255)
	{
		if (bScores)
		{
			if (PRI.bIsMedic)
			{
				return SubClass[0];
			}
		}
		else
		{
			if (PRI.bWillBeMedic)
			{
				return SubClass[0];
			}
		}
	}
	*/
	return nullptr;
}

UMaterialInstance* UAATeamList::GetRankIcon(AAGP_PlayerStart* PS)
{
	/*
	if (PS.bSquadLeader)
	{
		return GetIcon(rank[2], PS);
	}
	else
	{
		if (PS.bFTLeader)
		{
			return GetIcon(rank[3], PS);
		}
		else
		{
			return GetIcon(rank[5], PS);
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
			return GetIcon(ExtraSpecialForces[1], PS);
		}
		else
		{
			if (PS.ExtraSpecialForcesLetter == "C")
			{
				return GetIcon(ExtraSpecialForces[2], PS);
			}
			else
			{
				if (PS.ExtraSpecialForcesLetter == "D")
				{
					return GetIcon(ExtraSpecialForces[3], PS);
				}
				else
				{
					if (PS.ExtraSpecialForcesLetter == "E")
					{
						return GetIcon(ExtraSpecialForces[4], PS);
					}
					else
					{
						if (PS.ExtraSpecialForcesLetter == "F")
						{
							return GetIcon(ExtraSpecialForces[5], PS);
						}
						else
						{
							if (PS.ExtraSpecialForcesLetter == "Z")
							{
								return GetIcon(ExtraSpecialForces[6], PS);
							}
							else
							{
								return GetIcon(Invalid, PS);
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
			switch(GetNativeWeapon(PS))
			{
					case 2:
						return GetIcon(SpecialForces[1], PS);
					case 6:
						return GetIcon(SpecialForces[1], PS);
					case 3:
						return GetIcon(SpecialForces[2], PS);
					case 4:
						return GetIcon(SpecialForces[0], PS);
					default:
						break;
			}
			if (PS.bGuerrilla && !PS.bIFVIP)
			{
				switch(GetNativeWeapon(PS))
				{
					case 2:
						return GetIcon(Guerrilla[0], PS);
					case 7:
						return GetIcon(Guerrilla[1], PS);
					case 4:
						return GetIcon(Guerrilla[2], PS);
					case 3:
						return GetIcon(Guerrilla[3], PS);
					default:
						break;
				}
				if (PS.bIFVIP)
				{
					return GetIcon(Class[4], PS);
					break;
				}
				switch(GetNativeWeapon(PS))
				{
					case 2:
						return GetIcon(Class[0], PS);
					case 6:
						return GetIcon(Class[1], PS);
					case 3:
						return GetIcon(Class[2], PS);
					case 4:
						return GetIcon(Class[3], PS);
					default:
						return GetIcon(Invalid, PS);
				}
			}
		}
	}
	*/
	return nullptr;     //FAKE  /ELiZ
}

uint8 UAATeamList::GetNativeWeapon(AAGP_PlayerStart* PS)
{
	/*
	if (PS.GetSpawnClass() == nullptr)
	{
		return 1;
	}
	else
	{
		return PS.GetSpawnClass().Default.nativeWeapon;
	}
	*/
	return 0;    //FAKE  /ELiZ
}

UMaterialInstance* UAATeamList::GetClassIcon(AAGP_PlayerStart* PS)
{
	/*
	switch(GetNativeWeapon(PS))
	{
		case 2:
			return GetIcon(Class[0], PS);
		case 6:
			return GetIcon(Class[1], PS);
		case 3:
			return GetIcon(Class[2], PS);
		case 4:
			return GetIcon(Class[3], PS);
		default:
			if (PS.GetSpawnClass() == AClassVIP::StaticClass())
			{
				return GetIcon(Class[4], PS);
				break;
			}
			return GetIcon(Invalid, PS);
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
	FString new_name;
	
	new_name = M + "_g";
	new_material = Cast<UMaterialInstance>(DynamicLoadObject(new_name, Class'Material', True));
	if (new_material != nullptr)
	{
		return new_material;
	}
	else
	{
		return M;
	}
	*/
	return nullptr;     //FAKE  /ELiZ
}

AAGP_PlayerStart* UAATeamList::GetPlayerStart(AAA2_PlayerState* PlayerItem)
{
	return Cast<AAGP_PlayerStart>(PlayerItem->GetPlayerStart());
}

AAA2_PlayerState* UAATeamList::GetPlayerAtIndex(int32 aIndex)
{
	return nullptr;
}

FString UAATeamList::GetPlayerName(AAA2_PlayerState* PRI)
{
	/*
	if (PRI != nullptr)
	{
		return PRI.GetHumanReadableName();
	}
	else
	{
		return "";
	}
	*/
	return "FAKE";     //FAKE    /ELiZ
}

uint8 UAATeamList::GetPlayerState(AAA2_PlayerState* PRI)
{
	/*
	if (PRI == PlayerOwner().PlayerReplicationInfo)
	{
		return 2;
	}
	else
	{
		if (PRI != PlayerOwner().PlayerReplicationInfo && PRI.isDead())
		{
			if (PRI.Team != nullptr && PlayerOwner().PlayerReplicationInfo.Team != nullptr)
			{
				if (PRI.Team.TeamIndex == PlayerOwner().PlayerReplicationInfo.Team.TeamIndex)
				{
					return 4;
				}
			}
			return 1;
		}
		else
		{
			return 1;
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
	if (PS->bSpecialForces)
	{
		if (!IsSFQualified(PRI))
		{
			return false;
		}
	}
	/*
	if (PS->GetSpawnClass().Default.nativeWeapon == 4)
	{
		if (!IsSniperQualified(PRI))
		{
			return false;
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
		return true;
	}
	*/
	return false;
}

bool UAATeamList::IsSniperQualified(AAA2_PlayerState* PRI)
{
	/*
	if (PRI.bQualifiedSniper)
	{
		return true;
	}
	*/
	return false;
}

bool UAATeamList::IsJavelinQualified(AAA2_PlayerState* PRI)
{
	/*
	if (PRI.bQualifiedJavelin)
	{
		return true;
	}
	*/
	return false;
}

bool UAATeamList::IsAdmin(AAA2_PlayerState* PRI)
{
	/*
	if (PRI.bAdmin)
	{
		return true;
	}
	*/
	return false;
}

int32 UAATeamList::GetGroup(int32 aIndex)
{
	int32 i = 0;
	int32 TempCount = 0;
	int32 j = 0;
	bool bIsLastNonEmptyGroup = false;
	/*
	for (i = 0; i < Groups.Num(); i++)
	{
		TempCount += Groups[i];
		if (Groups[i] != 0)
		{
			bIsLastNonEmptyGroup = true;
			for (j = i + 1; j < Groups.Num(); j++)
			{
				if (Groups[j] != 0)
				{
					bIsLastNonEmptyGroup = false;
				}
			}
			if (!bIsLastNonEmptyGroup)
			{
				TempCount++;
			}
		}
		if (aIndex < TempCount)
		{
			return i;
		}
	}
	*/
	return 0;
}

int32 UAATeamList::GetPositionInGroup(int32 aGroup, int32 aIndex)
{
	int32 i = 0;
	int32 j = 0;
	int32 numSeparators = 0;
	int32 Size = 0;
	bool bIsLastNonEmptyGroup = false;
	/*
	for (i = 0; i < Groups.Num(); i++)
	{
		if (i == aGroup)
		{
			for (j = 0; j < Groups[i]; j++)
			{
				if (aIndex == j + Size + numSeparators)
				{
					return j;
				}
			}
		}
		Size += Groups[i];
		if (Groups[i] != 0)
		{
			bIsLastNonEmptyGroup = true;
			for (j = i + 1; j < Groups.Num(); j++)
			{
				if (Groups[j] != 0)
				{
					bIsLastNonEmptyGroup = false;
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
