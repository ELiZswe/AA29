// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/NPC_DS_Acosta.h"

ANPC_DS_Acosta::ANPC_DS_Acosta()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Acosta.Drill_Sergeant_Acosta"), NULL, LOAD_None, NULL);
	LoadMesh();
}
