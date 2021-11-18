// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/ACTION_FinishRotation/ACTION_FinishRotation.h"

UACTION_FinishRotation::UACTION_FinishRotation()
{
	ActionString = "Finish rotation";
}


bool UACTION_FinishRotation::TurnToGoal()
{
	return true;
}