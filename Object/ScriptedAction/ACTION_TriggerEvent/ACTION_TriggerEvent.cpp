// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_TriggerEvent/ACTION_TriggerEvent.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_TriggerEvent::UACTION_TriggerEvent()
{
	ActionString = "trigger event";
}

bool UACTION_TriggerEvent::InitActionFor(AScriptedController* C)
{
	//C.TriggerEvent(Event, C.SequenceScript, C.GetInstigator());
	return false;
}
FString UACTION_TriggerEvent::GetActionString()
{
	//return ActionString @ Event;
	return "";    //FAKE  /ELiZ
}
