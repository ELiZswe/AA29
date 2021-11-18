// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_Scripted.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAnimNotify_Scripted : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_Scripted();

	void Notify(AActor* Owner);
};
