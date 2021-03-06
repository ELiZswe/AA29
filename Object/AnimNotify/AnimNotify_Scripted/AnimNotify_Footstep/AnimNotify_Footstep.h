// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_Scripted.h"
#include "AnimNotify_Footstep.generated.h"

UCLASS()
class UAnimNotify_Footstep : public UAnimNotify_Scripted
{
	GENERATED_BODY()
public:
	UAnimNotify_Footstep();

	void Notify(AActor* Owner);
};
