// All the original content belonged to the US Army


#include "ScopeW_M16A2_Rifle.h"


AScopeW_M16A2_Rifle::AScopeW_M16A2_Rifle()
{
	aZoomFOV           = { 70.0f };
	tZoomOverlay       = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight_Mat.m16a2_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	tZoomOverlayMILES  = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight_miles_Mat.m16a2_overlay_sight_miles_Mat'"), NULL, LOAD_None, NULL);
}