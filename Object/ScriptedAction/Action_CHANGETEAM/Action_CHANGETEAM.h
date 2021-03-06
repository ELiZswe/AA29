// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_CHANGETEAM.generated.h"

class AScriptedController;
UCLASS()
class UAction_CHANGETEAM : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_CHANGETEAM();


	UPROPERTY(EditAnywhere, Category = "Action")		int32 Team;		//var(Action) int Team;

	bool InitActionFor(AScriptedController* C);
};
