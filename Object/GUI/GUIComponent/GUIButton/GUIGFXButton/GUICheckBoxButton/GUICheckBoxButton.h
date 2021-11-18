// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "GUICheckBoxButton.generated.h"

class UGUIController;

UCLASS()
class AA29_API UGUICheckBoxButton : public UGUIGFXButton
{
	GENERATED_BODY()
public:
	UGUICheckBoxButton();

	UPROPERTY()														bool bAllOverlay;									//var() bool bAllOverlay;
	UPROPERTY()														TArray<UMaterialInstance*> CheckedOverlay;			//var() Material CheckedOverlay;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
