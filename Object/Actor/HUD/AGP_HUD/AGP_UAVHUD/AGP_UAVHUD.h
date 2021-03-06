// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AGP_UAVHUD.generated.h"

UCLASS()
class AAGP_UAVHUD : public AAGP_HUD
{
	GENERATED_BODY()
public:
	AAGP_UAVHUD(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()		FColor				colorText;							//var Color colorText;
	UPROPERTY()		UMaterialInstance*	texNightVision;						//var Texture texNightVision;
	UPROPERTY()		UMaterialInstance*	texVisionOverlay;					//var Texture texVisionOverlay;
	UPROPERTY()		float				fpTimeSinceLastButtonClicked;		//var float fpTimeSinceLastButtonClicked;
	UPROPERTY()		int32				iSizeX;								//var int32 iSizeX;
	UPROPERTY()		int32				iSizeY;								//var int32 iSizeY;
	UPROPERTY()		UFont*				fntHUD;								//var Font fntHUD;

	void DrawHUD();
	void WorldSpaceOverlays();
	void DrawHUDText(UCanvas* Canvas, FString sText, float fpScaledX, float fpScaledY, FColor colorText, ETextHorzAlignment thaAlignment);
	void DrawHUDTextUnscaled(UCanvas* Canvas, FString sText, float fpX, float fpY, FColor colorText);
	void RenderOverlays_Stage1(UCanvas* Canvas);
	void Tick(float DeltaTime);
	void ProcessButtonClicked(int32 iMouseX, int32 iMouseY);
};
