// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_KILLINSTIGATOR.generated.h"

class UaDamageType;

UCLASS()
class AA29_API UAction_KILLINSTIGATOR : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_KILLINSTIGATOR();

	UPROPERTY(EditAnywhere)		UaDamageType* DamageType;						//var() class<DamageType> DamageType;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();

};
