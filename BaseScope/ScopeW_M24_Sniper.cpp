// All the original content belonged to the US Army


#include "ScopeW_M24_Sniper.h"

AScopeW_M24_Sniper::AScopeW_M24_Sniper()
{
	aZoomFOV      = { 10.0f };
	tZoomOverlay  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m68_overlay_sight_base.m68_overlay_sight_base"), NULL, LOAD_None, NULL);
	bInstantZoom  = true;
}