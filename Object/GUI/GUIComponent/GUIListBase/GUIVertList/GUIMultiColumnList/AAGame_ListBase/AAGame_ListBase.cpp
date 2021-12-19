// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAGame_ListBase.h"

UAAGame_ListBase::UAAGame_ListBase()
{
	//rank[0] = Texture'T_AA2_UI.HUD.hud_icon_msg';
	//rank[1] = Texture'T_AA2_UI.HUD.hud_icon_sfc';
	//rank[2] = Texture'T_AA2_UI.HUD.hud_icon_ssgt';
	//rank[3] = Texture'T_AA2_UI.HUD.hud_icon_sgt';
	//rank[4] = Texture'T_AA2_UI.HUD.hud_icon_cpl';
	//rank[5] = Texture'T_AA2_UI.HUD.hud_icon_pvt';
	
	RankDescriptions = {"Master Sergeant", "Sergeant First Class", "Staff Sergeant", "Sergeant", "Corporal", "Private"};
	//Class[0] = Texture'T_AA2_UI.HUD.hud_icon_r';
	//Class[1] = Texture'T_AA2_UI.HUD.hud_icon_g';
	//Class[2] = Texture'T_AA2_UI.HUD.hud_icon_ar';
	//Class[3] = Texture'T_AA2_UI.HUD.hud_icon_s';
	//Class[4] = Texture'T_AA2_UI.HUD.hud_icon_vip';
	//Class[5] = Texture'T_AA2_UI.HUD.hud_icon_at4a';
	
	ClassDescriptions = {"Rifleman", "Grenadier", "Automatic Rifleman", "Advanced Marksman", "VIP", "AT4 Soldier"};
	//SubClass[0] = Texture'T_AA2_UI.HUD.hud_icon_medic';
	//SubClass[1] = Texture'T_AA2_UI.HUD.hud_icon_e';

	SubClassDescriptions = {"Medic", "Engineer"};
	//SpecialForces[0] = Texture'T_AA2_UI.HUD.hud_icon_odac';
	//SpecialForces[1] = Texture'T_AA2_UI.HUD.hud_icon_18_a';
	//SpecialForces[2] = Texture'T_AA2_UI.HUD.hud_icon_18_b';
	//SpecialForces[3] = Texture'T_AA2_UI.HUD.hud_icon_18_c';
	//SpecialForces[4] = Texture'T_AA2_UI.HUD.hud_icon_18_d';
	//SpecialForces[5] = Texture'T_AA2_UI.HUD.hud_icon_18_e';
	//SpecialForces[6] = Texture'T_AA2_UI.HUD.hud_icon_18_f';
	//SpecialForces[7] = Texture'T_AA2_UI.HUD.hud_icon_18_z';
	
	SpecialForcesDescriptions = {"Captain", "Special Forces A", "Special Forces B", "Special Forces C", "Special Forces D", "Special Forces E", "Special Forces F", "Special Forces Z"};
	//Guerrilla[0] = Texture'T_AA2_UI.HUD.hud_icon_ind_74';
	//Guerrilla[1] = Texture'T_AA2_UI.HUD.hud_icon_ind_rpg';
	//Guerrilla[2] = Texture'T_AA2_UI.HUD.hud_icon_ind_vss';
	//Guerrilla[3] = Texture'T_AA2_UI.HUD.hud_icon_ind_rpk';
	//Guerrilla[4] = Texture'T_AA2_UI.HUD.hud_icon_ind_ak';
	//Guerrilla[5] = Texture'T_AA2_UI.HUD.hud_icon_ind_svd';
	//Guerrilla[6] = Texture'T_AA2_UI.HUD.hud_icon_ind_vip';
	
	GuerrillaDescriptions = {"Indigenous Forces AK-74", "Indigenous Forces RPG", "Indigenous Forces VSS", "Indigenous Forces RPK", "Indigenous Forces AK-47", "Indigenous Forces SVD", "Indigenous Forces VIP"};
	//Group[0] = class'None';
	//Group[1] = Texture'T_AA2_UI.HUD.hud_icon_dev';
	//Group[2] = Texture'T_AA2_UI.HUD.hud_icon_dev_army';
	//Group[3] = class'None';
	//Group[4] = Texture'T_AA2_UI.HUD.hud_icon_beta';
	//Group[5] = Texture'T_AA2_UI.HUD.hud_icon_army_active';
	//Group[6] = class'None';
	//Group[7] = class'None';
	//Group[8] = class'None';
	//Group[9] = Texture'T_AA2_UI.HUD.hud_icon_navy';
	//Group[10] = Texture'T_AA2_UI.HUD.hud_icon_airforce';
	//Group[11] = Texture'T_AA2_UI.HUD.hud_icon_marine';
	//Group[12] = class'None';
	//Group[13] = class'None';
	//Group[14] = class'None';
	//Group[15] = class'None';
	//Group[16] = class'None';
	//Group[17] = class'None';
	//Group[18] = class'None';
	//Group[19] = class'None';
	//Group[20] = class'None';
	//Group[21] = class'None';
	//Group[22] = Texture'T_AA2_UI.HUD.hud_icon_punkbuster';
	
	GroupDescriptions = {"", "Dev Team", "Army Dev Team", "HomeLan", "Beta Tester", "U.S. Army Active", "", "", "", "U.S. Navy", "U.S. Air Force", "U.S. Marine", "", "", "", "", "", "", "", "", "", "", "EvenBalance"};
	//Invalid = Texture'T_AAO_UI.HUD.hud_icon_pow';
	SortColumn = -1;
	bVisibleWhenEmpty = true;
	StyleName = "UnitBox";

}

