// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/KarmaBoostDest/KarmaBoostDest.h"
#include "AA29/Object/ReachSpec/ReachSpec.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

AKarmaBoostDest::AKarmaBoostDest()
{
	bSpecialForced = true;
	bVehicleDestination = true;
}
/*

int32 AKarmaBoostDest::SpecialCost(APawn* Other, UReachSpec* Path)
{
	if (Cast<AVehicle>(Other) == nullptr || !Vehicle(Other).bCanDoTrickJumps)
	{
		return 10000000;
	}
	return - 0.5 * Path.Distance;
	return 0;     //FAKE   /ELiZ
}
	*/
