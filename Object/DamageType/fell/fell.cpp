// All the original content belonged to the US Army

#include "AA29/Object/DamageType/fell/fell.h"

Ufell::Ufell()
{
	DeathString      = "%o left a small crater";
	FemaleSuicide    = "%o left a small crater";
	MaleSuicide      = "%o left a small crater";
	bLocationalHit   = false;
	bCausedByWorld   = true;
	GibModifier      = 2;
	GibPerterbation  = 0.5;
}
