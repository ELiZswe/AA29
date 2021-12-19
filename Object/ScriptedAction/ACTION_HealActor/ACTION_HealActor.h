// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_HealActor.generated.h"

class UaDamageType;

UCLASS()
class AA29_API UACTION_HealActor : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_HealActor();


	UPROPERTY(EditAnywhere, Category = "Action")		UaDamageType* DamageType;			//var(Action) class<DamageType> DamageType;
	UPROPERTY(EditAnywhere, Category = "Action")		int32 HealAmount;					//var(Action) int HealAmount;
	UPROPERTY(EditAnywhere, Category = "Action")		FName HealTag;						//var(Action) name HealTag;

	bool InitActionFor(AScriptedController* C);
};
