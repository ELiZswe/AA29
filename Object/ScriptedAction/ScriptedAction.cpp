// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"

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

bool UScriptedAction::InitActionFor(AScriptedController* C)
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

void UScriptedAction::ProceedToNextAction(AScriptedController* C)
{
	C->ActionNum += 1;
}

void UScriptedAction::ProceedToSectionEnd(AScriptedController* C)
{
	int32 Nesting = 0;
	UScriptedAction* A = nullptr;
	if (C->ActionNum < C->SequenceScript->Actions.Num())
	{
		A = C->SequenceScript->Actions[C->ActionNum];
		if (A->StartsSection())
		{
			Nesting++;
		}
		else
		{
			if (A->EndsSection())
			{
				Nesting--;
				if (Nesting < 0)
				{
					return;
				}
			}
		}
		C->ActionNum += 1;
	}
}
FString UScriptedAction::GetActionString()
{
	return ActionString;
}
