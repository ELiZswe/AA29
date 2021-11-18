// All the original content belonged to the US Army


#include "ScopeW_PSO_AK74su.h"

AScopeW_PSO_AK74su::AScopeW_PSO_AK74su()
{
	iPitchOffset      = 1;
	iYawOffset        = -20;
	aZoomFOV          = { 21.25f };
	tZoomOverlay      = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/svd_overlay_sight.svd_overlay_sight"), NULL, LOAD_None, NULL);
	fZoomMultiplier   = 4;
	bInstantZoom      = true;
	ScopeZoomAnimFOV  = 28;
	bUseAimAdjust     = true;
}
