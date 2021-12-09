// All the original content belonged to the US Army


#include "ScopeW_M203_Gren.h"

AScopeW_M203_Gren::AScopeW_M203_Gren()
{
	tAuxZoomOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m203_overlay_sight_Mat.m203_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	aZoomFOV        = { 70.0f };
	tZoomOverlay    = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/m16a2_overlay_sight_Mat.m16a2_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
}