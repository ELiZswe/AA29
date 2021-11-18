// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_STOPANIMATION/Action_STOPANIMATION.h"

UAction_STOPANIMATION::UAction_STOPANIMATION()
{
	ActionString = "stop animation";
	bValidForTrigger = false;

}

bool UAction_STOPANIMATION::InitActionFor(UScriptedController* C)
{
	//C.ClearAnimation();
	return false;
}