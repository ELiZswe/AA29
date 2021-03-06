// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/AGP_FellDamage/FallDamage/FallDamage.h"
#include "AA29/AA2_PlayerState.h"

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

FString UFallDamage::SuicideMessage(AAA2_PlayerState* Victim)
{
	/*
	if (Victim->Level->GamePlayMode == GM_MILES)
	{
		return "%o was injured and cannot continue.";
	}
	if (Victim->bIsFemale)
	{
		//return Default.FemaleSuicide;
	}
	else
	{
		//return Default.MaleSuicide;
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

