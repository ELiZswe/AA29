// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_StartTimer.generated.h"

class AAGP_Timer;

UCLASS()
class UDir_StartTimer : public UDirection
{
	GENERATED_BODY()
public:
	UDir_StartTimer();

	UPROPERTY()						AAGP_Timer*			_timer;					//var AGP_Gameplay.AGP_Timer _timer;
	UPROPERTY()						float				_Timeout;				//var float _Timeout;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
