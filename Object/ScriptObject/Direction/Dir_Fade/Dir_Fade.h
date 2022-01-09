// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_Fade.generated.h"

class AHumanController;

UCLASS()
class UDir_Fade : public UDirection
{
	GENERATED_BODY()
public:
	UDir_Fade();


	UPROPERTY()						bool					_bFadeIn;					//var bool _bFadeIn;
	UPROPERTY()						bool					_bFadeBlack;				//var bool _bFadeBlack;
	UPROPERTY()						float					_bFadeTime;					//var float _bFadeTime;
	UPROPERTY()						AHumanController*		_HumanController;			//var HumanController _HumanController;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();

};
