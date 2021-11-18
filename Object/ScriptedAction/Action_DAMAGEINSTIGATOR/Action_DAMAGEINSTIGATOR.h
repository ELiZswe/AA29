// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_DAMAGEINSTIGATOR.generated.h"

class UaDamageType;

UCLASS()
class AA29_API UAction_DAMAGEINSTIGATOR : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_DAMAGEINSTIGATOR();

	UPROPERTY(EditAnywhere, Category = "Action")		UaDamageType* DamageType;			//var(Action) class<DamageType> DamageType;
	UPROPERTY(EditAnywhere, Category = "Action")		int32 Damage;						//var(Action) int Damage;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();
};
