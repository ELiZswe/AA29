// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_pilot/NPC_pilot.h"

ANPC_pilot::ANPC_pilot()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot.SoldierM_Pilot"), NULL, LOAD_None, NULL);
	LoadMesh();
}
