// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedTriggerController/ScriptedTriggerController.h"

AScriptedTriggerController::AScriptedTriggerController()
{

}

/*
State Scripting
{
	Function Trigger(Actor Other, Pawn EventInstigator)
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
	Warn(" Trigger Scripted Sequence BROKEN " $ string(SequenceScript) $ " ACTION " $ string(CurrentAction));
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
	//SequenceScript.SetActions(Self);
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
