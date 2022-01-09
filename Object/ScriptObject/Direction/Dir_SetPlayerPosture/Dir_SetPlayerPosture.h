// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetPlayerPosture.generated.h"

class AHumanController;

UCLASS()
class UDir_SetPlayerPosture : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetPlayerPosture();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						int32				_iPosture;				//var int32 _iPosture;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
