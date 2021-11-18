// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BrowserFilters.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UBrowserFilters : public UObject
{
	GENERATED_BODY()
public:
	UBrowserFilters();

	//UPROPERTY()			TArray<UCustomFilter*> Deleted;					//var transient array<CustomFilter> Deleted;
	//UPROPERTY()			TArray<UCustomFilter*> AllFilters;					//var transient array<CustomFilter> AllFilters;
	UPROPERTY()			bool bInvalidFilterClass;					//var bool bInvalidFilterClass;
	//UPROPERTY()			UCustomFilter* FilterClass;					//var class<CustomFilter> FilterClass;
	UPROPERTY(EditAnywhere)			FString CustomFilterClass;					//var() config string CustomFilterClass;



	void InitCustomFilters();
	void CreateFilter(FString FilterName);
	bool AddCustomFilter(FString& NewFilterName);
	bool CopyFilter(int32 Index, FString& NewFilterName);
	void RemoveFilter(FString FilterName);
	bool RemoveFilterAt(int32 Index);
	void SaveFilters();
	void ResetFilters();
	bool RenameFilter(int32 Index, FString NewName);
	void ActivateFilter(int32 Index, bool Enable);
	//void IsActive(ACustomFilter* Test);
	void IsActiveAt(int32 Index);
	void LoadSettings(int32 FilterIndex);
	void GetFilterName(int32 Index);
	void GetFilterRules(int32 Index);
	void GetFilterARules(int32 Index);
	//void PostEdit(int32 Index, FString NewTitle, array<AFilterRule> NewRules);
	void GetFilterNames(bool bActiveOnly);
	void SetRule(int32 FilterIndex, int32 RuleIndex, FString RuleTag, FString RuleItem, FString RuleValue, FString DataType, FString QueryType, FString ExtraData);
	//void AddFilter(ACustomFilter* filter);
	void HasFilterNamed(FString FilterName);
	void FindFilterIndex(FString FilterName);
	void ValidIndex(int32 Index);
	void ValidName(FString Test);
	void Count();
};
