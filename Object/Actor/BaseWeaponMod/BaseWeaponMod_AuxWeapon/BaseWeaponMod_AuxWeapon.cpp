// All the original content belonged to the US Army

#include "BaseWeaponMod_AuxWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
ABaseWeaponMod_AuxWeapon::ABaseWeaponMod_AuxWeapon()
{

}

bool ABaseWeaponMod_AuxWeapon::MutuallyExclusive(ABaseWeaponMod* OtherMod)
{
	/*
	if (OtherMod.IsA('BaseWeaponMod_AuxWeapon'))
	{
		return true;
	}
	return MutuallyExclusive(OtherMod);
	*/
	return false;   //FAKE   /ELiZ
}

void ABaseWeaponMod_AuxWeapon::ModifyWeapon()
{
	ModifyWeapon();
	SetupAuxWeapon();
}

void ABaseWeaponMod_AuxWeapon::SetupAuxWeapon()
{
	/*
	Cast<AAGP_Weapon>(weap)->SetupAuxWeaponMesh(NewWeaponMesh, AuxWeaponMesh);
	Cast<AAGP_Weapon>(weap)->SetupAuxAmmo(AuxAmmo, AuxAmmoCount);
	Cast<AAGP_Weapon>(weap)->SetupAuxAmmoRound(AuxARound, NumAuxRound);
	Cast<AAGP_Weapon>(weap)->SetupAuxMuzzleFlash(AuxMuzzleFlash, AuxMuzzleFlashOffset);
	Cast<AAGP_Weapon>(weap)->SetupAuxSounds(AuxSingleFire, AuxOutdoorSingleFire, AltReloadSound);
	*/
}
