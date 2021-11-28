// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SequenceManagerActive.generated.h"

class ASequenceManager;

UCLASS()
class AA29_API UDir_SequenceManagerActive : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SequenceManagerActive();

	UPROPERTY()						ASequenceManager*	_SequenceManager;		//var AGP_Gameplay.SequenceManager _SequenceManager;
	UPROPERTY()						bool				_bActive;				//var bool _bActive;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
