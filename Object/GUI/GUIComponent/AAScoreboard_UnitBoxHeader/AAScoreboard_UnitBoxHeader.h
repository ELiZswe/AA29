// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AAScoreboard_UnitBoxHeader.generated.h"

class UGUIController;

UCLASS()
class AA29_API UAAScoreboard_UnitBoxHeader : public UGUIComponent
{
	GENERATED_BODY()
public:
	UAAScoreboard_UnitBoxHeader();

	UPROPERTY()											FString BarStyleName;						//var string BarStyleName;
	//UPROPERTY()											UGUIStyles* BarStyle;						//var XInterface.GUIStyles BarStyle;
	UPROPERTY()											TArray<float> ColumnWidths;					//var() array<float> ColumnWidths;
	UPROPERTY()											TArray<FString> ColumnHeadings;				//var() array<String> ColumnHeadings;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
