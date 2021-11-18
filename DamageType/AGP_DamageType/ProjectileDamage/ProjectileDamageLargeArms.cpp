// All the original content belonged to the US Army


#include "ProjectileDamageLargeArms.h"

UProjectileDamageLargeArms::UProjectileDamageLargeArms()
{
	fCaliber          = 12.7;
	DeathString       = "%o was sniped by %k.";
	PawnDamageSounds  = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_sniperhit1.human_dmg_sniperhit1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_sniperhit2.human_dmg_sniperhit2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_sniperhit3.human_dmg_sniperhit3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_sniperhit4.human_dmg_sniperhit4"), NULL, LOAD_None, NULL)
	};
	LowGoreDamageSounds = {
			LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_sniperhit1.human_dmg_sniperhit1"), NULL, LOAD_None, NULL),
			LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_sniperhit2.human_dmg_sniperhit2"), NULL, LOAD_None, NULL),
			LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_sniperhit3.human_dmg_sniperhit3"), NULL, LOAD_None, NULL),
			LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Damage/human_dmg_sniperhit4.human_dmg_sniperhit4"), NULL, LOAD_None, NULL)
	};
	AmmoType            = EAmmoType::AMMO_LargeArms;
	KDamageImpulse      = 50000;
	KDeathVel           = 175;
	KDeathUpKick        = 15;
}