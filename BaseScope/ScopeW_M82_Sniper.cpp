// All the original content belonged to the US Army


#include "ScopeW_M82_Sniper.h"

AScopeW_M82_Sniper::AScopeW_M82_Sniper()
{
	iPitchOffset     = 2;
	iYawOffset       = 3;
	aZoomFOV         = { 8.5f };
	tZoomOverlay     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/m82a1_overlay_sight.m82a1_overlay_sight"), NULL, LOAD_None, NULL);
	fZoomMultiplier  = 10;
	bInstantZoom     = true;
}