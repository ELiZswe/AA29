// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/KarmaBoostDest/KarmaBoostDest.h"

AKarmaBoostDest::AKarmaBoostDest()
{
	bSpecialForced = true;
	bVehicleDestination = true;
}
/*

int32 AKarmaBoostDest::SpecialCost(APawn* Other, AReachSpec* Path)
{
	if (Vehicle(Other) == None || !Vehicle(Other).bCanDoTrickJumps)
	{
		return 10000000;
	}
	return - 0.5 * Path.Distance;
	return 0;     //FAKE   /ELiZ
}
	*/
