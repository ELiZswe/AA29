// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/TEntryScreenplay/TEntryScreenplay.h"

ATEntryScreenplay::ATEntryScreenplay()
{

}

void ATEntryScreenplay::Init()
{
	NewScene("Init");
	SceneInit_Start();
	Direction("AGP_Script.Dir_SetLocation", "StartLocation;invEmpty","");
	Direction("AGP_Script.Dir_SceneEnd", "","");
	SceneInit_Finish();
	SceneEnd_Start();
	SceneEnd_Finish();
	EndScene();
}
