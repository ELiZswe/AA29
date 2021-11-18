// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "MBSFilters.generated.h"

class UMBSFiltersActiveFiltersets;


UCLASS()
class AA29_API UMBSFilters : public UObject
{
	GENERATED_BODY()
public:
	UMBSFilters();

	UPROPERTY()							int32							CurrentFilterSet;						//var int CurrentFilterSet;
	UPROPERTY()							UMBSFiltersActiveFiltersets*	ActiveFiltersets;						//var MBSFiltersActiveFiltersets ActiveFiltersets;
	UPROPERTY()							TArray<FFilterDesc>				Filters;								//var config array<FilterDesc> Filters;

	void OnGenerateChoices(FString CategoryName, FString FilterName);
	void CreateActiveFilterSets();
	void NumFilters(FString ServerBrowserType);
	void GetCategoryName(int32 Index);
	void GetFilterName(int32 Index);
	int32 NumFilterChoices(int32 Index);
	void GetFilterChoiceLabel(int32 FilterIndex, int32 ChoiceIndex);
	void IsValidFilter(FActiveFilter filter);
	void ActivateFilter(int32 FilterIndex, int32 ChoiceIndex);
	void DeactivateFilter(int32 FilterIndex, int32 ChoiceIndex);
	bool ActivateFilterByName(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	void HandleConflictingFilters(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	void ClearDependentFilters(FString CategoryName, FString FilterName);
	bool DeactivateFilterByName(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	bool IsFilterActive(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	void GetFilterIndex(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	void SetFilterSet(int32 FilterSet);
	void ClearFilterSet();
	void DumpFilterSets();
	void GetFilterAndChoiceIndexFromActiveFilter(int32& FilterIndex, int32& ChoiceIndex, int32 ActiveFilterIndex);
	void CreateDeploymentModeFilters(FString sDeploymentModeMap);
	void BuildDBMBSFilterList();
	FString BuildGameSpyFilterString();
	TArray<FKeyValuePair> BuildFilterDescriptions();
};
