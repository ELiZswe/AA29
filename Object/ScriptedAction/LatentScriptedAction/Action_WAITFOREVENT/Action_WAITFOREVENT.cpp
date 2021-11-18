// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFOREVENT/Action_WAITFOREVENT.h"

UAction_WAITFOREVENT::UAction_WAITFOREVENT()
{
	ActionString = "Wait for external event";
}


bool UAction_WAITFOREVENT::InitActionFor(UScriptedController* C)
{
	/*
	if (t == None)
	{
		ForEach C.AllActors('TriggeredCondition', t, ExternalEvent)
		{
		}
	}
	if (t != None && t.bEnabled)
	{
		Return False;
	}
	C.CurrentAction = Self;
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
