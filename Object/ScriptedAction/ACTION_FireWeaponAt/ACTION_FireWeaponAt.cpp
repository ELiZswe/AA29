// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_FireWeaponAt/ACTION_FireWeaponAt.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_FireWeaponAt::UACTION_FireWeaponAt()
{
	ActionString = "fire weapon";
}

bool UACTION_FireWeaponAt::InitActionFor(AScriptedController* C)
{
	/*
	if (ShootTarget == nullptr)
	{
		ForEach C.AllActors(Class'Actor', ShootTarget, ShootTargetTag)
		{
		}
	}
	if (ShootTarget != nullptr)
	{
		C.FireWeaponAt(ShootTarget);
	}
	*/
	return false;
}
