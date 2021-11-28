// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SceneEnd.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_SceneEnd : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SceneEnd();

	void DirectionStart();
	bool ProcessParams();

};
