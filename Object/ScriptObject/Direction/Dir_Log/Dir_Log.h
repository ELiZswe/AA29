// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_Log.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_Log : public UDirection
{
	GENERATED_BODY()
public:
	UDir_Log();

	UPROPERTY()						FString		LogMessage;		//var FString LogMessage;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
