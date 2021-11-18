// All the original content belonged to the US Army


#include "ScopeW_M68_Aimpoint.h"

AScopeW_M68_Aimpoint::AScopeW_M68_Aimpoint()
{
	aZoomFOV      = { 60.0f };
	tZoomOverlay  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m68_overlay_sight_base.m68_overlay_sight_base"), NULL, LOAD_None, NULL);
	bInstantZoom  = true;
}