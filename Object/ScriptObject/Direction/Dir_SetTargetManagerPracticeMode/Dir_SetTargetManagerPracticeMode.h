// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetTargetManagerPracticeMode.generated.h"

class ATargetManager;

UCLASS()
class AA29_API UDir_SetTargetManagerPracticeMode : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetTargetManagerPracticeMode();

	UPROPERTY()						ATargetManager* _TargetManager;			//var AGP_Gameplay.TargetManager _TargetManager;
	UPROPERTY()						bool _bPractice;						//var bool _bPractice;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
