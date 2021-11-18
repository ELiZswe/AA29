// All the original content belonged to the US Army


#include "Scope_BinocNewt_B.h"

// Sets default values
AScope_BinocNewt_B::AScope_BinocNewt_B()
{
	aZoomFOV         = { 12.14f };
	tZoomOverlay     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/bino_newt_overlay.bino_newt_overlay"), NULL, LOAD_None, NULL);
	fZoomMultiplier  = 7;
	bInstantZoom     = true;
}