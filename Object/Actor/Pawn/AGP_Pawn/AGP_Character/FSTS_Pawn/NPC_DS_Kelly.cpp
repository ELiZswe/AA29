// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/NPC_DS_Kelly.h"

ANPC_DS_Kelly::ANPC_DS_Kelly()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Kelly.Drill_Sergeant_Kelly"), NULL, LOAD_None, NULL);
	LoadMesh();
}
