// All the original content belonged to the US Army

#include "NPC_DS_Rieman.h"

ANPC_DS_Rieman::ANPC_DS_Rieman()
{
	IdleGestureAnims = {
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle"
	};
	ConversationalAnims = {
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk",
		"Rieman_Talk"
	};
	DSIdleAnim     = "Rieman_Idle";
	MovementAnims  = {
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle",
		"Rieman_Idle"
	};
	TurnLeftAnim   = "Rieman_Idle";
	TurnRightAnim  = "Rieman_Idle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/RealHeroesRieman.RealHeroesRieman"), NULL, LOAD_None, NULL);
	LoadMesh();
}