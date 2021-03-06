// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Inventory/DummyItem/Hat_Sarge/Hat_Sarge.h"

AFSTS_NPC_DrillSergeant::AFSTS_NPC_DrillSergeant()
{
	IdleGestureAnims = {
		"ae_adjustbelt",
		"ae_adjustshirt",
		"ae_brusharms",
		"ae_brushlegs",
		"ae_brushshoes_a",
		"ae_brushshoes_b",
		"ae_checkwatch_a",
		"ae_checkwatch_b",
		"ae_checkwatchbroken",
		"ae_fixbducap",
		"ae_popneck",
		"ae_popneck_warms",
		"ae_rubneck",
		"ae_scratchchest",
		"ae_scratchear_a",
		"ae_scratchear_b",
		"ae_scratcheye",
		"ae_scratchface",
		"ae_scratchhand",
		"ae_scratchleg",
		"ae_scratchnose",
		"ae_shoofly",
		"ae_stretch"
	};
	ConversationalAnims = {
		"ae_convgest_a",
		"ae_convgest_b",
		"ae_convgest_c",
		"ae_convgest_d",
		"ae_convgest_e",
		"ae_convgest_f",
		"ae_convgest_g",
		"ae_convgest_h",
		"ae_convgest_i",
		"ae_convgest_j",
		"ae_convgest_k"
	};
	DSIdleAnim                = "AE_Idle_A";
	TwitchInterval            = 60;
	//RequiredInventory = AHat_Sarge::StaticClass()
	bAbortMoveIfGoalOccupied  = false;
	//ControllerClass = ADSController::StaticClass()
	MovementAnims             = {
		"WlkFwNo",
		"WlkBkNo",
		"WlkLtNo",
		"WlkRtNo"
	};
	TurnLeftAnim              = "StdRotLtNo";
	TurnRightAnim             = "StdRotRtNo";
	UpperBodyAnim             = EUpperBodyAnim::UBANIM_NONE;
}

void AFSTS_NPC_DrillSergeant::PostBeginPlay()
{
	/*
	if ((ControllerClass != nullptr) && (Controller == nullptr))
	{
		Controller = Spawn(ControllerClass);
		if (Controller != nullptr)
		{
			ScriptedController(Controller).TakeControlOf(this);
		}
	}
	Super::PostBeginPlay();
	*/
}

