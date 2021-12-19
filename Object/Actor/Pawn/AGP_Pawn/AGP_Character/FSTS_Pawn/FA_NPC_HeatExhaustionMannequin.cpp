// All the original content belonged to the US Army

#include "FA_NPC_HeatExhaustionMannequin.h"

AFA_NPC_HeatExhaustionMannequin::AFA_NPC_HeatExhaustionMannequin()
{
	AlternateChestTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_MedicTraining/Mannequin/Mannequin_bdu_Shirt_loose_Mat.Mannequin_bdu_Shirt_loose_Mat'"), NULL, LOAD_None, NULL);
	AlternateChestTexture2 = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_MedicTraining/Mannequin/Mannequin_Shirt_Wet_Mat.Mannequin_Shirt_Wet_Mat'"), NULL, LOAD_None, NULL);
	AnimSequence		= "sitting_up";
	CustomMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_BCT_Characters/First_Aid_Mannequin_Hydration.First_Aid_Mannequin_Hydration'"), NULL, LOAD_None, NULL);
	LoadMesh();
}

void AFA_NPC_HeatExhaustionMannequin::PostBeginPlay()
{
	Super::PostBeginPlay();
	//LeftBoot = Spawn(class'FSTS.FA_LeftBootAttachment', Self);
	//RightBoot = Spawn(class'FSTS.FA_RightBootAttachment', Self);
	//LeftBoot.bHardAttach = true;
	//RightBoot.bHardAttach = true;
	//AttachToBone(LeftBoot, "LLegLow");
	//AttachToBone(RightBoot, "RLegLow");
}

void AFA_NPC_HeatExhaustionMannequin::AnimateStanding()
{
	DoAnimLoop();
}

void AFA_NPC_HeatExhaustionMannequin::RaiseLegs()
{
	//AnimStopLooping(AnimChannel);
	AnimSequence = "Legs_up";
	DoAnimLoop();
	//HE_EL_Lab.SpawnRuckSack();
}

void AFA_NPC_HeatExhaustionMannequin::SwitchChestTextures()
{
	//Skins[0] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_bdu_pants';
	//Skins[1] = AlternateChestTexture;
	//Skins[2] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_Hands';
	//Skins[3] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_FACE_SF_CaucA';
}

void AFA_NPC_HeatExhaustionMannequin::SwitchChestTextures2()
{
	//Skins[0] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_bdu_pants';
	//Skins[1] = AlternateChestTexture2;
	//Skins[2] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_Hands';
	//Skins[3] = Texture'T_AAO_MedicTraining.Mannequin.Mannequin_FACE_SF_CaucA';
}

void AFA_NPC_HeatExhaustionMannequin::Reset()
{
	//Skins[3] = Default.Skins[3];
	//Super::Reset();
}

