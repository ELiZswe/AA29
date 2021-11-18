// All the original content belonged to the US Army


#include "NPC_AirborneSoldier.h"

ANPC_AirborneSoldier::ANPC_AirborneSoldier()
{
	bStaticSkinsAndMeshes	= false;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB"), NULL, LOAD_None, NULL);
	LoadMesh();
}