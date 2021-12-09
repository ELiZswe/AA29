// All the original content belonged to the US Army

#include "WeaponMod_Flare_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Flare_1_Gren/Ammo_Flare_1_Gren.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_Flare_Gren.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod_AuxWeapon/WeaponMod_BS1_Gren/WeaponMod_BS1_Gren.h"

AWeaponMod_Flare_Gren::AWeaponMod_Flare_Gren()
{
	NewWeaponMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m4a1_m203_1P.m4a1_m203_1P"), NULL, LOAD_None, NULL);
	AuxWeaponMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m4a1_m203G_1P.m4a1_m203G_1P"), NULL, LOAD_None, NULL);
	AuxAmmo					= AAmmo_Flare_1_Gren::StaticClass();
	AuxAmmoCount			= 1;
	AuxARound				= AAmmoRound_Flare_Gren::StaticClass();
	NumAuxRound				= 1;
	AuxSingleFire			= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire.WeaponsUS_M203_Fire"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire	= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire.WeaponsUS_M203_Fire"), NULL, LOAD_None, NULL);
	AltReloadSound			= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Reload.WeaponsUS_M203_Reload"), NULL, LOAD_None, NULL);
	FillExtraSlot			= 1;
	ModImage				= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_203_black.mod_203_black"), NULL, LOAD_None, NULL);
	ModImageOverlay			= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_m203.m4mod_m203"), NULL, LOAD_None, NULL);
	ExclusiveModsList		= {
								AWeaponMod_Reflex::StaticClass()
							};
	//ValidSlot(4) = 1
	EnemyModClass			= AWeaponMod_BS1_Gren::StaticClass();
	modname					= "M583A1 Flare";
	DrawType				= EDrawType::DT_None;
}

void AWeaponMod_Flare_Gren::ModNotAllowed()
{
	/*
	uint8 Team;
	if (Pawn(Owner).PlayerReplicationInfo.Team == None)
	{
		Return False;
	}
	Team = Pawn(Owner).PlayerReplicationInfo.Team.TeamIndex;
	Switch(Team)
	{
			case 0:
				Return !Level.bTeam0AllowFlares;
			case 1:
				Return !Level.bTeam1AllowFlares;
			default:
				Return !Level.bTeam0AllowFlares || !Level.bTeam1AllowFlares;
	}
	*/
}