// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_HealActor/ACTION_HealActor.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_HealActor::UACTION_HealActor()
{
	ActionString = "Heal actor";
}

bool UACTION_HealActor::InitActionFor(AScriptedController* C)
{
	/*
	local Actor A;
	if (HealTag != "None")
	{
		ForEach C.AllActors(Class'Actor', A, HealTag)
		{
			A.HealDamage(HealAmount, C, DamageType);
		}
	}
	*/
	return false;
}
