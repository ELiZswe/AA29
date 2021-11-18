// All the original content belonged to the US Army


#include "AA29/NavigationPoint/KarmaBoostDest/KarmaBoostDest.h"

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
		Return 10000000;
	}
	Return - 0.5 * Path.Distance;
	return 0;     //FAKE   /ELiZ
}
	*/
