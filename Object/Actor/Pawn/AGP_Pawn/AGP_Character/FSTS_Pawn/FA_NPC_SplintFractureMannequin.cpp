// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_SplintFractureMannequin.h"

AFA_NPC_SplintFractureMannequin::AFA_NPC_SplintFractureMannequin()
{
	AnimSequence	= "sitting_pose";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin.First_Aid_Mannequin"), NULL, LOAD_None, NULL);
	LoadMesh();
}

void AFA_NPC_SplintFractureMannequin::AnimateStanding()
{
	DoAnimLoop();
}
