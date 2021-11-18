// All the original content belonged to the US Army


#include "ScopeW_M16A2_Rifle.h"


AScopeW_M16A2_Rifle::AScopeW_M16A2_Rifle()
{
	aZoomFOV           = { 70.0f };
	tZoomOverlay       = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight.m16a2_overlay_sight"), NULL, LOAD_None, NULL);
	tZoomOverlayMILES  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight_miles.m16a2_overlay_sight_miles"), NULL, LOAD_None, NULL);
}