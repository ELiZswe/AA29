// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedTriggerController/ScriptedTriggerController.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedTrigger/ScriptedTrigger.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"

AScriptedTriggerController::AScriptedTriggerController()
{

}

/*
State Scripting
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		Instigator=EventInstigator;
		Super::Trigger(Other,EventInstigator);
	}
	Function LeaveScripting()
	{
		Destroy();
	}
Begin:
	InitForNextAction();
	if (bBroken)
	{
		GotoState("Broken");
	}
	if (CurrentAction.TickedAction())
	{
		Enable("Tick");
	}
}
*/

/*
State Broken
{
Begin:
	Warn(" Trigger Scripted Sequence BROKEN " + FString::FromInt(SequenceScript) + " ACTION " + FString::FromInt(CurrentAction));
}
*/

void AScriptedTriggerController::LeaveScripting()
{
	//Super::Destroy();
}
void AScriptedTriggerController::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	Instigator = EventInstigator;
	Trigger(Other,EventInstigator);
	*/
}

void AScriptedTriggerController::InitializeFor(AScriptedTrigger* t)
{
	//SequenceScript = t;
	ActionNum = 0;
	//SequenceScript.SetActions(this);
	//GotoState('Scripting');
}

/*
bool AScriptedTriggerController::GameHasEnded()
{
	return false;    //FAKE   /ELiZ
}
*/

void AScriptedTriggerController::ClientGameEnded()
{
}

void AScriptedTriggerController::RoundHasEnded()
{
}

void AScriptedTriggerController::ClientRoundEnded()
{
}

void AScriptedTriggerController::DestroyPawn()
{
	/*
	if (Instigator != nullptr)
	{
		Instigator->Destroy();
	}
	*/
}
void AScriptedTriggerController::ClearAnimation()
{
}

void AScriptedTriggerController::SetNewScript(AScriptedSequence* NewScript)
{
	//SequenceScript = NewScript;
	ActionNum = 0;
	Focus = nullptr;
	//SequenceScript->SetActions(this);
}
