// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_JumpOnPlayerHealth.generated.h"

class AHumanController;

UCLASS()
class UDir_JumpOnPlayerHealth : public UDirection
{
	GENERATED_BODY()
public:
	UDir_JumpOnPlayerHealth();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						int32				_Min;					//var int32 _Min;
	UPROPERTY()						int32				_Max;					//var int32 _Max;
	UPROPERTY()						FName				_JumpScene;				//var FName _JumpScene;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
