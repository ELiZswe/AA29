// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_ChangeObjectiveTeam.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_ChangeObjectiveTeam : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_ChangeObjectiveTeam();



	UPROPERTY(EditAnywhere, Category = "Action")		uint8 NewTeam;			//var(Action) byte NewTeam;
	UPROPERTY(EditAnywhere, Category = "Action")		FName ObjectiveTag;		//var(Action) name ObjectiveTag;

	bool InitActionFor(UScriptedController* C);
};
