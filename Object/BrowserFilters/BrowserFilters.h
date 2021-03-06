// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "BrowserFilters.generated.h"

class UCustomFilter;
class AFilterRule;

UCLASS()
class UBrowserFilters : public UObject
{
	GENERATED_BODY()
public:
	UBrowserFilters();

	UPROPERTY()					TArray<UCustomFilter*>		Deleted;					//var transient array<CustomFilter> Deleted;
	UPROPERTY()					TArray<UCustomFilter*>		AllFilters;					//var transient array<CustomFilter> AllFilters;
	UPROPERTY()					bool						bInvalidFilterClass;		//var bool bInvalidFilterClass;
	UPROPERTY()					UCustomFilter*				FilterClass;				//var class<CustomFilter> FilterClass;
	UPROPERTY(EditAnywhere)		FString						CustomFilterClass;			//var() config string CustomFilterClass;

	void InitCustomFilters();
	void CreateFilter(FString FilterName);
	bool AddCustomFilter(FString& NewFilterName);
	bool CopyFilter(int32 Index, FString& NewFilterName);
	bool RemoveFilter(FString FilterName);
	bool RemoveFilterAt(int32 Index);
	void SaveFilters();
	void ResetFilters();
	bool RenameFilter(int32 Index, FString NewName);
	bool ActivateFilter(int32 Index, bool Enable);
	bool IsActive(UCustomFilter* Test);
	bool IsActiveAt(int32 Index);
	void LoadSettings(int32 FilterIndex);
	FString GetFilterName(int32 Index);
	TArray<FAFilterRule> GetFilterRules(int32 Index);
	TArray<FCurrentFilter> GetFilterARules(int32 Index);
	void PostEdit(int32 Index, FString NewTitle, TArray<FAFilterRule> NewRules);
	TArray<FString> GetFilterNames(bool bActiveOnly);
	void SetRule(int32 FilterIndex, int32 RuleIndex, FString RuleTag, FString RuleItem, FString RuleValue, FString DataType, FString QueryType, FString ExtraData);
	int32 AddFilter(UCustomFilter* filter);
	bool HasFilterNamed(FString FilterName);
	int32 FindFilterIndex(FString FilterName);
	bool ValidIndex(int32 Index);
	bool ValidName(FString Test);
	int32 Count();
};
