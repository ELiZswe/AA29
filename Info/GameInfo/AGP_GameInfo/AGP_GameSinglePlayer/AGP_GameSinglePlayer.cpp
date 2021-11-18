// All the original content belonged to the US Army

#include "AA29/Info/GameInfo/AGP_GameInfo/AGP_GameSinglePlayer/AGP_GameSinglePlayer.h"


AAGP_GameSinglePlayer::AAGP_GameSinglePlayer()
{
	PlayerControllerClassName = "AGP.StudentController";
	GameName = "AGP Game - Single Player";
}

void AAGP_GameSinglePlayer::PreBeginPlay()
{
	//Super::PreBeginPlay();
	SetupAI();
}

void AAGP_GameSinglePlayer::PostBeginPlay()
{
	/*
	local Controller C;
	if ("" $ Level ~= "Entry.LevelInfo0")
	{
		C = Level.ControllerList;
		if (C != None)
		{
			if (HumanController(C) != None)
			{
				HumanController(C).DoFade(False, True, 0);
			}
			C = C.nextController;
		}
	}
	*/
}

void AAGP_GameSinglePlayer::StartMatch()
{
	/*
	local Controller C;
	StartMatch();
	if ("" $ Level ~= "Entry.LevelInfo0")
	{
		if ("" $ Class'GameEngine'.Default.GPendingLevel ~= "None")
		{
			C = Level.ControllerList;
			if (C != None)
			{
				if (HumanController(C) != None)
				{
					HumanController(C).DoFade(False, True, 0);
				}
				C = C.nextController;
			}
			SetTimer(0.1, False);
			bEntryLevelinitialized = False;
		}
	}
	*/
}

void AAGP_GameSinglePlayer::Timer()
{
	/*
	local Controller C;
	if (bEntryLevelinitialized)
	{
		Return;
	}
	bEntryLevelinitialized = true;
	C = Level.ControllerList;
	if (C != None)
	{
		if (HumanController(C) != None)
		{
			HumanController(C).EntryLevelSimulatedScreenplay();
		}
		C = C.nextController;
	}
	*/
}

void AAGP_GameSinglePlayer::SetupAI()
{
	/*
	local AI_Interface local_interface;
	local class<AI_Interface>  interface_class;
	if (!Level.allowAI)
	{
		Return;
	}
	interface_class = class<AI_Interface>(DynamicLoadObject("AGP_AI.AI_Overlord", Class'Class'));
	local_interface = Spawn(interface_class, Self);
	if (local_interface == None)
	{
		GOTO JL0077;
	}
	AI_global = local_interface;
	AI_global.Init();
JL0077:
*/
}

void AAGP_GameSinglePlayer::GetDefaultTeamClass()
{
	//Return class<Actor>(DynamicLoadObject("AGP_Characters.ClassRecruit", Class'Class'));
}