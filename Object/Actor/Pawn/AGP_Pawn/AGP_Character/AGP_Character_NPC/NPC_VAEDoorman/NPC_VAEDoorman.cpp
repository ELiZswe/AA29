// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_VAEDoorman/NPC_VAEDoorman.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ANPC_VAEDoorman::ANPC_VAEDoorman()
{
	nameAudioToPlay				= "VAE_Terry_PleaseRegister";
	LipSincVolume				= 1;
	bNPCDisableSkinSwapping		= true;
	CustomMesh					= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/VAEemployee_ACU.VAEemployee_ACU'"), NULL, LOAD_None, NULL);
	DrawScale					= 1.15;
	LoadMesh();
}

void ANPC_VAEDoorman::PostBeginPlay()
{
	//LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
}

void ANPC_VAEDoorman::Touch(AActor* Other)
{
	AAGP_Pawn* IDPawn = nullptr;
	/*
	if (Other.IsA("AuxCollisionCylinder"))
	{
		IDPawn = AGP_Pawn(AuxCollisionCylinder(Other).Owner);
		if (IDPawn != nullptr)
		{
			if ((IDPawn.IsHumanControlled() && (!IsPlayingLIPSincAnim())) && (!(bSpeakOnlyOnce && bAlreadySpoke)))
			{
				PlayLIPSincAnim(nameAudioToPlay, 1, 1000, 1);
				bAlreadySpoke = true;
			}
		}
	}
	*/
}
