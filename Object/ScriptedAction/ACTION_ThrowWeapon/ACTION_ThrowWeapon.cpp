// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ThrowWeapon/ACTION_ThrowWeapon.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_ThrowWeapon::UACTION_ThrowWeapon()
{
	ActionString = "throw weapon";
}

bool UACTION_ThrowWeapon::InitActionFor(AScriptedController* C)
{
	/*
	if (C.Pawn == nullptr || C.Pawn.Weapon == nullptr)
	{
		return false;
	}
	if (WeaponVelocity == FVector(0,0,0))
	{
		WeaponVelocity = C.Pawn.Velocity + FVector(0 0 250) + 300 * Vector(C.Pawn.Rotation);
	}
	C.Pawn.TossWeapon(WeaponVelocity);
	*/
	return false;
}
