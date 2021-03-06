// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_ControlBleedingMannequin.h"

AFA_NPC_ControlBleedingMannequin::AFA_NPC_ControlBleedingMannequin()
{
	AlternateFaceTexture	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_MedicTraining/Mannequin/Mannequin_T_FACE_SF_CaucA_Mat.Mannequin_T_FACE_SF_CaucA_Mat'"), NULL, LOAD_None, NULL);
	AnimSequence			= "sitting";
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin_NoHand.First_Aid_Mannequin_NoHand'"), NULL, LOAD_None, NULL);
	LoadMesh();
}

void AFA_NPC_ControlBleedingMannequin::AnimateStanding()
{
	DoAnimLoop();
}

void AFA_NPC_ControlBleedingMannequin::SwitchHeadTextures()
{
	//Skins[0] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_Feet';
	//Skins[1] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_bdu_pants';
	//Skins[2] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_bdu_Shirt';
	//Skins[3] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_Hands';
	//Skins[4] = AlternateFaceTexture;
}

void AFA_NPC_ControlBleedingMannequin::Reset()
{
	//Skins[4] = Default.Skins[4];
}

