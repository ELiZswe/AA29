// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_ShootTarget.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_ShootTarget : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_ShootTarget();

	UPROPERTY(EditAnywhere, Category = "Action")						bool bSpray;						//var(Action) bool bSpray;
	UPROPERTY(EditAnywhere, Category = "Action")						FName FiringMode;					//var(Action) name FiringMode;
	UPROPERTY(EditAnywhere, Category = "Action")						int32 NumShots;						//var(Action) int NumShots;

};
