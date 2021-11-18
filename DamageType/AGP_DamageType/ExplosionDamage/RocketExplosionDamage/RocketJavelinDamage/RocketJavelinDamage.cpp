// All the original content belonged to the US Army


#include "RocketJavelinDamage.h"

URocketJavelinDamage::URocketJavelinDamage()
{
	DeathString   = "%o got blown up by %k's launched rocket.";
	SplashDamage  = { 3000, 2500, 2000, 1500, 1000, 750, 350, 275 };
}