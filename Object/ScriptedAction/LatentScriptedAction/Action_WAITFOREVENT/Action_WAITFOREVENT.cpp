// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFOREVENT/Action_WAITFOREVENT.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Triggers/TriggeredCondition/TriggeredCondition.h"

UAction_WAITFOREVENT::UAction_WAITFOREVENT()
{
	ActionString = "Wait for external event";
}

bool UAction_WAITFOREVENT::InitActionFor(AScriptedController* C)
{
	/*
	if (t == nullptr)
	{
		ForEach C.AllActors('TriggeredCondition', t, ExternalEvent)
		{
		}
	}
	if (t != nullptr && t.bEnabled)
	{
		return false;
	}
	C.CurrentAction = this;
	C.Tag = ExternalEvent;
	*/
	return true;
}
bool UAction_WAITFOREVENT::CompleteWhenTriggered()
{
	return true;
}
FString UAction_WAITFOREVENT::GetActionString()
{
	//return ActionString @ ExternalEvent;
	return "";     //FAKE   /ELiZ
}
