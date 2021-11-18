// All the original content belonged to the US Army


#include "ProjectileDamage.h"

#include "AA29/SideEffect/SideEffectSlow\SideEffectSlowProjectile.h"
#include "AA29/SideEffect/SideEffectViewShake\SideEffectViewShakeProjectile.h"

UProjectileDamage::UProjectileDamage()
{
	SideEffects       = { ASideEffectSlowProjectile::StaticClass(), ASideEffectViewShakeProjectile::StaticClass() };
	DeathString       = "%o was shot by %k.";
	bKUseOwnDeathVel  = true;
	PawnDamageSounds  = { 
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit1.human_dmg_bullethit1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit2.human_dmg_bullethit2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit3.human_dmg_bullethit3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit4.human_dmg_bullethit4"), NULL, LOAD_None, NULL)
	};
	LowGoreDamageSounds = {
			LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit1.human_dmg_bullethit1"), NULL, LOAD_None, NULL),
			LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit2.human_dmg_bullethit2"), NULL, LOAD_None, NULL),
			LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit3.human_dmg_bullethit3"), NULL, LOAD_None, NULL),
			LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_bullethit4.human_dmg_bullethit4"), NULL, LOAD_None, NULL)
	};
	KDamageImpulse    = 10000;
	KDeathVel         = 100;
	KDeathUpKick      = 5;
}