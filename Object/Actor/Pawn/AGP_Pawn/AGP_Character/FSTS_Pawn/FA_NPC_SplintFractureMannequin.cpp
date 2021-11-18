// All the original content belonged to the US Army


#include "FA_NPC_SplintFractureMannequin.h"

AFA_NPC_SplintFractureMannequin::AFA_NPC_SplintFractureMannequin()
{
	AnimSequence	= "sitting_pose";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin.First_Aid_Mannequin"), NULL, LOAD_None, NULL);
	LoadMesh();
}