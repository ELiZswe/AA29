// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_SetHidden/ACTION_SetHidden.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"

UACTION_SetHidden::UACTION_SetHidden()
{

}

void UACTION_SetHidden::PostBeginPlay(AScriptedSequence* SS)
{
	AActor* A = nullptr;
	/*
	if (HideActorTag != "None")
	{
		ForEach SS.AllActors(Class'Actor', A, HideActorTag)
		{
			Target[Target.Num()] = A;
		}
	}
	*/
}

bool UACTION_SetHidden::InitActionFor(AScriptedController* C)
{
	int32 i = 0;
	/*
	if (Target.Num() > 0)
	{
		for (i = 0; i < Target.Num(); i++)
		{
			Target[i].bHidden = bHidden;
		}
	}
	else
	{
		C.GetInstigator().bHidden = bHidden;
	}
	*/
	return false;
}
