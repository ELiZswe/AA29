// All the original content belonged to the US Army


#include "FA_NPC_CasualtyEvalMannequin.h"

AFA_NPC_CasualtyEvalMannequin::AFA_NPC_CasualtyEvalMannequin()
{
	AnimSequence	= "Laying_Down";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin_AVPU.First_Aid_Mannequin_AVPU"), NULL, LOAD_None, NULL);
	LoadMesh();
}