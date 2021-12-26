// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_WoundedPilot/NPC_WoundedPilot.h"

ANPC_WoundedPilot::ANPC_WoundedPilot()
{
	AnimSequence   = "wounded01_idle";
	MovementAnims = {
		"wounded01_idle",
		"wounded01_idle",
		"wounded01_idle",
		"wounded01_idle"
	};
	TurnLeftAnim	= "wounded01_idle";
	TurnRightAnim	= "wounded01_idle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot.SoldierM_Pilot"), NULL, LOAD_None, NULL);
	LoadMesh();
}

/*
simulated State BusyStanding
{
	simulated Function EndState()
	{
		LoopAnim("wounded01_idle",1,0.25);
	}
}
*/
