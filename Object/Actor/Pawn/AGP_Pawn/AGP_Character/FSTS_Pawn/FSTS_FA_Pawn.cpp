// All the original content belonged to the US Army

#include "FSTS_FA_Pawn.h"

AFSTS_FA_Pawn::AFSTS_FA_Pawn()
{

}

void AFSTS_FA_Pawn::PlayMILESDeathTone()
{
	//PlaySound(Sound'S_AA2_WeaponFX.miles.WeaponFX_MILES_Death', 0, 1, , , , false);
}

bool AFSTS_FA_Pawn::CanSwapHands()
{
	/*
	if (FA_PlayerController(Controller).FAMasterScript.LockWeaponPosition())
	{
		return false;
	}
	if ((((IsBusy() || IsSupported()) || (Physics == 11)) || bIsDead) || ((Weapon != None) && ((Weapon.IsBusy() && (!Weapon.IsTempBusy())) || Weapon.IsA("Item_Parachute"))))
	{
		return false;
	}
	*/
	return true;
}
