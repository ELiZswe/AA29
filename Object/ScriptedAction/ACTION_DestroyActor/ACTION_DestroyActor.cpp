// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_DestroyActor/ACTION_DestroyActor.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_DestroyActor::UACTION_DestroyActor()
{
	ActionString = "Destroy actor";
}

bool UACTION_DestroyActor::InitActionFor(AScriptedController* C)
{
	AActor* A = nullptr;
	/*
	if (DestroyTag != "None")
	{
		ForEach C.AllActors(Class'Actor', A, DestroyTag)
		{
			A.Destroy();
		}
	}
	*/
	return false;
}
