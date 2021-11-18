// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_DamageActor/ACTION_DamageActor.h"

UACTION_DamageActor::UACTION_DamageActor()
{
	ActionString = "Damage actor";
}



bool UACTION_DamageActor::InitActionFor(UScriptedController* C)
{
	/*
	local Actor A;
	if (DamageTag != 'None')
	{
		ForEach C.AllActors(Class'Actor', A, DamageTag)
		{
			A.TakeDamage(DamageAmount, C.Pawn, A.Location, vect(0 0 0), DamageType);
		}
	}
	*/
	return false;
}