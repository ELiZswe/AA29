// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenDoorIsOpen.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCond_WhenDoorIsOpen : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenDoorIsOpen();

	UPROPERTY()										bool bOpen;					//var bool bOpen;
	//UPROPERTY()										ADoorTrigger* DoorTrigger;					//var AGP_Gameplay.DoorTrigger DoorTrigger;


	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();

};
