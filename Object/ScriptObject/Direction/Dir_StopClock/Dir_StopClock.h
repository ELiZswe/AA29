// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_StopClock.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_StopClock : public UDirection
{
	GENERATED_BODY()
public:
	UDir_StopClock();

	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
