// All the original content belonged to the US Army


#include "NPC_BHCrewChief.h"

ANPC_BHCrewChief::ANPC_BHCrewChief()
{
	AnimSequence	= "BH_CrewIdle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryBasicACU.InfantryBasicACU"), NULL, LOAD_None, NULL);
	LoadMesh();
}