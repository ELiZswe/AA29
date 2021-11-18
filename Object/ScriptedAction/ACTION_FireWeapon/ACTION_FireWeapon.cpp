// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_FireWeapon/ACTION_FireWeapon.h"

UACTION_FireWeapon::UACTION_FireWeapon()
{
	ActionString = "fire weapon";
}

bool UACTION_FireWeapon::InitActionFor(UScriptedController* C)
{
	return false;
}