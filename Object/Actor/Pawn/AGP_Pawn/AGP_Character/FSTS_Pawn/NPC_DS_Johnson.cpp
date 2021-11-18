// All the original content belonged to the US Army


#include "NPC_DS_Johnson.h"

ANPC_DS_Johnson::ANPC_DS_Johnson()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Johnson.Drill_Sergeant_Johnson"), NULL, LOAD_None, NULL);
	LoadMesh();
}