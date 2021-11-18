// All the original content belonged to the US Army


#include "ScopeW_MosinNagant_Sniper.h"

AScopeW_MosinNagant_Sniper::AScopeW_MosinNagant_Sniper()
{
	iPitchOffset     = 2;
	iYawOffset       = 3;
	aZoomFOV         = { 21.25f };
	tZoomOverlay     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/mn_sniper_overlay_sight.mn_sniper_overlay_sight"), NULL, LOAD_None, NULL);
	fZoomMultiplier  = 4;
	b3dSights        = true;
	bInstantZoom     = true;
	bUseAimAdjust    = true;
}
