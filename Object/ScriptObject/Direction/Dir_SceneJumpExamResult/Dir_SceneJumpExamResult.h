// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SceneJumpExamResult.generated.h"

class AMedExam;

UCLASS()
class UDir_SceneJumpExamResult : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SceneJumpExamResult();

	UPROPERTY()						AMedExam*	MedExam;				//var AGP_Gameplay.MedExam MedExam;
	UPROPERTY()						FName		Scene;					//var FName Scene;
	UPROPERTY()						int32		LowPercentage;			//var int32 LowPercentage;
	UPROPERTY()						int32		HighPercentage;			//var int32 HighPercentage;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
