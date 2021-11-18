// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_FireCROWSWeaponAT/ACTION_FireCROWSWeaponAT.h"

UACTION_FireCROWSWeaponAT::UACTION_FireCROWSWeaponAT()
{
	ActionString = "fire weapon";
}


bool UACTION_FireCROWSWeaponAT::InitActionFor(UScriptedController* C)
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
		C.Target = ShootTarget;
	}
	if (VehiclePosition(C.Pawn) == None || VehiclePosition(C.Pawn).Gun == None)
	{
		Return False;
	}
	if (bPressFire)
	{
		VehiclePosition(C.Pawn).Gun.SpawnProjectile(VehiclePosition(C.Pawn).Gun.ProjectileClass, False);
		C.bFire = 1;
	}
	else
	{
		C.bFire = 0;
	}
	if (bPressAltFire)
	{
		C.bAltFire = 1;
	}
	else
	{
		C.bAltFire = 0;
	}
	C.bFineWeaponControl = bPressFire || bPressAltFire;
	*/
	return false;
}