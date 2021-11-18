// All the original content belonged to the US Army


#include "ScopeW_M203_Gren.h"

AScopeW_M203_Gren::AScopeW_M203_Gren()
{
	tAuxZoomOverlay  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m203_overlay_sight.m203_overlay_sight"), NULL, LOAD_None, NULL);
	aZoomFOV         = { 70.0f };
	tZoomOverlay     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight.m16a2_overlay_sight"), NULL, LOAD_None, NULL);
}