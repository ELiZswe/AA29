// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/EntryScreenplay/EntryScreenplay.h"

AEntryScreenplay::AEntryScreenplay()
{

}

void AEntryScreenplay::Init()
{
	NewScene("Init");
	SceneInit_Start();
	Direction("AGP_Script.Dir_RunConsoleCommand", "AGPHUD 0;","");
	Direction("AGP_Script.Dir_SetPlayerInventory", "invEmpty;", "");
	Direction("AGP_Script.Dir_Fade", "false;true;0.0;", "");
	Direction("AGP_Script.Dir_SetPlayerLocation", "startLocation;", "");
	Direction("AGP_Script.Dir_PlayerLockMovement", "true;true;", "");
	Direction("AGP_Script.Dir_RunConsoleCommand", "AGPMainMenu;", "");
	Direction("AGP_Script.Dir_Fade", "true;true;3.0;", "");
	Direction("AGP_Script.Dir_SceneEnd", "", "");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
}
