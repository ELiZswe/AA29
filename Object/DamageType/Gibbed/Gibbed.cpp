// All the original content belonged to the US Army

#include "AA29/Object/DamageType/Gibbed/Gibbed.h"

UGibbed::UGibbed()
{
	DeathString      = "%o died";
	FemaleSuicide    = "%o died";
	MaleSuicide      = "%o died";
	bArmorStops      = false;
	bAlwaysGibs      = true;
	bLocationalHit   = false;
	GibPerterbation  = 1;
}
