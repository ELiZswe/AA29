// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_TraumaDressingMannequin.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_BleedingControl/FA_EL_BleedingControl.h"

AFA_NPC_TraumaDressingMannequin::AFA_NPC_TraumaDressingMannequin()
{
	AnimSequence	= "sitting_pose";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin.First_Aid_Mannequin"), NULL, LOAD_None, NULL);
	LoadMesh();
}

/*
simulated State WaitForAnimFinish
{
	simulated Event AnimEnd(int32 Channel)
	{
		DoAnimLoop();
		BC_EL_Lab.SpawnRuckSack();
		GotoState("None");
	}
}
*/

void AFA_NPC_TraumaDressingMannequin::AnimateStanding()
{
	DoAnimLoop();
}

void AFA_NPC_TraumaDressingMannequin::RaiseLeftLeg()
{
	//AnimStopLooping(AnimChannel);
	//PlayAnim("Raise_Leg");
	//GotoState("WaitForAnimFinish");
	AnimSequence = "HoldLegsUp";
}

void AFA_NPC_TraumaDressingMannequin::Destroyed()
{
	BC_EL_Lab = nullptr;
	//Super::Destroyed();
}
