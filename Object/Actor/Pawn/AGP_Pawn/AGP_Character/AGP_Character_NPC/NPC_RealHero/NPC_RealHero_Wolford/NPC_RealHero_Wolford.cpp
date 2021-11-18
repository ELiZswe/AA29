// All the original content belonged to the US Army


#include "NPC_RealHero_Wolford.h"

ANPC_RealHero_Wolford::ANPC_RealHero_Wolford()
{
	MissionID      = 2;
	MovementAnims  = {
		"Wolford_Idle",
		"Wolford_Idle",
		"Wolford_Idle",
		"Wolford_Idle"
	};
	TurnLeftAnim	= "Wolford_Idle";
	TurnRightAnim	= "Wolford_Idle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/RealHeroesWolford.RealHeroesWolford"), NULL, LOAD_None, NULL);
	LoadMesh();
}