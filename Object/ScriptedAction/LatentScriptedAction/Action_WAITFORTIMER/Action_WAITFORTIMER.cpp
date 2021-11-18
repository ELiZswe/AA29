// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFORTIMER/Action_WAITFORTIMER.h"

UAction_WAITFORTIMER::UAction_WAITFORTIMER()
{
	ActionString = "Wait for timer";
}

bool UAction_WAITFORTIMER::InitActionFor(UScriptedController* C)
{
	/*
	C.CurrentAction = Self;
	C.SetTimer(PauseTime, False);
	*/
	return true;
}
bool UAction_WAITFORTIMER::CompleteWhenTriggered()
{
	return true;
}
bool UAction_WAITFORTIMER::CompleteWhenTimer()
{
	return true;
}
FString UAction_WAITFORTIMER::GetActionString()
{
	//return ActionString + PauseTime;
	return "";   //FAKE   /ELiZ
}	
