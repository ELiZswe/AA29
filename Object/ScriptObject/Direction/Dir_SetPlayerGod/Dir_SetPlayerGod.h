// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetPlayerGod.generated.h"

class AHumanController;

UCLASS()
class UDir_SetPlayerGod : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetPlayerGod();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						bool				_bGod;					//var bool _bGod;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
