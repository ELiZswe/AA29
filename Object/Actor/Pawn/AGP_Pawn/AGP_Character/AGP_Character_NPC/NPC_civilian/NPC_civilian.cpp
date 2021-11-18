// All the original content belonged to the US Army


#include "NPC_civilian.h"

ANPC_civilian::ANPC_civilian() 
{
	NPC_DamageOn			= true;
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	AnimRate				= 1;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/CivilianM_B.CivilianM_B"), NULL, LOAD_None, NULL);
	bCollideActors			= false;
	LoadMesh();
}