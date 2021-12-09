// All the original content belonged to the US Army


#include "Scope_BinocM22_A.h"

// Sets default values
AScope_BinocM22_A::AScope_BinocM22_A()
{
	aZoomFOV         = { 8.5f };
	tZoomOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/bino_m22_overlay_Mat.bino_m22_overlay_Mat'"), NULL, LOAD_None, NULL);

	fZoomMultiplier  = 10;
	bInstantZoom     = true;
}

// Called when the game starts or when spawned
void AScope_BinocM22_A::BeginPlay()
{
	Super::BeginPlay();
}

