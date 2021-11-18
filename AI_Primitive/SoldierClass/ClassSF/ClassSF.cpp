// All the original content belonged to the US Army


#include "ClassSF.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M14_Incendiary/Throw_M14_Incendiary.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
AClassSF::AClassSF()
{
	ClassEquipment = {
		AWeapon_M4A1_Rifle_Mod::StaticClass(),
		AThrow_M14_Incendiary::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};
	_ShortName = "SF";
}



void AClassSF::LoadWeapon()
{
	/*
	AAGP_Weapon W;
	FString WeaponName;
	int32 i;
	int32 num_ammo;
	
	WeaponName = HumanController(myPawn.Controller).WM_CurrentWeapon;
	W = AGP_Weapon(myPawn.CreateInventoryFromName(WeaponName));
	if (W == NULL)
	{
		W = AGP_Weapon(myPawn.CreateInventoryFromName(Default_CurrentWeapon));
	}

	switch(W->AmmoName.Default.MaxAmmo)
	{
			case 5:
				num_ammo = 9;
				break;
			case 7:
				num_ammo = 4;
				break;
			case 10:
				num_ammo = 4;
				break;
			case 20:
			case 30:
				num_ammo = 6;
				break;
			case 100:
			case 200:
				num_ammo = 3;
				break;
			default:
				num_ammo = 4;
				break;
	}
	for (i = 0; i < num_ammo; i++)
	{
		myPawn.CreateInventory(W.AmmoName);
	}
	if (W.AuxAmmoName != None)
	{
		num_ammo = 1;
		for (i = 0; i < num_ammo; i++)
		{
			myPawn.CreateInventory(W.AuxAmmoName);
		}
	}
	*/
}
void AClassSF::addClassInventory(bool bMaybeSkip)
{
	Super::addClassInventory(bMaybeSkip);
	LoadWeapon();
}
float AClassSF::WeaponEffectivenessBonus(AAGP_Weapon* W)
{
	return nativeBonus;
}