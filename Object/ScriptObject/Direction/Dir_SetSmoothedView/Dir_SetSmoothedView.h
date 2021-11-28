// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetSmoothedView.generated.h"

class AHumanController;

UCLASS()
class AA29_API UDir_SetSmoothedView : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetSmoothedView();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						bool				_bSmooth;				//var bool _bSmooth;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
