// All the original content belonged to the US Army


#include "ScopeW_M249_SAW.h"

AScopeW_M249_SAW::AScopeW_M249_SAW()
{
	aZoomFOV           = { 70.0f };
	tZoomOverlay       = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m249_overlay_sight.m249_overlay_sight"), NULL, LOAD_None, NULL);
	tZoomOverlayMILES  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m249_overlay_sight_miles.m249_overlay_sight_miles"), NULL, LOAD_None, NULL);
}