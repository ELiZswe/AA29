// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_ES2_SetupObjs.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_ES2_SetupObjs : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_ES2_SetupObjs();

	UPROPERTY(EditAnywhere, Category = "Action")		int32 nMaxObjs;						//var(Action) int nMaxObjs;
	UPROPERTY(EditAnywhere, Category = "Action")		int32 nMinObjs;						//var(Action) int nMinObjs;
	UPROPERTY(EditAnywhere, Category = "Action")		TArray<FName> ES2_GroupTags;		//var(Action) array<name> ES2_GroupTags;

	void InitActionFor(UScriptedController* C);
};
