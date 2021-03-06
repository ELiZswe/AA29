// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_SETVIEWTARGET.generated.h"

class AScriptedController;
UCLASS()
class UAction_SETVIEWTARGET : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_SETVIEWTARGET();

	UPROPERTY()												AActor* ViewTarget;						//var Actor ViewTarget;
	UPROPERTY(EditAnywhere, Category = "Action")			FName ViewTargetTag;					//var(Action) name ViewTargetTag;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();
};
