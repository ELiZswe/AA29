// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_DamageActor/ACTION_DamageActor.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_DamageActor::UACTION_DamageActor()
{
	ActionString = "Damage actor";
}

bool UACTION_DamageActor::InitActionFor(AScriptedController* C)
{
	AActor* A = nullptr;
	/*
	if (DamageTag != "None")
	{
		ForEach C.AllActors(Class'Actor', A, DamageTag)
		{
			A.TakeDamage(DamageAmount, C.Pawn, A.Location, FVector(0,0,0), DamageType);
		}
	}
	*/
	return false;
}
