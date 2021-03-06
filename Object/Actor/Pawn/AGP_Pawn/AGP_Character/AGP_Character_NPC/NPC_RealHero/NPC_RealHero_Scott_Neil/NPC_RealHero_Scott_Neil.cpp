// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_RealHero/NPC_RealHero_Scott_Neil/NPC_RealHero_Scott_Neil.h"

ANPC_RealHero_Scott_Neil::ANPC_RealHero_Scott_Neil()
{
	MovementAnims  = {
		"Scott_Idle",
		"Scott_Idle",
		"Scott_Idle",
		"Scott_Idle"
	};
	TurnLeftAnim	= "Scott_Idle";
	TurnRightAnim	= "Scott_Idle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/RealHeroesNeil.RealHeroesNeil"), NULL, LOAD_None, NULL);
	LoadMesh();
}
