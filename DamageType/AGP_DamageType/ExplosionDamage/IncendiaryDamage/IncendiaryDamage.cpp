// All the original content belonged to the US Army


#include "IncendiaryDamage.h"

UIncendiaryDamage::UIncendiaryDamage()
{
	DeathString       = "%o was killed by %k's grenade.";
	PawnDamageSounds  = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL) };
	AmmoType          = EAmmoType::AMMO_Incendiary;
}