// All the original content belonged to the US Army


#include "ScopeW_ACOG_Reflex.h"

// Sets default values
AScopeW_ACOG_Reflex::AScopeW_ACOG_Reflex()
{
	aZoomFOV      = { 70.0f };
	tZoomOverlay  = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/reflex_overlay_sight_Mat.reflex_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	b3dSights     = true;
	bInstantZoom  = true;
	bAux3dSights  = true;
}