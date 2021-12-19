// All the original content belonged to the US Army

#include "WeaponMod_M203_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_40mm_1_Gren_Mod/Ammo_40mm_1_Gren_Mod.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_40mm_Gren.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod_AuxWeapon/WeaponMod_BS1_Gren/WeaponMod_BS1_Gren.h"

AWeaponMod_M203_Gren::AWeaponMod_M203_Gren()
{
	NewWeaponMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m4a1_m203_1P.m4a1_m203_1P"), NULL, LOAD_None, NULL);
	AuxWeaponMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m4a1_m203G_1P.m4a1_m203G_1P"), NULL, LOAD_None, NULL);
	AuxAmmo					= AAmmo_40mm_1_Gren_Mod::StaticClass();
	AuxAmmoCount			= 1;
	AuxARound				= AAmmoRound_40mm_Gren::StaticClass();
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
	modname					= "M203A1 Grenade";
	DrawType				= EDrawType::DT_None;
}

bool AWeaponMod_M203_Gren::ModNotAllowed()
{
	uint8 Team = 0;
	/*
	if (Pawn(Owner).PlayerReplicationInfo.Team == nullptr)
	{
		return false;
	}
	Team=Pawn(Owner).PlayerReplicationInfo.Team.TeamIndex;
	if (Level.Game.GameReplicationInfo.Disable203Grenades())
	{
		Log("WeaponMod_M203_Gren.ModNotAllowed - disabling 203 for TM");
		return true;
	}
	*/

	switch(Team)
	{
		case 0:
			return ! Cast<AAA2_WorldSettings>(GetWorldSettings())->bTeam0AllowM203Mod;
		case 1:
			return ! Cast<AAA2_WorldSettings>(GetWorldSettings())->bTeam1AllowM203Mod;
		default:
			return ! Cast<AAA2_WorldSettings>(GetWorldSettings())->bTeam0AllowM203Mod || ! Cast<AAA2_WorldSettings>(GetWorldSettings())->bTeam1AllowM203Mod;
	}
	return false;    //FAKE   /ELiZ
}
