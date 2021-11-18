// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_IFCONDITION/Action_IFCONDITION.h"

UAction_IFCONDITION::UAction_IFCONDITION()
{
	ActionString = "If condition";
}

void UAction_IFCONDITION::ProceedToNextAction(UScriptedController* C)
{
	/*
	if (t == None && TriggeredConditionTag != 'None')
	{
		ForEach C.AllActors('TriggeredCondition', t, TriggeredConditionTag)
		{
		}
	}
	C.ActionNum += 1;
	if (t == None)
	{
		Warn("No TriggeredCondition with tag " $ TriggeredConditionTag $ " found, breaking " $ C.SequenceScript);
		ProceedToSectionEnd(C);
		Return;
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