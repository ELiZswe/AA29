// All the original content belonged to the US Army


#include "ScopeW_M249_SAW.h"

AScopeW_M249_SAW::AScopeW_M249_SAW()
{
	aZoomFOV           = { 70.0f };
	tZoomOverlay       = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m249_overlay_sight_Mat.m249_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	tZoomOverlayMILES  = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m249_overlay_sight_miles_Mat.m249_overlay_sight_miles_Mat'"), NULL, LOAD_None, NULL);
}