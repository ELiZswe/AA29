// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/NPC_DS_DSOY.h"

ANPC_DS_DSOY::ANPC_DS_DSOY()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Johnson.Drill_Sergeant_Johnson"), NULL, LOAD_None, NULL);
	LoadMesh();
}
