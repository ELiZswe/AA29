// All the original content belonged to the US Army


#include "FallDamage.h"

UFallDamage::UFallDamage()
{
	PawnDamageSounds = { 
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/bonebreak/bonebreak1.bonebreak1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/bonebreak/bonebreak2.bonebreak2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/bonebreak/bonebreak3.bonebreak3"), NULL, LOAD_None, NULL)
	};
	LowGoreDamageSounds = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/bonebreak/bonebreak1.bonebreak1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/bonebreak/bonebreak2.bonebreak2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/bonebreak/bonebreak3.bonebreak3"), NULL, LOAD_None, NULL)
	};
}

/*
void UFallDamage::SuicideMessage(PlayerReplicationInfo Victim)
{
	if (Victim.Level.GamePlayMode == 1)
	{
		Return "%o was injured and cannot continue.";
	}
	if (Victim.bIsFemale)
	{
		Return Default.FemaleSuicide;
	}
	else
	{
		Return Default.MaleSuicide;
	}
}
*/