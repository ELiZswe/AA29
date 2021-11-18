// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_ChangeObjectiveTeam/ACTION_ChangeObjectiveTeam.h"

UACTION_ChangeObjectiveTeam::UACTION_ChangeObjectiveTeam()
{
	ActionString = "Change game objective team";
}

bool UACTION_ChangeObjectiveTeam::InitActionFor(UScriptedController* C)
{
	return false;
}