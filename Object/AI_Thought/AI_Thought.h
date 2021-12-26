// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AI_Thought.generated.h"

class AAGP_Bot;

UCLASS()
class UAI_Thought : public UObject
{
	GENERATED_BODY()
public:
	UAI_Thought();

	UPROPERTY()			UAI_Thought*	NextThought;					//var AI_Thought NextThought;

	bool Preformed(AAGP_Bot* Bot);
};
