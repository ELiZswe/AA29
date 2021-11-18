// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_Scripted.h"
#include "AnimNotify_JavelinShrink.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAnimNotify_JavelinShrink : public UAnimNotify_Scripted
{
	GENERATED_BODY()
public:
	UAnimNotify_JavelinShrink();

	void Notify(AActor* Owner);
};
