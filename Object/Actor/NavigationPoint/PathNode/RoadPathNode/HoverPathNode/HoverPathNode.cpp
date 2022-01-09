// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/HoverPathNode/HoverPathNode.h"
#include "AA29/Object/ReachSpec/ReachSpec.h"

AHoverPathNode::AHoverPathNode()
{
	bNotBased = true;
	bSpecialForced = true;
	bForcedOnly = true;
	//CollisionHeight = 120;
}

int32 AHoverPathNode::SpecialCost(APawn* Other, UReachSpec* Path)
{
	/*
	if (Other.bCanFly || Vehicle(Other) != nullptr && Vehicle(Other).bCanHover)
	{
		return 0;
	}
	*/
	return 100000000;
}
