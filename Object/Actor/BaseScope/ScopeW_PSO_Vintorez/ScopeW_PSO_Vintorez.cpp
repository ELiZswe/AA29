// All the original content belonged to the US Army


#include "ScopeW_PSO_Vintorez.h"

AScopeW_PSO_Vintorez::AScopeW_PSO_Vintorez()
{
	iPitchOffset      = 1;
	iYawOffset        = -20;
	aZoomFOV          = { 21.25f };
	tZoomOverlay      = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/svd_overlay_sight_Mat.svd_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	fZoomMultiplier   = 4;
	bInstantZoom      = true;
	ScopeZoomAnimFOV  = 28;
	bUseAimAdjust     = true;
}