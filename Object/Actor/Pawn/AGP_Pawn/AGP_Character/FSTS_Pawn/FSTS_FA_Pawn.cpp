// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_FA_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Parachute/Item_Parachute.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FA_PlayerController/FA_PlayerController.h"

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
	if (Cast<AFA_PlayerController>(Controller).FAMasterScript.LockWeaponPosition())
	{
		return false;
	}
	if ((((IsBusy() || IsSupported()) || (Physics == 11)) || bIsDead) || ((Weapon != nullptr) && ((Weapon.IsBusy() && (!Weapon.IsTempBusy())) || Weapon->IsA(AItem_Parachute::StaticClass()))))
	{
		return false;
	}
	*/
	return true;
}
