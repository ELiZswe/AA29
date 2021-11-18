// All the original content belonged to the US Army


#include "ScopeW_M4_Rifle.h"

AScopeW_M4_Rifle::AScopeW_M4_Rifle()
{
	aZoomFOV      = { 70.0f };
	tZoomOverlay  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight.m16a2_overlay_sight"), NULL, LOAD_None, NULL);
	b3dSights     = true;
}