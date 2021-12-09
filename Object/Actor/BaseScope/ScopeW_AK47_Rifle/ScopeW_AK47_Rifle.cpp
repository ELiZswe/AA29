// All the original content belonged to the US Army


#include "ScopeW_AK47_Rifle.h"

AScopeW_AK47_Rifle::AScopeW_AK47_Rifle()
{
	aZoomFOV      = { 70.0f };
	tZoomOverlay  = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/ak47_overlay_sight_Mat.ak47_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	b3dSights     = true;
}
