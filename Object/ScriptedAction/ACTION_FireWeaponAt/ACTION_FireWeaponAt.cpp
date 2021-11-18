// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_FireWeaponAt/ACTION_FireWeaponAt.h"

UACTION_FireWeaponAt::UACTION_FireWeaponAt()
{
	ActionString = "fire weapon";
}

bool UACTION_FireWeaponAt::InitActionFor(UScriptedController* C)
{
	/*
	if (ShootTarget == None)
	{
		ForEach C.AllActors(Class'Actor', ShootTarget, ShootTargetTag)
		{
		}
	}
	if (ShootTarget != None)
	{
		C.FireWeaponAt(ShootTarget);
	}
	*/
	return false;
}
