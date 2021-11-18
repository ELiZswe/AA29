// All the original content belonged to the US Army


#include "NPC_EnemyCommando.h"

ANPC_EnemyCommando::ANPC_EnemyCommando()
{
	MovementAnims  = {
		"PtrlWlkFwLg",
		"PtrlWlkBkLg",
		"PtrlWlkLtLg",
		"PtrlWlkRtLg"
	};
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/EnemyCommando.EnemyCommando"), NULL, LOAD_None, NULL);
	LoadMesh();
}