// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_DisplayLandNavScore.generated.h"

class AHumanController;
class ALandNavScoreManager;

UCLASS()
class AA29_API UDir_DisplayLandNavScore : public UDirection
{
	GENERATED_BODY()
public:
	UDir_DisplayLandNavScore();

	UPROPERTY()						AHumanController*			_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						ALandNavScoreManager*		Scm;					//var AGP_Gameplay.LandNavScoreManager Scm;
	UPROPERTY()						bool						bToScreen;				//var bool bToScreen;
	UPROPERTY()						bool						bToFile;				//var bool bToFile;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
