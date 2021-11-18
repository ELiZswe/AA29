// All the original content belonged to the US Army


#include "NPC_Ambient.h"

ANPC_Ambient::ANPC_Ambient()
{
	bStaticSkinsAndMeshes  = true;
	KillHealth             = 100;
	bDummyPawn             = true;
	AnimRate               = 1;
	bDontPossess           = true;
	MovementAnims          = {
		"None",
		"None",
		"None",
		"None"
	};
	bCleanUp               = false;
	bAlwaysRelevant        = true;
	//RemoteRole = 1
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/CivilianM_B.CivilianM_B"), NULL, LOAD_None, NULL);
	bCollideWorld          = false;
	LoadMesh();
}


void ANPC_Ambient::PossessedBy(AController* C)
{

}
void ANPC_Ambient::BeginPlay()
{

}