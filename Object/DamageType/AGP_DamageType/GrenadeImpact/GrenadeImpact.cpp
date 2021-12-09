// All the original content belonged to the US Army


#include "GrenadeImpact.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowConcussion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeConcussion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropConcussion.h"
UGrenadeImpact::UGrenadeImpact()
{
	SideEffects       = { ASideEffectSlowConcussion::StaticClass(), ASideEffectViewShakeConcussion::StaticClass(), ASideEffectWeaponDropConcussion::StaticClass() };
	DeathString       = "%o got pegged by %k's launched grenade.";
	bKUseOwnDeathVel  = true;
	PawnDamageSounds  = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL) };
	AmmoType          = EAmmoType::AMMO_GrenadeImpact;
	KDamageImpulse    = 35000;
	KDeathVel         = 125;
	KDeathUpKick      = 5;
}