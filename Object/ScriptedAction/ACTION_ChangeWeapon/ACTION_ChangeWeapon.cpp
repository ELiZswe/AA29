// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ChangeWeapon/ACTION_ChangeWeapon.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

UACTION_ChangeWeapon::UACTION_ChangeWeapon()
{

}

bool UACTION_ChangeWeapon::InitActionFor(AScriptedController* C)
{
	/*
	C.Pawn.PendingWeapon = Weapon(C.Pawn.FindInventoryType(newWeapon));
	C.Pawn.ChangedWeapon();
	*/
	return false;
}
