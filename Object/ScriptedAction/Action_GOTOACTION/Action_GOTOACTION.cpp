// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_GOTOACTION/Action_GOTOACTION.h"

UAction_GOTOACTION::UAction_GOTOACTION()
{
	ActionString = "go to action";
}

void UAction_GOTOACTION::ProceedToNextAction(AScriptedController* C)
{
	//C.ActionNum = Max(0, ActionNumber);
}
FString UAction_GOTOACTION::GetActionString()
{
	//Return ActionString @ ActionNumber;
	return "";     //FAKE   /ELiZ
}
