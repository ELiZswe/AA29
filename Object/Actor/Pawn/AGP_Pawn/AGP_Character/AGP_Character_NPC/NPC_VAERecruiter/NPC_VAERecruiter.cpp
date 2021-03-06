// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_VAERecruiter/NPC_VAERecruiter.h"
#include "AA29/Object/Actor/RealHeroIcon/RealHeroIcon.h"
#include "AA29/Object/Actor/RealHeroAwarenessCylinder/RealHeroAwarenessCylinder.h"
#include "AA29/Object/Actor/RealHeroFadeInCylinder/RealHeroFadeInCylinder.h"

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
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/VAE_grayshirt.VAE_grayshirt'"), NULL, LOAD_None, NULL);
	DrawScale                = 1.15;

	PrimaryActorTick.bCanEverTick = true;

	LoadMesh();
}

void ANPC_VAERecruiter::PostBeginPlay()
{
	Super::PostBeginPlay();
	AddDefaultInventory();
	LoadSkinsAndMeshes();
}

/*
void ANPC_VAERecruiter::PossessedBy(AController* C)
{
	Super::PossessedBy(C);
}
*/

void ANPC_VAERecruiter::AnimEnd(int32 iChannel)
{
	if (iChannel == 0)
	{
		PlayWaiting();
	}
}

void ANPC_VAERecruiter::PlayWaiting()
{
	/*
	if (AnimLoopAction != "None")
	{
		LoopAnim(AnimLoopAction, 1, 0, 0);
	}
	else
	{
		if (IsAnimating(1))
		{
			AnimStopLooping(1);
		}
	}
	*/
}

void ANPC_VAERecruiter::AnimateRunning()
{
}

void ANPC_VAERecruiter::AnimateStanding()
{
}

void ANPC_VAERecruiter::PlayLanding()
{
}
