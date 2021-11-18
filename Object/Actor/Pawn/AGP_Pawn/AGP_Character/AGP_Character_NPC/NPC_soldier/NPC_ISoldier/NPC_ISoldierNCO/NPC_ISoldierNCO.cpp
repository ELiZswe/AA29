// All the original content belonged to the US Army


#include "NPC_ISoldierNCO.h"

ANPC_ISoldierNCO::ANPC_ISoldierNCO()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/EnemyCommando.EnemyCommando"), NULL, LOAD_None, NULL);
	LoadMesh();
}