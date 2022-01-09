// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_TriggerActive.generated.h"

class ATrigger;
class AAGP_Trigger;

UCLASS()
class UDir_TriggerActive : public UDirection
{
	GENERATED_BODY()
public:
	UDir_TriggerActive();

	UPROPERTY()						ATrigger*			_Trigger;		//var Trigger _Trigger;
	UPROPERTY()						AAGP_Trigger*		_AGPTrigger;	//var AGP_Gameplay.AGP_Trigger _AGPTrigger;
	UPROPERTY()						bool				_bActive;		//var bool _bActive;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
