// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AAWeaponClass_UnitBoxHeader.generated.h"

class UGUIController;
class UGUIComponent;
class UGUIStyles;
UCLASS()
class UAAWeaponClass_UnitBoxHeader : public UGUIComponent
{
	GENERATED_BODY()
public:
	UAAWeaponClass_UnitBoxHeader();

	UPROPERTY()											FString BarStyleName;						//var string BarStyleName;
	UPROPERTY()											UGUIStyles* BarStyle;						//var XInterface.GUIStyles BarStyle;
	UPROPERTY()											TArray<float> ColumnWidths;					//var() array<float> ColumnWidths;
	UPROPERTY()											TArray<FString> ColumnHeadings;				//var() TArray<FString> ColumnHeadings;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
