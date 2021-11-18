// All the original content belonged to the US Army


#include "WeaponMod_BS1_Gren.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_BS1_30mm_1_Gren/Ammo_BS1_30mm_1_Gren.h"
#include "AA29/BaseAmmoRound/AmmoRound_BS1_30mm_Gren.h"
#include "AA29/BaseWeaponMod/WeaponMod_Kobra_Reflex/WeaponMod_Kobra_Reflex.h"
#include "AA29/BaseWeaponMod/BaseWeaponMod_AuxWeapon/WeaponMod_M203_Gren/WeaponMod_M203_Gren.h"

AWeaponMod_BS1_Gren::AWeaponMod_BS1_Gren()
{
	NewWeaponMesh			= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/aks74u_bs1_1P.aks74u_bs1_1P"), NULL, LOAD_None, NULL);
	AuxWeaponMesh			= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/aks74u_bs1G_1P.aks74u_bs1G_1P"), NULL, LOAD_None, NULL);
	AuxAmmo					= AAmmo_BS1_30mm_1_Gren::StaticClass();
	AuxAmmoCount			= 1;
	AuxARound				= AAmmoRound_BS1_30mm_Gren::StaticClass();
	NumAuxRound				= 1;
	AuxSingleFire			= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/BS1/WeaponsOPFOR_BS1_Fire.WeaponsOPFOR_BS1_Fire"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire	= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/BS1/WeaponsOPFOR_BS1_Fire.WeaponsOPFOR_BS1_Fire"), NULL, LOAD_None, NULL);
	AltReloadSound			= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/BS1/WeaponsOPFOR_BS1_Reload.WeaponsOPFOR_BS1_Reload"), NULL, LOAD_None, NULL);
	FillExtraSlot			= 1;
	ExclusiveModsList		= {
									AWeaponMod_Kobra_Reflex::StaticClass()
							};
	//ValidSlot(4) = 1;
	EnemyModClass         = AWeaponMod_M203_Gren::StaticClass();
	DrawType              = EDrawType::DT_None;
}