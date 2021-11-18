// All the original content belonged to the US Army


#include "ScopeW_SVD_Sniper.h"


AScopeW_SVD_Sniper::AScopeW_SVD_Sniper()
{
	iPitchOffset     = 1;
	iYawOffset       = -20;
	aZoomFOV         = { 21.25f };
	tZoomOverlay     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/svd_overlay_sight.svd_overlay_sight"), NULL, LOAD_None, NULL);
	fZoomMultiplier  = 4;
	bInstantZoom     = true;
	bUseAimAdjust    = true;
}