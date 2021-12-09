// All the original content belonged to the US Army


#include "ScopeW_M24_Sniper.h"

AScopeW_M24_Sniper::AScopeW_M24_Sniper()
{
	aZoomFOV      = { 10.0f };
	tZoomOverlay  = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/m24_overlay_sight_Mat.m24_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	bInstantZoom  = true;
}