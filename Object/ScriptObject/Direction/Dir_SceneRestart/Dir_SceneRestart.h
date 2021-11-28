// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SceneRestart.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_SceneRestart : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SceneRestart();

	void DirectionStart();
	bool ProcessParams();
};
