// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_SetHidden.generated.h"

class AScriptedController;
class AScriptedSequence;
UCLASS()
class UACTION_SetHidden : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_SetHidden();

	UPROPERTY()												TArray<AActor*> Target;			//var array<Actor> Target;
	UPROPERTY(EditAnywhere, Category = "Action")			FName HideActorTag;				//var(Action) name HideActorTag;
	UPROPERTY(EditAnywhere, Category = "Action")			bool bHidden;					//var(Action) bool bHidden;


	void PostBeginPlay(AScriptedSequence* SS);
	bool InitActionFor(AScriptedController* C);
};
