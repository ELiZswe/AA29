// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/MyStructs.h"
#include "ACTION_Jump.generated.h"


/**
 * 
 */
UCLASS()
class AA29_API UACTION_Jump : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_Jump();

	UPROPERTY(EditAnywhere, Category = "Action")		EJumpType JumpAction;						//var(Action) JumpType JumpAction;

	bool InitActionFor(UScriptedController* C);
};
