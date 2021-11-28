// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_Trigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_Trigger : public UDirection
{
	GENERATED_BODY()
public:
	UDir_Trigger();

	UPROPERTY()						AActor*				_Trigger;		//var Actor _Trigger;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
