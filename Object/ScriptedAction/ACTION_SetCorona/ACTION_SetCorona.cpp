// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_SetCorona/ACTION_SetCorona.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_SetCorona::UACTION_SetCorona()
{

}

bool UACTION_SetCorona::InitActionFor(AScriptedController* C)
{
	AActor* A = nullptr;
	/*
	if (HideActorTag != "None")
	{
		ForEach C.AllActors(Class'Actor', A, HideActorTag)
		{
			A.bCorona = bCorona;
		}
	}
	*/
	return false;
}
