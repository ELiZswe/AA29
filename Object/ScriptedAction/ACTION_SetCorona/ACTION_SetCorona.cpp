// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_SetCorona/ACTION_SetCorona.h"

UACTION_SetCorona::UACTION_SetCorona()
{

}


bool UACTION_SetCorona::InitActionFor(UScriptedController* C)
{
	/*
	local Actor A;
	if (HideActorTag != 'None')
	{
		ForEach C.AllActors(Class'Actor', A, HideActorTag)
		{
			A.bCorona = bCorona;
		}
	}
	*/
	return false;
}