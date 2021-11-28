// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_ControlAnimation.generated.h"

class AAnimationController;

UCLASS()
class AA29_API UDir_ControlAnimation : public UDirection
{
	GENERATED_BODY()
public:
	UDir_ControlAnimation();

	UPROPERTY()						AAnimationController*			_Controller;				//var AnimationController _Controller;
	UPROPERTY()						FAnimInstruction				_Instruction;				//var Actor.AnimInstruction _Instruction;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
