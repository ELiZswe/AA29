// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenSoundEnds.generated.h"

class AAGP_Sound;

UCLASS()
class AA29_API UCond_WhenSoundEnds : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenSoundEnds();

	UPROPERTY()										AAGP_Sound* _Sound;					//var AGP_Gameplay.AGP_Sound _Sound;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
};
