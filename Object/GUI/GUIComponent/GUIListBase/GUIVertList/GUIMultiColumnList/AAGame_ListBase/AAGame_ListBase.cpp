// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAGame_ListBase.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassVIP/ClassVIP.h"

UAAGame_ListBase::UAAGame_ListBase()
{
	rank = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_msg_Mat.hud_icon_msg_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_sfc_Mat.hud_icon_sfc_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ssgt_Mat.hud_icon_ssgt_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_sgt_Mat.hud_icon_sgt_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_cpl_Mat.hud_icon_cpl_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_pvt_Mat.hud_icon_pvt_Mat'"), NULL, LOAD_None, NULL)
	};
	RankDescriptions = { "Master Sergeant", "Sergeant First Class", "Staff Sergeant", "Sergeant", "Corporal", "Private" };
	Class = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_r_Mat.hud_icon_r_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_g_Mat.hud_icon_g_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ar_Mat.hud_icon_ar_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_s_Mat.hud_icon_s_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_vip_Mat.hud_icon_vip_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_at4a_Mat.hud_icon_at4a_Mat'"), NULL, LOAD_None, NULL)
	};
	ClassDescriptions = { "Rifleman", "Grenadier", "Automatic Rifleman", "Advanced Marksman", "VIP", "AT4 Soldier" };
	SubClass = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_medic_Mat.hud_icon_medic_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_e_Mat.hud_icon_e_Mat'"), NULL, LOAD_None, NULL)
	};
	SubClassDescriptions = { "Medic", "Engineer" };
	SpecialForces = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_odac_Mat.hud_icon_odac_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_a_Mat.hud_icon_18_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_b_Mat.hud_icon_18_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_c_Mat.hud_icon_18_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_d_Mat.hud_icon_18_d_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_e_Mat.hud_icon_18_e_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_f_Mat.hud_icon_18_f_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_18_z_Mat.hud_icon_18_z_Mat'"), NULL, LOAD_None, NULL)
	};
	SpecialForcesDescriptions = { "Captain", "Special Forces A", "Special Forces B", "Special Forces C", "Special Forces D", "Special Forces E", "Special Forces F", "Special Forces Z" };
	Guerrilla = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_74_Mat.hud_icon_ind_74_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_rpg_Mat.hud_icon_ind_rpg_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_vss_Mat.hud_icon_ind_vss_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_rpk_Mat.hud_icon_ind_rpk_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_ak_Mat.hud_icon_ind_ak_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_svd_Mat.hud_icon_ind_svd_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_ind_vip_Mat.hud_icon_ind_vip_Mat'"), NULL, LOAD_None, NULL)
	};
	GuerrillaDescriptions = { "Indigenous Forces AK-74", "Indigenous Forces RPG", "Indigenous Forces VSS", "Indigenous Forces RPK", "Indigenous Forces AK-47", "Indigenous Forces SVD", "Indigenous Forces VIP" };
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
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_icon_punkbuster_Mat.hud_icon_punkbuster_Mat'"), NULL, LOAD_None, NULL)
	};
	GroupDescriptions = { "", "Dev Team", "Army Dev Team", "HomeLan", "Beta Tester", "U.S. Army Active", "", "", "", "U.S. Navy", "U.S. Air Force", "U.S. Marine", "", "", "", "", "", "", "", "", "", "", "EvenBalance" };
	Invalid = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/hud_icon_pow_Mat.hud_icon_pow_Mat'"), NULL, LOAD_None, NULL);
	SortColumn = -1;
	bVisibleWhenEmpty = true;
	StyleName = "UnitBox";
}

bool UAAGame_ListBase::IsEnabled()
{
	return true;
}

UMaterialInstance* UAAGame_ListBase::MaybeGray(UMaterialInstance* M)
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

UMaterialInstance* UAAGame_ListBase::GetGray(UMaterialInstance* M)
{
	FString new_name = "";
	UMaterialInstance* new_material = nullptr;
	/*
	new_name = FString::FromInt(M) + "_g";
	new_material = Cast<UMaterialInstance>(DynamicLoadObject(new_name, Class'Material', true));
	*/
	if (new_material != nullptr)
	{
		return new_material;
	}
	else
	{
		return M;
	}

}

uint8 UAAGame_ListBase::GetNativeWeapon(AAGP_PlayerStart* PS)
{
	if (PS->GetSpawnClass() == nullptr)
	{
		return 1;
	}
	else
	{
		//return PS->GetSpawnClass().Default.nativeWeapon;
	}
	return 0;   //FAKE   /ELiZ
}

UMaterialInstance* UAAGame_ListBase::GetGroupIcon(AAA2_PlayerState* PRI)
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

UMaterialInstance* UAAGame_ListBase::GetSubClassIcon(AAA2_PlayerState* PRI)
{
	if (PRI != nullptr)
	{
		if (PRI->bWillBeMedic)
		{
			return SubClass[0];
		}
	}
	return nullptr;
}

UMaterialInstance* UAAGame_ListBase::GetRankIcon(AAGP_PlayerStart* PS)
{
	if (PS->bSquadLeader)
	{
		return MaybeGray(rank[2]);
	}
	else
	{
		if (PS->bFTLeader)
		{
			return MaybeGray(rank[3]);
		}
		else
		{
			return MaybeGray(rank[5]);
		}
	}
	return nullptr;			//FAKE   /EliZ
}

UMaterialInstance* UAAGame_ListBase::GetSFIcon(AAGP_PlayerStart* PS)
{
	if (PS->bExtraSpecialForces)
	{
		if (PS->ExtraSpecialForcesLetter == "B")
		{
			return MaybeGray(SpecialForces[2]);
		}
		else
		{
			if (PS->ExtraSpecialForcesLetter == "C")
			{
				return MaybeGray(SpecialForces[3]);
			}
			else
			{
				if (PS->ExtraSpecialForcesLetter == "D")
				{
					return MaybeGray(SpecialForces[4]);
				}
				else
				{
					if (PS->ExtraSpecialForcesLetter == "E")
					{
						return MaybeGray(SpecialForces[5]);
					}
					else
					{
						if (PS->ExtraSpecialForcesLetter == "F")
						{
							return MaybeGray(SpecialForces[6]);
						}
						else
						{
							if (PS->ExtraSpecialForcesLetter == "Z")
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
		if (PS->bSpecialForces)
		{
			switch(GetNativeWeapon(PS))
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
			if (PS->bGuerrilla && !PS->bIFVIP)
			{
				switch(GetNativeWeapon(PS))
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
				if (PS->bIFVIP)
				{
					return MaybeGray(Class[4]);
				}
				return MaybeGray(Invalid);
			}
		}
	}
	return nullptr;			//FAKE   /EliZ
}

UMaterialInstance* UAAGame_ListBase::GetClassIcon(AAGP_PlayerStart* PS)
{
	switch(GetNativeWeapon(PS))
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
			/*
			if (PS->GetSpawnClass() == AClassVIP::StaticClass())
			{
				return MaybeGray(Class[4]);
				break;
			}
			*/
			return MaybeGray(Invalid);
			break;
	}
	return nullptr;			//FAKE   /EliZ
}

FString UAAGame_ListBase::GetPlayerName(AAA2_PlayerState* PRI)
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
	return "FAKE";    //FAKE   /ELiZ
}

uint8 UAAGame_ListBase::GetPlayerState(AAA2_PlayerState* PRI)
{
	/*
	if (PRI == PlayerOwner()->PlayerReplicationInfo)
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
