// All the original content belonged to the US Army


#include "NPC_RealHero_Nien.h"

ANPC_RealHero_Nien::ANPC_RealHero_Nien()
{
	MovementAnims  = {
		"Nien_Idle",
		"Nien_Idle",
		"Nien_Idle",
		"Nien_Idle",
	};
	TurnLeftAnim	= "Nien_Idle";
	TurnRightAnim	= "Nien_Idle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/RealHeroesNien.RealHeroesNien"), NULL, LOAD_None, NULL);
	LoadMesh();
}