// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "FSTS_ScriptedSequence.generated.h"

UCLASS()
class AFSTS_ScriptedSequence : public AScriptedSequence
{
	GENERATED_BODY()
public:
	AFSTS_ScriptedSequence(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere, Category = "AIScript")			FString ProductionFile;							//var(AIScript) string ProductionFile;
	
	void TakeOver(APawn* p);
};
