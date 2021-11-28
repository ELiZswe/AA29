// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_UpdateParachute.generated.h"

class AHumanController;

UCLASS()
class AA29_API UDir_UpdateParachute : public UDirection
{
	GENERATED_BODY()
public:
	UDir_UpdateParachute();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						int32				_UpdateValue;			//var int32 _UpdateValue;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
