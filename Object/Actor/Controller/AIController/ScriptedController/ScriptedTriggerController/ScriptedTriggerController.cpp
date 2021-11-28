// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedTriggerController/ScriptedTriggerController.h"

AScriptedTriggerController::AScriptedTriggerController()
{

}


void LeaveScripting()
{
	//Super::Destroy();
}
void Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	Instigator = EventInstigator;
	Trigger(Other,EventInstigator);
	*/
}
/*
void InitializeFor(AScriptedTrigger* t)
{
	SequenceScript = t;
	ActionNum = 0;
	SequenceScript.SetActions(Self);
	GotoState('Scripting');
}
	*/
/*
void GameHasEnded()
{
}
*/

void ClientGameEnded()
{
}

void RoundHasEnded()
{
}

void ClientRoundEnded()
{
}

void DestroyPawn()
{
	/*
	if (Instigator != nullptr)
	{
		Instigator->Destroy();
	}
	*/
}
void ClearAnimation()
{
}
/*
void SetNewScript(ScriptedSequence NewScript)
{
	SequenceScript = NewScript;
	ActionNum = 0;
	Focus = None;
	SequenceScript.SetActions(Self);
}
	*/
