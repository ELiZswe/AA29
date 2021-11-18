// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ScriptedAction.h"

UScriptedAction::UScriptedAction()
{
	ActionString = "unspecified action";
	bValidForTrigger = true;

}



void UScriptedAction::ActionCompleted()
{
}
void UScriptedAction::PostBeginPlay(AScriptedSequence* SS)
{
}
void UScriptedAction::Reset()
{
}
bool UScriptedAction::InitActionFor(UScriptedController* C)
{
	return false;
}
bool UScriptedAction::EndsSection()
{
	return false;
}
bool UScriptedAction::StartsSection()
{
	return false;
}
AScriptedSequence* UScriptedAction::GetScript(AScriptedSequence* S)
{
	return S;
}
void UScriptedAction::ProceedToNextAction(UScriptedController* C)
{
	//C.ActionNum += 1;
}
void UScriptedAction::ProceedToSectionEnd(UScriptedController* C)
{
	/*
	local int Nesting;
	local ScriptedAction A;
	if (C.ActionNum < C.SequenceScript.Actions.Length)
	{
		A = C.SequenceScript.Actions[C.ActionNum];
		if (A.StartsSection())
		{
			Nesting++;
		}
		else
		{
			if (A.EndsSection())
			{
				Nesting--;
				if (Nesting < 0)
				{
					Return;
				}
			}
		}
		C.ActionNum += 1;
	}
	*/
}
FString UScriptedAction::GetActionString()
{
	return ActionString;
}