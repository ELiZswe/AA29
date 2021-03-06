// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AAScoreboard_UnitBoxHeader.generated.h"

class UGUIController;

class UGUIComponent;
class UGUIStyles;
UCLASS()
class UAAScoreboard_UnitBoxHeader : public UGUIComponent
{
	GENERATED_BODY()
public:
	UAAScoreboard_UnitBoxHeader();

	UPROPERTY()						FString BarStyleName;						//var string BarStyleName;
	UPROPERTY()						UGUIStyles* BarStyle;						//var XInterface.GUIStyles BarStyle;
	UPROPERTY(EditAnywhere)			TArray<float> ColumnWidths;					//var() array<float> ColumnWidths;
	UPROPERTY(EditAnywhere)			TArray<FString> ColumnHeadings;				//var() TArray<FString> ColumnHeadings;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
