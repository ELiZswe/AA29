// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_IFCONDITION/Action_IFCONDITION.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Triggers/TriggeredCondition/TriggeredCondition.h"

UAction_IFCONDITION::UAction_IFCONDITION()
{
	ActionString = "If condition";
}

void UAction_IFCONDITION::ProceedToNextAction(AScriptedController* C)
{
	/*
	if (t == nullptr && TriggeredConditionTag != "None")
	{
		ForEach C.AllActors('TriggeredCondition', t, TriggeredConditionTag)
		{
		}
	}
	C.ActionNum += 1;
	if (t == nullptr)
	{
		Warn("No TriggeredCondition with tag " + TriggeredConditionTag + " found, breaking " + C.SequenceScript);
		ProceedToSectionEnd(C);
		return;
	}
	if (!t.bEnabled)
	{
		ProceedToSectionEnd(C);
	}
	*/
}

bool UAction_IFCONDITION::StartsSection()
{
	return true;
}

FString UAction_IFCONDITION::GetActionString()
{
	//return ActionString @ t @ TriggeredConditionTag;
	return "";    //FAKE   /ELiZ
}
