// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_RealHero/NPC_RealHero_Rieman/NPC_RealHero_Rieman.h"

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
