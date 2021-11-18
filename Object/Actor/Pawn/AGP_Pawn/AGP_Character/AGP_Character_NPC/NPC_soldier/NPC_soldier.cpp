// All the original content belonged to the US Army


#include "NPC_soldier.h"

ANPC_soldier::ANPC_soldier()
{
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	AnimRate				= 1;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_InfantryB.OpforM_InfantryB"), NULL, LOAD_None, NULL);
	LoadMesh();
}