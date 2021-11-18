// All the original content belonged to the US Army


#include "NPC_BHPilot.h"

ANPC_BHPilot::ANPC_BHPilot()
{
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	bDummyPawn				= true;
	AnimSequence			= "BH_Pilot";
	AnimRate				= 1;
	bDontPossess			= true;
	bDisableShadow			= true;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot.SoldierM_Pilot"), NULL, LOAD_None, NULL);
	HUDText					= "Pilot";
	LoadMesh();
}