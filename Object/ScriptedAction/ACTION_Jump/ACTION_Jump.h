// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/MyEnums.h"
#include "ACTION_Jump.generated.h"


class AScriptedController;
UCLASS()
class UACTION_Jump : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_Jump();

	UPROPERTY(EditAnywhere, Category = "Action")		EJumpType JumpAction;						//var(Action) JumpType JumpAction;

	bool InitActionFor(AScriptedController* C);
};
