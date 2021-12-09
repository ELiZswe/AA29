// All the original content belonged to the US Army


#include "ScopeW_M4_Rifle.h"

AScopeW_M4_Rifle::AScopeW_M4_Rifle()
{
	aZoomFOV      = { 70.0f };
	tZoomOverlay  = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight_Mat.m16a2_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	b3dSights     = true;
}