// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ChangeObjectiveTeam/ACTION_ChangeObjectiveTeam.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_ChangeObjectiveTeam::UACTION_ChangeObjectiveTeam()
{
	ActionString = "Change game objective team";
}

bool UACTION_ChangeObjectiveTeam::InitActionFor(AScriptedController* C)
{
	return false;
}
