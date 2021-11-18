// All the original content belonged to the US Army


#include "NPC_ISoldier.h"

ANPC_ISoldier::ANPC_ISoldier()
{
	MovementAnims  = {
		"PtrlWlkFwLg",
		"PtrlWlkBkLg",
		"PtrlWlkLtLg",
		"PtrlWlkRtLg"
	};
	CustomMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/EnemyInfantry.EnemyInfantry"), NULL, LOAD_None, NULL);
	LoadMesh();
}
