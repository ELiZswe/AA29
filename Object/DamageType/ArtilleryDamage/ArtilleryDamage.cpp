// All the original content belonged to the US Army

#include "AA29/Object/DamageType/ArtilleryDamage/ArtilleryDamage.h"

UArtilleryDamage::UArtilleryDamage()
{
	DeathString       = "%o got blown up by an air strike!";
	bKUseOwnDeathVel  = true;
	PawnDamageSounds  = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL) };
	KDamageImpulse    = 35000;
	KDeathVel         = 125;
	KDeathUpKick      = 5;
	SplashDamage      = { 1000, 400, 300, 200, 150 };
	DirectDamage      = { 1000, 1000, 1000, 500, 500, 500, 500, 500, 500, 500, 400 };
}
