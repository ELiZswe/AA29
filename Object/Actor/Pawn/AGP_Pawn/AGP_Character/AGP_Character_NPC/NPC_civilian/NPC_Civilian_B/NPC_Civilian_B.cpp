// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_Civilian_B/NPC_Civilian_B.h"

ANPC_Civilian_B::ANPC_Civilian_B()
{
	CustomMesh	= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/CivB.CivB"), NULL, LOAD_None, NULL);
	LoadMesh();
}
