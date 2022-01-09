// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SceneJumpOnStatus.generated.h"

class AHumanController;

UCLASS()
class UDir_SceneJumpOnStatus : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SceneJumpOnStatus();

	UPROPERTY()						AHumanController*		_HumanController;			//var HumanController _HumanController;
	UPROPERTY()						FName					_PassScene;					//var FName _PassScene;
	UPROPERTY()						FName					SceneIndex;					//var FName _FailScene;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
