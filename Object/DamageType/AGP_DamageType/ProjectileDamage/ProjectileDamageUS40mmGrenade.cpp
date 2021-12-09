// All the original content belonged to the US Army


#include "ProjectileDamageUS40mmGrenade.h"

UProjectileDamageUS40mmGrenade::UProjectileDamageUS40mmGrenade()
{
	DeathString      = "%o got blown up by %k's 40mm Grenade.";

	PawnDamageSounds = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit2.human_dmg_bullethit2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit3.human_dmg_bullethit3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit4.human_dmg_bullethit4"), NULL, LOAD_None, NULL)
	};
	AmmoType         = EAmmoType::AMMO_GrenadeImpact;
	KDamageImpulse   = 35000;
	KDeathVel        = 125;
	SplashDamage     = { 1000, 300, 200, 150, 100, 50 };
	DirectDamage     = { 1000 };
}