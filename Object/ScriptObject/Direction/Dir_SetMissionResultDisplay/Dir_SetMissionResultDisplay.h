// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetMissionResultDisplay.generated.h"

class AHumanController;

UCLASS()
class AA29_API UDir_SetMissionResultDisplay : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetMissionResultDisplay();

	UPROPERTY()						FString _sMRD;							//var FString _sMRD;
	UPROPERTY()						AHumanController* _HumanController;		//var HumanController _HumanController;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
