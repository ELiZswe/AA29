// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_TargetManagerPause.generated.h"

class ATargetManager;

UCLASS()
class AA29_API UDir_TargetManagerPause : public UDirection
{
	GENERATED_BODY()
public:
	UDir_TargetManagerPause();

	UPROPERTY()						ATargetManager*		_TargetManager;		//var AGP_Gameplay.TargetManager _TargetManager;
	UPROPERTY()						bool				_bPause;			//var bool _bPause;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
