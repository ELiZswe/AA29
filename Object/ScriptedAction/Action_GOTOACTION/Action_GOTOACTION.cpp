// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_GOTOACTION/Action_GOTOACTION.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_GOTOACTION::UAction_GOTOACTION()
{
	ActionString = "go to action";
}

void UAction_GOTOACTION::ProceedToNextAction(AScriptedController* C)
{
	//C.ActionNum = FMath::Max(0, ActionNumber);
}
FString UAction_GOTOACTION::GetActionString()
{
	//return ActionString @ ActionNumber;
	return "";     //FAKE   /ELiZ
}
