// All the original content belonged to the US Army


#include "FA_NPC_DS_Johnson.h"

AFA_NPC_DS_Johnson::AFA_NPC_DS_Johnson()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Johnson.Drill_Sergeant_Johnson"), NULL, LOAD_None, NULL);
	LoadMesh();
}