// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_TargetManagerActive.generated.h"

class ATargetManager;

UCLASS()
class UDir_TargetManagerActive : public UDirection
{
	GENERATED_BODY()
public:
	UDir_TargetManagerActive();

	UPROPERTY()						ATargetManager*		_TargetManager;			//var AGP_Gameplay.TargetManager _TargetManager;
	UPROPERTY()						bool				_bActive;				//var bool _bActive;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
