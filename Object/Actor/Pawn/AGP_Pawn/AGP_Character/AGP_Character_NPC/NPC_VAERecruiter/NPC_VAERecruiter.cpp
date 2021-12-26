// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_VAERecruiter/NPC_VAERecruiter.h"

ANPC_VAERecruiter::ANPC_VAERecruiter()
{
	MovementAnims            = {
		"LanyardIdle",
		"LanyardIdle",
		"LanyardIdle",
		"LanyardIdle"
	};
	TurnLeftAnim			= "LanyardIdle";
	TurnRightAnim			= "LanyardIdle";
	bNPCDisableSkinSwapping	= true;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/VAE_grayshirt.VAE_grayshirt"), NULL, LOAD_None, NULL);
	DrawScale                = 1.15;
	LoadMesh();
}
