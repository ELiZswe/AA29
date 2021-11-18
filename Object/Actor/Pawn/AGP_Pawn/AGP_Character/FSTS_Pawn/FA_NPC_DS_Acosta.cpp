// All the original content belonged to the US Army


#include "FA_NPC_DS_Acosta.h"

AFA_NPC_DS_Acosta::AFA_NPC_DS_Acosta()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/Drill_Sergeant_Acosta.Drill_Sergeant_Acosta"), NULL, LOAD_None, NULL);
	LoadMesh();
}