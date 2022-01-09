// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_WeaponInduceJam.generated.h"

class AHumanController;

UCLASS()
class UDir_WeaponInduceJam : public UDirection
{
	GENERATED_BODY()
public:
	UDir_WeaponInduceJam();

	UPROPERTY()						AHumanController* _HumanController;			//var HumanController _HumanController;

	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();

};
