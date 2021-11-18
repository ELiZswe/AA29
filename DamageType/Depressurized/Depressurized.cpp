// All the original content belonged to the US Army


#include "Depressurized.h"

UDepressurized::UDepressurized()
{
	DeathString      = "%o was depressurized by %k.";
	FemaleSuicide    = "%o was depressurized.";
	MaleSuicide      = "%o was depressurized.";
	bArmorStops      = false;
	bAlwaysGibs      = true;
	bLocationalHit   = false;
	GibPerterbation  = 1;
}