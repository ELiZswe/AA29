// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "KeyGenerator.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UKeyGenerator : public UObject
{
	GENERATED_BODY()
public:
	UKeyGenerator();

	bool DoesKeyNeedGeneration();
	void BeginKeyGeneration();
	bool IsKeyGenerationComplete();

};
