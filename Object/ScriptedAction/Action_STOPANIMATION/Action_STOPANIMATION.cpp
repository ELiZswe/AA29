// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_STOPANIMATION/Action_STOPANIMATION.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_STOPANIMATION::UAction_STOPANIMATION()
{
	ActionString = "stop animation";
	bValidForTrigger = false;

}

bool UAction_STOPANIMATION::InitActionFor(AScriptedController* C)
{
	//C.ClearAnimation();
	return false;
}
