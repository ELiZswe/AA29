// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ChangeWeapon/ACTION_ChangeWeapon.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

UACTION_ChangeWeapon::UACTION_ChangeWeapon()
{

}

bool UACTION_ChangeWeapon::InitActionFor(AScriptedController* C)
{
	Cast<AAGP_Pawn>(C->GetPawn())->PendingWeapon = Cast<AWeapon>(Cast<AAGP_Pawn>(C->GetPawn())->FindInventoryType(newWeapon));
	Cast<AAGP_Pawn>(C->GetPawn())->ChangedWeapon();
	return false;
}
