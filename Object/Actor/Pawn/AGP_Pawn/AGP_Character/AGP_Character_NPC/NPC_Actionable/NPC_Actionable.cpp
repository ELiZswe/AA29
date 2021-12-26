// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_Actionable/NPC_Actionable.h"

ANPC_Actionable::ANPC_Actionable()
{
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	bDummyPawn				= true;
	bCanBeCarried			= true;
	AnimRate				= 1;
	bDontPossess			= true;
	MovementAnims			= {
		"None",
		"None",
		"None",
		"None"
	};
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/CivilianM_B.CivilianM_B"), NULL, LOAD_None, NULL);
	LoadMesh();
}
