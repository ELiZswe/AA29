// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_DrawHUDMaterial.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_DrawHUDMaterial : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_DrawHUDMaterial();

	//UPROPERTY(EditAnywhere, Category = "Action")					UScriptedHudOverlay* Overlay;			//var ScriptedHudOverlay Overlay;
	UPROPERTY(EditAnywhere, Category = "Action")					float DisplayTime;						//var(Action) float DisplayTime;
	UPROPERTY(EditAnywhere, Category = "Action")					float Height;							//var(Action) float Height;
	UPROPERTY(EditAnywhere, Category = "Action")					float Width;							//var(Action) float Width;
	UPROPERTY(EditAnywhere, Category = "Action")					float PosY;								//var(Action) float PosY;
	UPROPERTY(EditAnywhere, Category = "Action")					float PosX;								//var(Action) float PosX;
	UPROPERTY(EditAnywhere, Category = "Action")					UMaterialInstance* HUDMaterial;			//var(Action) Material HUDMaterial;


	bool InitActionFor(UScriptedController* C);
	void ActionCompleted();
	bool CompleteWhenTriggered();
	bool CompleteWhenTimer();

};
