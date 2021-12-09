// All the original content belonged to the US Army


#include "ScopeW_M68_Aimpoint.h"

AScopeW_M68_Aimpoint::AScopeW_M68_Aimpoint()
{
	aZoomFOV      = { 60.0f };
	tZoomOverlay  = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m68_overlay_sight_base_Mat.m68_overlay_sight_base_Mat'"), NULL, LOAD_None, NULL);
	bInstantZoom  = true;
}