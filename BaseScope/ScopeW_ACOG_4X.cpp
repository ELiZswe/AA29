// All the original content belonged to the US Army


#include "ScopeW_ACOG_4X.h"

// Sets default values
AScopeW_ACOG_4X::AScopeW_ACOG_4X()
{
	aZoomFOV        = { 21.25f };
	tZoomOverlay    = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/acog4x32_overlay_sight.acog4x32_overlay_sight"), NULL, LOAD_None, NULL);
	fZoomMultiplier = 4;
	bInstantZoom    = true;
}