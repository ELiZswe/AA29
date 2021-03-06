// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_RealHero/NPC_RealHero_Zedwick/NPC_RealHero_Zedwick.h"

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
