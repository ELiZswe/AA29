// All the original content belonged to the US Army


#include "FA_NPC_HeatExhaustionMannequin.h"

AFA_NPC_HeatExhaustionMannequin::AFA_NPC_HeatExhaustionMannequin()
{
	//AlternateChestTexture = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_bdu_Shirt_loose'
	//AlternateChestTexture2 = Shader'T_AAO_MedicTraining.Mannequin.Mannequin_Shirt_Wet'
	AnimSequence		= "sitting_up";
	CustomMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin_Hydration.First_Aid_Mannequin_Hydration"), NULL, LOAD_None, NULL);
	LoadMesh();
}