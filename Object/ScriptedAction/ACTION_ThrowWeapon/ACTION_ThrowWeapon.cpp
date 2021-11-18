// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_ThrowWeapon/ACTION_ThrowWeapon.h"

UACTION_ThrowWeapon::UACTION_ThrowWeapon()
{
	ActionString = "throw weapon";
}


bool UACTION_ThrowWeapon::InitActionFor(UScriptedController* C)
{
	/*
	if (C.Pawn == None || C.Pawn.Weapon == None)
	{
		Return False;
	}
	if (WeaponVelocity == vect(0 0 0))
	{
		WeaponVelocity = C.Pawn.Velocity + vect(0 0 250) + 300 * Vector(C.Pawn.Rotation);
	}
	C.Pawn.TossWeapon(WeaponVelocity);
	*/
	return false;
}