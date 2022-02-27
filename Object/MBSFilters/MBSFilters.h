// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "MBSFilters.generated.h"

class UMBSFiltersActiveFiltersets;

UCLASS(Config = Game)
class UMBSFilters : public UObject
{
	GENERATED_BODY()
public:
	UMBSFilters();

	UPROPERTY()							int32							CurrentFilterSet;						//var int CurrentFilterSet;
	UPROPERTY()							UMBSFiltersActiveFiltersets*	ActiveFiltersets;						//var MBSFiltersActiveFiltersets ActiveFiltersets;
	UPROPERTY(config)					TArray<FFilterDesc>				Filters;								//var config array<FilterDesc> Filters;

	void OnGenerateChoices(FString CategoryName, FString FilterName);
	void CreateActiveFilterSets();
	int32 NumFilters(FString ServerBrowserType);
	FString GetCategoryName(int32 Index);
	FString GetFilterName(int32 Index);
	int32 NumFilterChoices(int32 Index);
	FString GetFilterChoiceLabel(int32 FilterIndex, int32 ChoiceIndex);
	bool IsValidFilter(FActiveFilter filter);
	bool ActivateFilter(int32 FilterIndex, int32 ChoiceIndex);
	bool DeactivateFilter(int32 FilterIndex, int32 ChoiceIndex);
	bool ActivateFilterByName(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	void HandleConflictingFilters(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	void ClearDependentFilters(FString CategoryName, FString FilterName);
	bool DeactivateFilterByName(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	bool IsFilterActive(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	int32 GetFilterIndex(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
	void SetFilterSet(int32 FilterSet);
	void ClearFilterSet();
	void DumpFilterSets();
	bool GetFilterAndChoiceIndexFromActiveFilter(int32& FilterIndex, int32& ChoiceIndex, int32 ActiveFilterIndex);
	void CreateDeploymentModeFilters(FString sDeploymentModeMap);
	TArray<FFilterItem> BuildDBMBSFilterList();
	FString BuildGameSpyFilterString();
	TArray<FKeyValuePair> BuildFilterDescriptions();
};
