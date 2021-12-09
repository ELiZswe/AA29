// All the original content belonged to the US Army


#include "ScopeW_AK74su_Rifle.h"

AScopeW_AK74su_Rifle::AScopeW_AK74su_Rifle()
{
	aZoomFOV      = { 70.0f };
	tZoomOverlay  = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/ak47_overlay_sight_Mat.ak47_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	b3dSights     = true;
}