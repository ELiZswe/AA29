// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_EnableObjective.generated.h"

class AAGP_Objective;

UCLASS()
class UDir_EnableObjective : public UDirection
{
	GENERATED_BODY()
public:
	UDir_EnableObjective();

	UPROPERTY()						AAGP_Objective*			_Objective;					//var AGP_Objective _Objective;
	UPROPERTY()						bool					_bEnabled;					//var bool _bEnabled;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