bool UAAGame_ListBase::IsEnabled()
{
	return true;
}

void UAAGame_ListBase::MaybeGray(UMaterialInstance* M)
{
	/*
	if (IsEnabled())
	{
		return M;
	}
	else
	{
		return GetGray(M);
	}
	*/
}

void UAAGame_ListBase::GetGray(UMaterialInstance* M)
{
	/*
	local string new_name;
	local Material new_material;
	new_name = M $ "_g";
	new_material = Material(DynamicLoadObject(new_name, Class'Material', True));
	if (new_material != None)
	{
		return new_material;
	}
	else
	{
		return M;
	}
	*/
}

void UAAGame_ListBase::GetNativeWeapon(AAGP_PlayerStart* PS)
{
	/*
	if (PS.GetSpawnClass() == None)
	{
		return 1;
	}
	else
	{
		return PS.GetSpawnClass().Default.nativeWeapon;
	}
	*/
}

void UAAGame_ListBase::GetGroupIcon(AAA2_PlayerState* PRI)
{
	/*
	if (PRI != None)
	{
		if (PRI.GetGroup() < Group.Length)
		{
			return Group[PRI.GetGroup()];
		}
	}
	return None;
	*/
}

void UAAGame_ListBase::GetSubClassIcon(AAA2_PlayerState* PRI)
{
	/*
	if (PRI != None)
	{
		if (PRI.bWillBeMedic)
		{
			return SubClass[0];
		}
	}
	return None;
	*/
}

void UAAGame_ListBase::GetRankIcon(AAGP_PlayerStart* PS)
{
	/*
	if (PS.bSquadLeader)
	{
		return MaybeGray(rank[2]);
	}
	else
	{
		if (PS.bFTLeader)
		{
			return MaybeGray(rank[3]);
		}
		else
		{
			return MaybeGray(rank[5]);
		}
	}
	*/
}

void UAAGame_ListBase::GetSFIcon(AAGP_PlayerStart* PS)
{
	/*
	if (PS.bExtraSpecialForces)
	{
		if (PS.ExtraSpecialForcesLetter == "B")
		{
			return MaybeGray(SpecialForces[2]);
		}
		else
		{
			if (PS.ExtraSpecialForcesLetter == "C")
			{
				return MaybeGray(SpecialForces[3]);
			}
			else
			{
				if (PS.ExtraSpecialForcesLetter == "D")
				{
					return MaybeGray(SpecialForces[4]);
				}
				else
				{
					if (PS.ExtraSpecialForcesLetter == "E")
					{
						return MaybeGray(SpecialForces[5]);
					}
					else
					{
						if (PS.ExtraSpecialForcesLetter == "F")
						{
							return MaybeGray(SpecialForces[6]);
						}
						else
						{
							if (PS.ExtraSpecialForcesLetter == "Z")
							{
								return MaybeGray(SpecialForces[7]);
							}
							else
							{
								return MaybeGray(Invalid);
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
						return MaybeGray(SpecialForces[3]);
					case 6:
						return MaybeGray(SpecialForces[3]);
					case 3:
						return MaybeGray(SpecialForces[7]);
					case 4:
						return MaybeGray(SpecialForces[2]);
					default:
						break;
			}
			if (PS.bGuerrilla && !PS.bIFVIP)
			{
				Switch(GetNativeWeapon(PS))
				{
					case 2:
						return MaybeGray(Guerrilla[0]);
					case 7:
						return MaybeGray(Guerrilla[1]);
					case 4:
						return MaybeGray(Guerrilla[2]);
					case 3:
						return MaybeGray(Guerrilla[3]);
					default:
						break;
				}
				if (PS.bIFVIP)
				{
					return MaybeGray(Class[4]);
					break;
				}
				return MaybeGray(Invalid);
			}
		}
	}
	*/
}

void UAAGame_ListBase::GetClassIcon(AAGP_PlayerStart* PS)
{
	/*
	Switch(GetNativeWeapon(PS))
	{
			case 2:
				return MaybeGray(Class[0]);
			case 6:
				return MaybeGray(Class[1]);
			case 3:
				return MaybeGray(Class[2]);
			case 4:
				return MaybeGray(Class[3]);
			case 7:
				return MaybeGray(Class[5]);
			default:
				if (PS.GetSpawnClass() == Class'ClassVIP')
				{
					return MaybeGray(Class[4]);
					break;
				}
				return MaybeGray(Invalid);
	}
	*/
}

FString UAAGame_ListBase::GetPlayerName(AAA2_PlayerState* PRI)
{
	/*
	if (PRI != None)
	{
		return PRI.GetHumanReadableName();
	}
	else
	{
		return "";
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

int32 UAAGame_ListBase::GetPlayerState(AAA2_PlayerState* PRI)
{
	/*
	if (PRI == PlayerOwner().PlayerReplicationInfo)
	{
		return 2;
	}
	else
	{
		return 1;
	}
	*/
	return -1;     //FAKE    /ELIZ
}
