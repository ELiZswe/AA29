// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SceneJumpRemembered.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_SceneJumpRemembered : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SceneJumpRemembered();

	UPROPERTY()						int32				SceneIndex;				//var int32 SceneIndex;

	void DirectionStart();
	bool ProcessParams();
};
