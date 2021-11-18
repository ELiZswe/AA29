// All the original content belonged to the US Army


#include "NPC_DS_Moore.h"

ANPC_DS_Moore::ANPC_DS_Moore()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Moore.Drill_Sergeant_Moore"), NULL, LOAD_None, NULL);
	LoadMesh();
}