// All the original content belonged to the US Army

#include "AA29/Object/DamageType/Crushed/Crushed.h"

UCrushed::UCrushed()
{
	DeathString      = "%o was crushed by %k.";
	FemaleSuicide    = "%o was crushed.";
	MaleSuicide      = "%o was crushed.";
	bArmorStops      = false;
	bAlwaysGibs      = true;
	bLocationalHit   = false;
	GibPerterbation  = 1;
}
