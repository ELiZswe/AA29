// All the original content belonged to the US Army


#include "NPC_RealHero_Zedwick.h"

ANPC_RealHero_Zedwick::ANPC_RealHero_Zedwick()
{
	MissionID      = 3;
	MovementAnims  = {
		"Zedwick_Idle",
		"Zedwick_Idle",
		"Zedwick_Idle",
		"Zedwick_Idle"
	};
	TurnLeftAnim	= "Zedwick_Idle";
	TurnRightAnim	= "Zedwick_Idle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/RealHeroesZedwick.RealHeroesZedwick"), NULL, LOAD_None, NULL);
	LoadMesh();
}