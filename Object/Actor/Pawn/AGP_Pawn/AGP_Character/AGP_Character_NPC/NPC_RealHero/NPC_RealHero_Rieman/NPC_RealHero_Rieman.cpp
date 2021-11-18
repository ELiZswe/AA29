// All the original content belonged to the US Army


#include "NPC_RealHero_Rieman.h"

ANPC_RealHero_Rieman::ANPC_RealHero_Rieman()
{
	MovementAnims  = {
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle"
	};
	TurnLeftAnim	= "Rieman_Idle";
	TurnRightAnim	= "Rieman_Idle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/RealHeroesRieman.RealHeroesRieman"), NULL, LOAD_None, NULL);
	LoadMesh();
}