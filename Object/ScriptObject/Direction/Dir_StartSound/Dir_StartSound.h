// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_StartSound.generated.h"

class AAGP_Sound;

UCLASS()
class AA29_API UDir_StartSound : public UDirection
{
	GENERATED_BODY()
public:
	UDir_StartSound();

	UPROPERTY()						AAGP_Sound* _Sound;					//var AGP_Gameplay.AGP_Sound _Sound;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
	void SetSound(AAGP_Sound* Sound);
};
