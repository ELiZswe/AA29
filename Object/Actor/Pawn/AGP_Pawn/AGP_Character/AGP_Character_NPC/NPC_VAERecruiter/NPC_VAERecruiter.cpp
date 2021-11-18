// All the original content belonged to the US Army


#include "NPC_VAERecruiter.h"

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