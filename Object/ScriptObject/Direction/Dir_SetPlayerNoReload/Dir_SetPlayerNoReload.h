// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetPlayerNoReload.generated.h"

class AHumanController;

UCLASS()
class UDir_SetPlayerNoReload : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetPlayerNoReload();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						bool				_bNoReload;				//var bool _bNoReload;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
