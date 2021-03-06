// All the original content belonged to the US Army

#include "AA29/Object/DamageType/RocketAT4Damage/RocketAT4Damage.h"

URocketAT4Damage::URocketAT4Damage()
{
	DeathString       = "%o got blown up by %k's launched rocket.";
	bKUseOwnDeathVel  = true;
	PawnDamageSounds  = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL) };
	AmmoType          = EAmmoType::AMMO_Rocket;
	KDamageImpulse    = 35000;
	KDeathVel         = 125;
	KDeathUpKick      = 5;
	SplashDamage      = { 1000, 400, 300, 200, 150 };
	DirectDamage      = { 1000, 1000, 1000, 500, 500, 500, 500, 500, 500, 500, 400 };
}
