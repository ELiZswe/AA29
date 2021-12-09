// All the original content belonged to the US Army


#include "Scope_BinocM24_B.h"

// Sets default values
AScope_BinocM24_B::AScope_BinocM24_B()
{
	aZoomFOV         = { 12.14f };
	tZoomOverlay     = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/bino_m24_overlay_Mat.bino_m24_overlay_Mat'"), NULL, LOAD_None, NULL);
	fZoomMultiplier  = 7;
	bInstantZoom     = true;
}
