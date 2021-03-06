// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/LeavenworthScreenplay/LeavenworthScreenplay.h"

ALeavenworthScreenplay::ALeavenworthScreenplay()
{

}

void ALeavenworthScreenplay::Init()
{
	NewScene("Init");
	SceneInit_Start();
	Direction("AGP_Script.Dir_RunConsoleCommand", "AGPHUD 0;","");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invEmpty;", "");
	Direction("AGP_Script.Dir_Fade", "false;true;0.0;", "");
	Direction("AGP_Script.Dir_SceneEnd", "", "");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
	NewScene("Introduction");
	SceneInit_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;", "");
	Direction("AGP_Script.Dir_Fade", "true;true;3.0;", "");
	Direction("AGP_Script.Dir_StartTimer", "fadetimer;3.0;", "");
	SceneInit_Finish();
	NewEvent();
	Condition("AGP_Script.Cond_WhenTimerEnds", "fadetimer;");
	Direction("AGP_Script.Dir_SceneEnd", "", "");
	EndEvent();
	SceneEnd_Start();
	Direction("AGP_Script.Dir_PlayerLockMovement", "false;false;", "");
	SceneEnd_Finish();
	EndScene();
}

