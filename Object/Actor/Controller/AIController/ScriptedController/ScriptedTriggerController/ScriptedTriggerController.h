// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "ScriptedTriggerController.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AScriptedTriggerController : public AScriptedController
{
	GENERATED_BODY()
public:
	AScriptedTriggerController();



	void LeaveScripting();
	void Trigger(AActor* Other, APawn* EventInstigator);
	//void InitializeFor(AScriptedTrigger* t);
	//void GameHasEnded();
	void ClientGameEnded();
	void RoundHasEnded();
	void ClientRoundEnded();
	void DestroyPawn();
	void ClearAnimation();
	//void SetNewScript(AScriptedSequence* NewScript);

};
