// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"
#include "HoverPathNode.generated.h"

class UReachSpec;

UCLASS()
class AA29_API AHoverPathNode : public ARoadPathNode
{
	GENERATED_BODY()
public:
	AHoverPathNode();

	int32 SpecialCost(APawn* Other, UReachSpec* Path);
};
