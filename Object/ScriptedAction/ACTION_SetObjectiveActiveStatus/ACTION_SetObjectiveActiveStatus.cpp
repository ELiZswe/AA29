// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_SetObjectiveActiveStatus/ACTION_SetObjectiveActiveStatus.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_SetObjectiveActiveStatus::UACTION_SetObjectiveActiveStatus()
{
	bActive = true;
	ActionString = "Change Objective's Active Status";
}

bool UACTION_SetObjectiveActiveStatus::InitActionFor(AScriptedController* C)
{
	return false;
}
FString UACTION_SetObjectiveActiveStatus::GetActionString()
{
	//return ActionString @ ObjectiveTag;
	return "";    //FAKE   /EliZ
}
