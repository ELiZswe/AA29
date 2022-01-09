// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_CheckParachute.generated.h"

class AHumanController;
class AAGP_IntVar;

UCLASS()
class UDir_CheckParachute : public UDirection
{
	GENERATED_BODY()
public:
	UDir_CheckParachute();

	UPROPERTY()						AHumanController*	_HumanController;		//var HumanController _HumanController;
	UPROPERTY()						AAGP_IntVar*		_IntVar;				//var AGP_Gameplay.AGP_IntVar _IntVar;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
