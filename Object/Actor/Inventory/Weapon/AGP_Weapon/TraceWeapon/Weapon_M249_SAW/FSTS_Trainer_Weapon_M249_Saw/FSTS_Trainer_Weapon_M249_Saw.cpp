// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/FSTS_Trainer_Weapon_M249_Saw/FSTS_Trainer_Weapon_M249_Saw.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_M249_SAW/PickupW_FSTS_Trainer_M249_SAW.h"

AFSTS_Trainer_Weapon_M249_Saw::AFSTS_Trainer_Weapon_M249_Saw()
{
	iMisFire     = 0;
	PickupClass  = APickupW_FSTS_Trainer_M249_SAW::StaticClass();
}

void AFSTS_Trainer_Weapon_M249_Saw::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
	GiveTo(Other, Pickup);
	_bActive = true;
	GotoState('Idle');
	*/
}

bool AFSTS_Trainer_Weapon_M249_Saw::AddClip(AAmmunition* AmmoClass)
{
	/*
	local int i;
	DebugLog(DEBUG_Inv, "AGP_Weapon::AddClip()	" $ AmmoClass @ AmmoName @ AuxAmmoName);
	if (AmmoClass == nullptr)
	{
		return false;
	}
	else
	{
		if (ClassIsChildOf(AmmoClass, AmmoName))
		{
			for (i = 0; i < 16; i++)
			{
				if (GetClipCount(i) <= 0)
				{
					SetClipCount(i, AmmoClass.Default.AmmoAmount);
					AmmoMagCount++;
					return true;
				}
			}
		}
		else
		{
			if (AmmoClass == AuxAmmoName)
			{
				for (i = 0; i < 16; i++)
				{
					if (GetClipCount(i, true) <= 0)
					{
						SetClipCount(i, AmmoClass.Default.AmmoAmount, true);
						AuxAmmoMagCount++;
						return true;
					}
				}
			}
			else
			{
				return false;
			}
		}
	}
	*/

	return false;    //FAKE   /ELiZ
}
