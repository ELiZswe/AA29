// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_Civilian_A/NPC_Civilian_A.h"

ANPC_Civilian_A::ANPC_Civilian_A()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/CivA.CivA"), NULL, LOAD_None, NULL);
	LoadMesh();
}
