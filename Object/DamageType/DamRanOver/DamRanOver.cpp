// All the original content belonged to the US Army


#include "DamRanOver.h"

UDamRanOver::UDamRanOver()
{
	DeathString           = "%k ran over %o";
	FemaleSuicide         = "%o ran over herself";
	MaleSuicide           = "%o ran over himself";
	bLocationalHit        = false;
	bKUseTearOffMomentum  = true;
	bNeverSevers          = true;
	bExtraMomentumZ       = false;
	bVehicleHit           = true;
	GibModifier           = 2;
	GibPerterbation       = 0.5;
}