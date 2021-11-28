// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetTargetManagerScoreKeeper.generated.h"

class ATargetManager;
class AHumanController;

UCLASS()
class AA29_API UDir_SetTargetManagerScoreKeeper : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetTargetManagerScoreKeeper();

	UPROPERTY()						ATargetManager*		_TargetManager;					//var AGP_Gameplay.TargetManager _TargetManager;
	UPROPERTY()						AHumanController*	_HumanController;				//var HumanController _HumanController;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
