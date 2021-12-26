// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_VAEDoorman/NPC_VAEDoorman.h"

ANPC_VAEDoorman::ANPC_VAEDoorman()
{
	nameAudioToPlay				= "VAE_Terry_PleaseRegister";
	LipSincVolume				= 1;
	bNPCDisableSkinSwapping		= true;
	CustomMesh					= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/VAEemployee_ACU.VAEemployee_ACU"), NULL, LOAD_None, NULL);
	DrawScale					= 1.15;
	LoadMesh();
}
