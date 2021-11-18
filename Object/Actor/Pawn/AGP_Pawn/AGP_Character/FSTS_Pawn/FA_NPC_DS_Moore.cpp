// All the original content belonged to the US Army


#include "FA_NPC_DS_Moore.h"

AFA_NPC_DS_Moore::AFA_NPC_DS_Moore()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Moore.Drill_Sergeant_Moore"), NULL, LOAD_None, NULL);
	LoadMesh();
}