// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_LevelJump.generated.h"

class AHumanController;

UCLASS()
class UDir_LevelJump : public UDirection
{
	GENERATED_BODY()
public:
	UDir_LevelJump();

	UPROPERTY()						FRotator			_sLevel;				//var FString _sLevel;
	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
