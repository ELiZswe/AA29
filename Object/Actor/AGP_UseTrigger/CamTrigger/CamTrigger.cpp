// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_UseTrigger/CamTrigger/CamTrigger.h"

ACamTrigger::ACamTrigger()
{
	UseFOV = 85;
	bUseTriggered = true;
	SwitchState = "Viewing_RemoteCam";
	//HUDCamOverlay = Texture'T_AA2_FX.Overlay.fx2_overlay_monitor_a';
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_CamTrigger.S_CamTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

	//bBlockNonZeroExtentTraces = true;
}