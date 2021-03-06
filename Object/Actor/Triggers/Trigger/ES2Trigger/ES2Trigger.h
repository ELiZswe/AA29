// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "ES2Trigger.generated.h"

class AAGP_CoopESSObjective;

UCLASS()
class AES2Trigger : public ATrigger
{
	GENERATED_BODY()
public:
	AES2Trigger();
	
	UPROPERTY(EditAnywhere, Category = "ES2")		AAGP_CoopESSObjective*	ObjectiveReference;			//var(ES2) edfindable AGP_CoopESSObjective ObjectiveReference;

	void DoTouch(AActor* Other);
};
