// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_HidePlayerCompassObj.generated.h"

class AHumanController;

UCLASS()
class AA29_API UDir_HidePlayerCompassObj : public UDirection
{
	GENERATED_BODY()
public:
	UDir_HidePlayerCompassObj();

	UPROPERTY()						bool					_bHide;						//var bool _bHide;
	UPROPERTY()						AHumanController*		_HumanController;			//var HumanController _HumanController;
	
	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
