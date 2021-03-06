// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageBMPAutoCannon.h"

UProjectileDamageBMPAutoCannon::UProjectileDamageBMPAutoCannon()
{
	DeathString = "%o got blown up by %k's cannon.";
	PawnDamageSounds = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit2.human_dmg_bullethit2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit3.human_dmg_bullethit3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit4.human_dmg_bullethit4"), NULL, LOAD_None, NULL)
	};
	AmmoType        = EAmmoType::AMMO_GrenadeImpact;
	KDamageImpulse  = 35000;
	KDeathVel       = 125;
	SplashDamage    = { 1000, 1000, 1000 };
	DirectDamage    = { 1000, 1000, 1000, 1000, 1000, 1000, 750, 500, 500, 500 };

}
