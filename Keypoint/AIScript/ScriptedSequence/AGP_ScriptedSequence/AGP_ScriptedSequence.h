// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "AGP_ScriptedSequence.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ScriptedSequence : public AScriptedSequence
{
	GENERATED_BODY()
public:
	AAGP_ScriptedSequence(const FObjectInitializer& objectInitializer);


	UPROPERTY()												bool bDisabled;							//var bool bDisabled;
	UPROPERTY()												bool bAvoid;							//var bool bAvoid;
};
