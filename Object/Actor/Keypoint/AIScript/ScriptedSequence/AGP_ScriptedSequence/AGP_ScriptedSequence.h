// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "AGP_ScriptedSequence.generated.h"

UCLASS()
class AAGP_ScriptedSequence : public AScriptedSequence
{
	GENERATED_BODY()
public:
	AAGP_ScriptedSequence(const FObjectInitializer& objectInitializer);

	UPROPERTY()												bool bDisabled;							//var bool bDisabled;
	UPROPERTY()												bool bAvoid;							//var bool bAvoid;
};
