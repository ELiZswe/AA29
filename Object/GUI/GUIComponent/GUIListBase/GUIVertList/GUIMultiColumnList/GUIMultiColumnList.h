// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "GUIMultiColumnList.generated.h"

UCLASS()
class UGUIMultiColumnList : public UGUIVertList
{
	GENERATED_BODY()
public:
	UGUIMultiColumnList();

	UPROPERTY(EditAnywhere, Category = "Style")						bool ExpandLastColumn;										//var() bool ExpandLastColumn;
	UPROPERTY(EditAnywhere, Category = "Style")						bool SortDescending;										//var() bool SortDescending;
	UPROPERTY(EditAnywhere, Category = "Style")						bool NeedsSorting;											//var() bool NeedsSorting;
	UPROPERTY(EditAnywhere, Category = "Style")						int32 SortColumn;											//var() int SortColumn;
	UPROPERTY(EditAnywhere, Category = "Style")						float CellSpacing;											//var() float CellSpacing;
	UPROPERTY(EditAnywhere, Category = "Style")						TArray<float> ColumnWidths;									//var() const editconst array<float> ColumnWidths;
	UPROPERTY(EditAnywhere)											TArray<int32> InvSortData;									//var const array<int> InvSortData;
	UPROPERTY(EditAnywhere)											TArray<FMultiColumnSortData> SortData;						//var const array<MultiColumnSortData> SortData;
	UPROPERTY(EditAnywhere, Category = "Style")						TArray<FString> ColumnHeadingHints;							//var() localized array<String> ColumnHeadingHints;
	UPROPERTY(EditAnywhere, Category = "Style")						TArray<float> InitColumnPerc;								//var() array<float> InitColumnPerc;
	UPROPERTY(EditAnywhere, Category = "Style")						TArray<FString> ColumnHeadings;								//var() localized array<String> ColumnHeadings;

	void OnColumnSized(int32 Column);
	void GetListIndex(int32 YourArrayIndex);
	void ChangeSortOrder();
	void SortList();
	void UpdatedItem(int32 YourArrayIndex);
	void RemovedItem(int32 YourArrayIndex);
	void AddedItem(int32 YourArrayIndex);
	void GetSortString(int32 YourArrayIndex);
	int32 CurrentListId();
	void OnSortChanged();
	void Clear();
	void RemovedCurrent();
	void ResolutionChanged(int32 ResX, int32 ResY);
	void InitializeColumns(UCanvas* C);
	bool InternalOnPreDraw(UCanvas* C);
	void GetCellLeftWidth(int32 Column, float& Left, float& Width);
	void Sort();
	void Dump();

};
