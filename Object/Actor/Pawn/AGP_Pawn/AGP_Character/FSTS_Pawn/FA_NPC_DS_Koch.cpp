// All the original content belonged to the US Army


#include "FA_NPC_DS_Koch.h"

AFA_NPC_DS_Koch::AFA_NPC_DS_Koch()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Koch.Drill_Sergeant_Koch"), NULL, LOAD_None, NULL);
	LoadMesh();
}