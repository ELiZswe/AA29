// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetLandNavScore.generated.h"

class ALandNavScoreManager;

UCLASS()
class UDir_SetLandNavScore : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetLandNavScore();

	UPROPERTY()						ALandNavScoreManager*	Scm;		//var AGP_Gameplay.LandNavScoreManager Scm;
	UPROPERTY()						int32					Index;		//var int32 Index;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
