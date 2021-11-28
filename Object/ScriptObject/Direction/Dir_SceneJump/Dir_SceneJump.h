// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SceneJump.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_SceneJump : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SceneJump();

	UPROPERTY()						FName		_SceneTag;			//var FName _SceneTag;
	
	void DirectionStart();
	bool ProcessParams();
};
