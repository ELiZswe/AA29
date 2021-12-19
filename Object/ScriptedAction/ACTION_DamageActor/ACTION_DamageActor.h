// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_DamageActor.generated.h"

class UaDamageType;

UCLASS()
class AA29_API UACTION_DamageActor : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_DamageActor();


	UPROPERTY(EditAnywhere, Category = "Action")		UaDamageType* DamageType;		//var(Action) class<DamageType> DamageType;
	UPROPERTY(EditAnywhere, Category = "Action")		int32 DamageAmount;				//var(Action) int DamageAmount;
	UPROPERTY(EditAnywhere, Category = "Action")		FName DamageTag;				//var(Action) name DamageTag;

	bool InitActionFor(AScriptedController* C);
};
