// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetClock.generated.h"

UCLASS()
class AA29_API UDir_SetClock : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetClock();

	UPROPERTY()						float					_fTime;				//var float _fTime;
	UPROPERTY()						bool					_bCountdown;		//var bool _bCountdown;

	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
