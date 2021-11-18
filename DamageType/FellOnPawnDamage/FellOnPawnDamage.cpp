// All the original content belonged to the US Army


#include "FellOnPawnDamage.h"

UFellOnPawnDamage::UFellOnPawnDamage()
{
	DeathString			= "%o fell, landed on someone else, and died.";
	FemaleSuicide		= "%o fell, landed on someone else, and died.";
	MaleSuicide			= "%o fell, landed on someone else, and died.";
	bLocationalHit		= false;
	bCausedByWorld		= true;
	GibModifier			= 2;
	GibPerterbation		= 0.5;
	DamageBleedPercent	= 0;
}