// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetPlayerNoRoll.generated.h"

class AHumanController;

UCLASS()
class AA29_API UDir_SetPlayerNoRoll : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetPlayerNoRoll();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						bool				_bNoRoll;				//var bool _bNoRoll;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
