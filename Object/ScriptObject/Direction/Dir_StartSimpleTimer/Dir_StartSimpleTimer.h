// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_StartSimpleTimer.generated.h"

class AAGP_Timer;

UCLASS()
class AA29_API UDir_StartSimpleTimer : public UDirection
{
	GENERATED_BODY()
public:
	UDir_StartSimpleTimer();

	UPROPERTY()						AAGP_Timer* _timer;					//var AGP_Gameplay.AGP_Timer _timer;
	UPROPERTY()						float		Delay;					//var float Delay;
	UPROPERTY()						FName		TimerTag;				//var FName TimerTag;
	UPROPERTY()						USoundBase*	TimerSound;				//var Sound TimerSound;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
