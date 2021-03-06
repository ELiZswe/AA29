// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/MyEnums.h"
#include "ACTION_SetPhysics.generated.h"

class AScriptedController;
UCLASS()
class UACTION_SetPhysics : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_SetPhysics();

	UPROPERTY(EditAnywhere, Category = "Action")			EPhysics NewPhysicsMode;					//var(Action) Actor.EPhysics NewPhysicsMode;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();
};
