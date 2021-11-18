// All the original content belonged to the US Army


#include "FA_NPC_ControlBleedingMannequin.h"

AFA_NPC_ControlBleedingMannequin::AFA_NPC_ControlBleedingMannequin()
{
	//AlternateFaceTexture = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_T_FACE_SF_CaucA'
	AnimSequence	= "sitting";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin_NoHand.First_Aid_Mannequin_NoHand"), NULL, LOAD_None, NULL);
	LoadMesh();
}