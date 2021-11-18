// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_SetHidden/ACTION_SetHidden.h"

UACTION_SetHidden::UACTION_SetHidden()
{

}

void UACTION_SetHidden::PostBeginPlay(AScriptedSequence* SS)
{
	/*
	local Actor A;
	if (HideActorTag != 'None')
	{
		ForEach SS.AllActors(Class'Actor', A, HideActorTag)
		{
			Target[Target.Length] = A;
		}
	}
	*/
}
bool UACTION_SetHidden::InitActionFor(UScriptedController* C)
{
	/*
	local int i;
	if (Target.Length > 0)
	{
		for (i = 0; i < Target.Length; i++)
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