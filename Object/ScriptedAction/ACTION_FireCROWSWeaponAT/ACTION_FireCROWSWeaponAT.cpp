// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_FireCROWSWeaponAT/ACTION_FireCROWSWeaponAT.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"

UACTION_FireCROWSWeaponAT::UACTION_FireCROWSWeaponAT()
{
	ActionString = "fire weapon";
}

bool UACTION_FireCROWSWeaponAT::InitActionFor(AScriptedController* C)
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
		C.Target = ShootTarget;
	}
	if (VehiclePosition(C.Pawn) == nullptr || Cast<AVehiclePosition>(C.Pawn).Gun == nullptr)
	{
		return false;
	}
	if (bPressFire)
	{
		VehiclePosition(C.Pawn).Gun.SpawnProjectile(VehiclePosition(C.Pawn).Gun.ProjectileClass, false);
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
