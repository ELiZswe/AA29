// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFORANIMEND/Action_WAITFORANIMEND.h"

UAction_WAITFORANIMEND::UAction_WAITFORANIMEND()
{
	ActionString = "Wait for animend";
	bValidForTrigger = false;
}


bool UAction_WAITFORANIMEND::CompleteOnAnim(int32 Num)
{
	return Channel == Num;
}
