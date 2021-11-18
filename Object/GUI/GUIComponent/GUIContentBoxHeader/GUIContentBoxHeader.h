// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIContentBoxHeader.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIContentBoxHeader : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIContentBoxHeader();

	UPROPERTY()														FString BarStyleName;									//var string BarStyleName;
	//UPROPERTY()														GUIStyles BarStyle;									//var XInterface.GUIStyles BarStyle;
	UPROPERTY()														TArray<float> ColumnWidths;								//var() array<float> ColumnWidths;
	UPROPERTY()														TArray <FString> ColumnHeadings;						//var() array<String> ColumnHeadings;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
