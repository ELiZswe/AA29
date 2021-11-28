// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HudOverlay/HudOverlay.h"
#include "ScriptedHudOverlay.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AScriptedHudOverlay : public AHudOverlay
{
	GENERATED_BODY()
public:
	AScriptedHudOverlay();

	UPROPERTY()					UMaterialInstance*	HUDMaterial;						//var Material HUDMaterial;
	UPROPERTY()					float				PosX;								//var float PosX;
	UPROPERTY()					float				PosY;								//var float PosY;
	UPROPERTY()					float				Width;								//var float Width;
	UPROPERTY()					float				Height;								//var float Height;

	void Render(UCanvas* C);
};
