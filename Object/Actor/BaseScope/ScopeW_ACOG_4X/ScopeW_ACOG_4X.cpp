// All the original content belonged to the US Army


#include "ScopeW_ACOG_4X.h"

// Sets default values
AScopeW_ACOG_4X::AScopeW_ACOG_4X()
{
	aZoomFOV        = { 21.25f };
	tZoomOverlay    = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/acog4x32_overlay_sight_Mat.acog4x32_overlay_sight_Mat'"), NULL, LOAD_None, NULL);
	fZoomMultiplier = 4;
	bInstantZoom    = true;
}