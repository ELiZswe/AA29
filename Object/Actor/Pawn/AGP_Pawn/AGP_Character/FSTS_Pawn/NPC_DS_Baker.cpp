// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/NPC_DS_Baker.h"

ANPC_DS_Baker::ANPC_DS_Baker()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Baker.Drill_Sergeant_Baker"), NULL, LOAD_None, NULL);
	LoadMesh();
}
