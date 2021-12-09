// All the original content belonged to the US Army


#include "ScopeW_SVD_Sniper.h"


AScopeW_SVD_Sniper::AScopeW_SVD_Sniper()
{
	iPitchOffset     = 1;
	iYawOffset       = -20;
	aZoomFOV         = { 21.25f };
	tZoomOverlay     = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/svd_overlay_sight_Mat.svd_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	fZoomMultiplier  = 4;
	bInstantZoom     = true;
	bUseAimAdjust    = true;
}