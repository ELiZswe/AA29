// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenPawnTriggerChanges.generated.h"

class AAGP_Pawn;

UCLASS()
class AA29_API UCond_WhenPawnTriggerChanges : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenPawnTriggerChanges();

	UPROPERTY()										bool bWasInTrigger;					//var bool bWasInTrigger;
	UPROPERTY()										bool _bEntry;						//var bool _bEntry;
	UPROPERTY()										FName _TriggerTag;					//var name _TriggerTag;
	UPROPERTY()										AAGP_Pawn* _Pawn;					//var AGP.AGP_Pawn _Pawn;
	UPROPERTY()										AActor* _Actor;						//var Actor _Actor;
};
