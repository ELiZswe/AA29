// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/NPC_DS_Lang.h"

ANPC_DS_Lang::ANPC_DS_Lang()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Lang.Drill_Sergeant_Lang"), NULL, LOAD_None, NULL);
	LoadMesh();
}
