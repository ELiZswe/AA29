// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenEventSounds.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCond_WhenEventSounds : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenEventSounds();

	//UPROPERTY()										AEventSound* _EventSound;					//var AGP_Gameplay.EventSound _EventSound;
};
