// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_DisableObjective/ACTION_DisableObjective.h"
#include "AA29/Object/Actor/NavigationPoint/GameObjective/GameObjective.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"

UACTION_DisableObjective::UACTION_DisableObjective()
{
	bClearInstigator = true;
	ActionString = "disable objective";
}

void UACTION_DisableObjective::PostBeginPlay(AScriptedSequence* SS)
{
	/*
	Super::PostBeginPlay(SS);
	if (ObjectiveTag != "None")
	{
		ForEach SS.AllActors('GameObjective', GO, ObjectiveTag)
		{
		}
	}
	*/
}

bool UACTION_DisableObjective::InitActionFor(AScriptedController* C)
{
	APawn* Instigator = nullptr;
	/*
	if (!bClearInstigator)
	{
		Instigator = C.GetInstigator();
	}
	*/
	return false;
}

FString UACTION_DisableObjective::GetActionString()
{
	//return ActionString @ ObjectiveTag;
	return "";   //FAKE   /ELiZ
}
