// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AAGUIProgressBar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAGUIProgressBar : public UGUIComponent
{
	GENERATED_BODY()
public:
	UAAGUIProgressBar();

	UPROPERTY()														float MaxValue;										//var float MaxValue;
	UPROPERTY()														float CurrentValue;									//var float CurrentValue;
	UPROPERTY()														float MinValue;										//var float MinValue;
	UPROPERTY()														UMaterialInstance* BarMaterial;						//var Material BarMaterial;
	UPROPERTY()														UMaterialInstance* BackgroundMaterial;				//var Material BackgroundMaterial;
	UPROPERTY()														FColor BarColor;									//var Object.Color BarColor;

};
