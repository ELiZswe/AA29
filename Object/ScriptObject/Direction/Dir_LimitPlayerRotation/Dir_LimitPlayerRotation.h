// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_LimitPlayerRotation.generated.h"

class AHumanController;

UCLASS()
class UDir_LimitPlayerRotation : public UDirection
{
	GENERATED_BODY()
public:
	UDir_LimitPlayerRotation();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						bool				_bLimit;				//var bool _bLimit;
	UPROPERTY()						FRotator			_rRotator;				//var Rotator _rRotator;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
