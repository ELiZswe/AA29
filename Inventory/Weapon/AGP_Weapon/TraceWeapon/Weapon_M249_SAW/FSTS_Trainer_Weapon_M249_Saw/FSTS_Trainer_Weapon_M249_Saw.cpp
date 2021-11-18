// All the original content belonged to the US Army


#include "FSTS_Trainer_Weapon_M249_Saw.h"
#include "AA29/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_M249_SAW/PickupW_FSTS_Trainer_M249_SAW.h"

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
void AFSTS_Trainer_Weapon_M249_Saw::AddClip(AAmmunition* AmmoClass)
{
	/*
	local int i;
	DebugLog(DEBUG_Inv, "AGP_Weapon::AddClip()	" $ AmmoClass @ AmmoName @ AuxAmmoName);
	if (AmmoClass == None)
	{
		Return False;
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
					Return True;
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
						Return True;
					}
				}
			}
			else
			{
				Return False;
			}
		}
	}
	*/
}
