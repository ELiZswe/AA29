// All the original content belonged to the US Army


#include "NPC_VirtualGeorge.h"

ANPC_VirtualGeorge::ANPC_VirtualGeorge()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/George_FlakVest.George_FlakVest"), NULL, LOAD_None, NULL);
	LoadMesh();
}