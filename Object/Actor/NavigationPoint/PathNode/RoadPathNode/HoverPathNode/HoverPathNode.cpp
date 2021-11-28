// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/HoverPathNode/HoverPathNode.h"

AHoverPathNode::AHoverPathNode()
{
	bNotBased = true;
	bSpecialForced = true;
	bForcedOnly = true;
	//CollisionHeight = 120;
}

/*
int32 SpecialCost(APawn* Other, AReachSpec* Path)
{
	if (Other.bCanFly || Vehicle(Other) != None && Vehicle(Other).bCanHover)
	{
		Return 0;
	}
	Return 100000000;
	
}
*/