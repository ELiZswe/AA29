// All the original content belonged to the US Army


#include "FA_NPC_DS_Mateo.h"

AFA_NPC_DS_Mateo::AFA_NPC_DS_Mateo()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Mateo.Drill_Sergeant_Mateo"), NULL, LOAD_None, NULL);
	LoadMesh();
}