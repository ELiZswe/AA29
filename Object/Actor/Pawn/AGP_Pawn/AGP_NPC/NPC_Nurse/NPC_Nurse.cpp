// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_Nurse/NPC_Nurse.h"

ANPC_Nurse::ANPC_Nurse()
{
	RagdollOverride   = "CivilianF";
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/DocF_Nurse.DocF_Nurse"), NULL, LOAD_None, NULL);
	LoadMesh();
}
