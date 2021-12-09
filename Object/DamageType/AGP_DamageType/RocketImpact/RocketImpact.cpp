// All the original content belonged to the US Army


#include "RocketImpact.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropExplosion.h"
URocketImpact::URocketImpact()
{
	SideEffects       = { ASideEffectSlowExplosion::StaticClass(), ASideEffectViewShakeExplosion::StaticClass(), ASideEffectWeaponDropExplosion::StaticClass() };
	DeathString       = "%o got blown up by %k's launched rocket.";
	bKUseOwnDeathVel  = true;
	PawnDamageSounds  = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL) };
	AmmoType          = EAmmoType::AMMO_Rocket;
	KDamageImpulse    = 35000;
	KDeathVel         = 125;
	KDeathUpKick      = 5;
}