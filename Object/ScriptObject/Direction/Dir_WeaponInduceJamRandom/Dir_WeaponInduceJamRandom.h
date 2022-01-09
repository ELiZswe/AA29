// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_WeaponInduceJamRandom.generated.h"

class AHumanController;

UCLASS()
class UDir_WeaponInduceJamRandom : public UDirection
{
	GENERATED_BODY()
public:
	UDir_WeaponInduceJamRandom();

	UPROPERTY()						AHumanController*	_HumanController;			//var HumanController _HumanController;
	UPROPERTY()						int32				iRandNum;					//var int32 iRandNum;
	UPROPERTY()						bool				bOnceOnly;					//var bool bOnceOnly;
	UPROPERTY()						bool				bJammed;					//var bool bJammed;

	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
