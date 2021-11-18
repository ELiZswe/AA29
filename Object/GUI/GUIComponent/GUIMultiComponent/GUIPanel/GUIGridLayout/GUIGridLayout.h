// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "GUIGridLayout.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIGridLayout : public UGUIPanel
{
	GENERATED_BODY()
public:
	UGUIGridLayout();

	UPROPERTY()								bool						bInitialPredraw;				//var bool bInitialPredraw;
	UPROPERTY(EditAnywhere)					float						RowSpacing;						//var() float RowSpacing;
	UPROPERTY(EditAnywhere)					float						ColumnSpacing;					//var() float ColumnSpacing;
	UPROPERTY(EditAnywhere)					TArray <float>				OriginalComponentWidths;		//var() array<float> OriginalComponentWidths;
	UPROPERTY(EditAnywhere)					TArray <float>				ColumnWidths;					//var() array<float> ColumnWidths;
	UPROPERTY(EditAnywhere)					int32						NumColumns;						//var() int NumColumns;
	UPROPERTY(EditAnywhere)					TArray<FLayoutItem>			Elements;						//var() array<LayoutItem> Elements;

	void CreateItem(FString NewClass, EeCellAlign A, int32 row, int32 col);
	void addItem(UGUIComponent* NewComp, EeCellAlign A, int32 row, int32 col);
	void RemoveItem(UGUIComponent* Comp, bool bAdjustTrailingItems);
	void AddColumnWidth(float Width);

};
