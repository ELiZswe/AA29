// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_ACUBasicSoldier/NPC_ACUBasicSoldier.h"

ANPC_ACUBasicSoldier::ANPC_ACUBasicSoldier()
{
	fpAudioFullVolumeRadius	= 250;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryBasicACU.InfantryBasicACU"), NULL, LOAD_None, NULL);
	LoadMesh();
}
