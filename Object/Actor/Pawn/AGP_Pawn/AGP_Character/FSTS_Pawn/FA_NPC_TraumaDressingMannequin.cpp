// All the original content belonged to the US Army


#include "FA_NPC_TraumaDressingMannequin.h"

AFA_NPC_TraumaDressingMannequin::AFA_NPC_TraumaDressingMannequin()
{
	AnimSequence	= "sitting_pose";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin.First_Aid_Mannequin"), NULL, LOAD_None, NULL);
	LoadMesh();
}