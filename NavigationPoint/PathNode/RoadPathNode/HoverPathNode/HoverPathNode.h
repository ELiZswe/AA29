// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"
#include "HoverPathNode.generated.h"



UCLASS()
class AA29_API AHoverPathNode : public ARoadPathNode
{
	GENERATED_BODY()
public:
	AHoverPathNode();

	//int32 SpecialCost(APawn* Other, AReachSpec* Path)
};
