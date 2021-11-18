// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/ACTION_WaitForLIPSincAnimEnd/ACTION_WaitForLIPSincAnimEnd.h"

UACTION_WaitForLIPSincAnimEnd::UACTION_WaitForLIPSincAnimEnd()
{
	ActionString = "Wait for LIPSincAnimEnd";
	bValidForTrigger = false;
}


bool UACTION_WaitForLIPSincAnimEnd::CompleteOnLIPSincAnim()
{
	return true;
}