// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/BaseShellEmitter.h"
#include "Javelin_Tube_Emitter.generated.h"

UCLASS()
class AJavelin_Tube_Emitter : public ABaseShellEmitter
{
	GENERATED_BODY()
public:
	AJavelin_Tube_Emitter();

	FRangeVector GetStartVelocity();
	FRangeVector GetStartRotation();
};
