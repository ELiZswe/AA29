// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AI_Thought/AI_Thought.h"
#include "WalkThought.generated.h"

class ANavigationPoint;
class AAGP_Bot;

UCLASS()
class AA29_API UWalkThought : public UAI_Thought
{
	GENERATED_BODY()
public:
	UWalkThought();

	UPROPERTY()											ANavigationPoint* Destination;									//var() NavigationPoint Destination;

	bool Preformed(AAGP_Bot* Bot);
};
