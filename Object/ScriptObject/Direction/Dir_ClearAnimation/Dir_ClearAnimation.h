// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_ClearAnimation.generated.h"

class AAnimationController;

UCLASS()
class AA29_API UDir_ClearAnimation : public UDirection
{
	GENERATED_BODY()
public:
	UDir_ClearAnimation();

	UPROPERTY()						AAnimationController* _Controller;				//var AnimationController _Controller;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
