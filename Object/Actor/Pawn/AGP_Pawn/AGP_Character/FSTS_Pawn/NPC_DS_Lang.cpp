// All the original content belonged to the US Army


#include "NPC_DS_Lang.h"

ANPC_DS_Lang::ANPC_DS_Lang()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Lang.Drill_Sergeant_Lang"), NULL, LOAD_None, NULL);
	LoadMesh();
}