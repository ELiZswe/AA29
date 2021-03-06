// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod_AuxWeapon/WeaponMod_Flare_Gren/WeaponMod_Flare_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Flare_1_Gren/Ammo_Flare_1_Gren.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_Flare_Gren.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod_AuxWeapon/WeaponMod_BS1_Gren/WeaponMod_BS1_Gren.h"

AWeaponMod_Flare_Gren::AWeaponMod_Flare_Gren()
{
	NewWeaponMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m4a1_m203_1P.m4a1_m203_1P'"), NULL, LOAD_None, NULL);
	AuxWeaponMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m4a1_m203G_1P.m4a1_m203G_1P'"), NULL, LOAD_None, NULL);
	AuxAmmo					= AAmmo_Flare_1_Gren::StaticClass();
	AuxAmmoCount			= 1;
	AuxARound				= AAmmoRound_Flare_Gren::StaticClass();
	NumAuxRound				= 1;
	AuxSingleFire			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire_Cue.WeaponsUS_M203_Fire_Cue'"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire	= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire_Cue.WeaponsUS_M203_Fire_Cue'"), NULL, LOAD_None, NULL);
	AltReloadSound			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Reload_Cue.WeaponsUS_M203_Reload_Cue'"), NULL, LOAD_None, NULL);
	FillExtraSlot			= 1;
	ModImage				= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_203_black_Mat.mod_203_black_Mat'"), NULL, LOAD_None, NULL);
	ModImageOverlay			= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_m203_Mat.m4mod_m203_Mat'"), NULL, LOAD_None, NULL);
	ExclusiveModsList		= {
								AWeaponMod_Reflex::StaticClass()
							};
	//ValidSlot(4) = 1
	EnemyModClass			= AWeaponMod_BS1_Gren::StaticClass();
	modname					= "M583A1 Flare";
	DrawType				= EDrawType::DT_None;
}

bool AWeaponMod_Flare_Gren::ModNotAllowed()
{
	uint8 Team = 0;
	/*
	if (Cast<APawn>(GetOwner())->PlayerReplicationInfo.Team == nullptr)
	{
		return false;
	}
	Team = Cast<APawn>(GetOwner())->PlayerReplicationInfo.Team.TeamIndex;
	switch(Team)
	{
			case 0:
				return !Level.bTeam0AllowFlares;
			case 1:
				return !Level.bTeam1AllowFlares;
			default:
				return !Level.bTeam0AllowFlares || !Level.bTeam1AllowFlares;
	}
	*/
	return false;    //FAKE   /ELiZ
}
