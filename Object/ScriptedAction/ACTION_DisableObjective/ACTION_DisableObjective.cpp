// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_DisableObjective/ACTION_DisableObjective.h"

UACTION_DisableObjective::UACTION_DisableObjective()
{
	bClearInstigator = true;
	ActionString = "disable objective";
}


void UACTION_DisableObjective::PostBeginPlay(AScriptedSequence* SS)
{
	/*
	Super::PostBeginPlay(SS);
	if (ObjectiveTag != 'None')
	{
		ForEach SS.AllActors('GameObjective', GO, ObjectiveTag)
		{
		}
	}
	*/
}
bool UACTION_DisableObjective::InitActionFor(UScriptedController* C)
{
	/*
	local Pawn Instigator;
	if (!bClearInstigator)
	{
		Instigator = C.GetInstigator();
	}
	*/
	return false;
}
FString UACTION_DisableObjective::GetActionString()
{
	//Return ActionString @ ObjectiveTag;
	return "";   //FAKE   /ELiZ
}