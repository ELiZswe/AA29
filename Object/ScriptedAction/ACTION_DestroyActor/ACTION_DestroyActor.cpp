// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_DestroyActor/ACTION_DestroyActor.h"

UACTION_DestroyActor::UACTION_DestroyActor()
{
	ActionString = "Destroy actor";
}

bool UACTION_DestroyActor::InitActionFor(UScriptedController* C)
{
	/*
	local Actor A;
	if (DestroyTag != 'None')
	{
		ForEach C.AllActors(Class'Actor', A, DestroyTag)
		{
			A.Destroy();
		}
	}
	*/
	return false;
}