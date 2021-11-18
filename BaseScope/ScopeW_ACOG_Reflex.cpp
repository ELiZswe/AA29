// All the original content belonged to the US Army


#include "ScopeW_ACOG_Reflex.h"

// Sets default values
AScopeW_ACOG_Reflex::AScopeW_ACOG_Reflex()
{
	aZoomFOV      = { 70.0f };
	tZoomOverlay  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/acog4x32_overlay_sight.acog4x32_overlay_sight"), NULL, LOAD_None, NULL);
	b3dSights     = true;
	bInstantZoom  = true;
	bAux3dSights  = true;
}