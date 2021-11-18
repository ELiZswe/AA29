// All the original content belonged to the US Army


#include "NPC_ACUBasicSoldier.h"

ANPC_ACUBasicSoldier::ANPC_ACUBasicSoldier()
{
	fpAudioFullVolumeRadius	= 250;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryBasicACU.InfantryBasicACU"), NULL, LOAD_None, NULL);
	LoadMesh();
}