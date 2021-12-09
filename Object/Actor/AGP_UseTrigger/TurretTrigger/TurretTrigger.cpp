// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_UseTrigger/TurretTrigger/TurretTrigger.h"

ATurretTrigger::ATurretTrigger()
{
	UseFOV = 85;
	bUseTriggered = true;
	bToggle = true;
	SwitchState = "Manning_Turret";
	//bStatic = true;
	//bBlockNonZeroExtentTraces = true;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_TurretTrigger.S_TurretTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}