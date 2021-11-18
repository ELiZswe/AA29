// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "FSTS_ScriptedSequence.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_ScriptedSequence : public AScriptedSequence
{
	GENERATED_BODY()
public:
	AFSTS_ScriptedSequence(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere, Category = "AIScript")			FString ProductionFile;							//var(AIScript) string ProductionFile;
};
