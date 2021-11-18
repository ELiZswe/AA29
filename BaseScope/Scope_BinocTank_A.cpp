// All the original content belonged to the US Army


#include "Scope_BinocTank_A.h"

// Sets default values
AScope_BinocTank_A::AScope_BinocTank_A()
{
	aZoomFOV         = { 8.5f };
	tZoomOverlay     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/bino_tank_overlay.bino_tank_overlay"), NULL, LOAD_None, NULL);
	fZoomMultiplier  = 10;
	bInstantZoom     = true;
}