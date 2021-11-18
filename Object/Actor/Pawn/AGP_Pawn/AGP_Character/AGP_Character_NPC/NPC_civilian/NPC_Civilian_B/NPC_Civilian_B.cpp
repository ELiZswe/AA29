// All the original content belonged to the US Army


#include "NPC_Civilian_B.h"

ANPC_Civilian_B::ANPC_Civilian_B()
{
	CustomMesh	= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/CivB.CivB"), NULL, LOAD_None, NULL);
	LoadMesh();
}