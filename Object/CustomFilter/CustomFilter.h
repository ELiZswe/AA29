// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "CustomFilter.generated.h"

UCLASS(Config = Game)
class UCustomFilter : public UObject
{
	GENERATED_BODY()
public:
	UCustomFilter();

	UPROPERTY()				bool					bDirty;			//var bool bDirty;
	UPROPERTY()				bool					bEnabled;		//var bool bEnabled;
	UPROPERTY()				FString					Title;			//var string Title;
	UPROPERTY()				TArray<FCurrentFilter>	AllRules;		//var array<CurrentFilter> AllRules;
	UPROPERTY(config)		bool					Active;			//var config bool Active;
	UPROPERTY(config)		FString					DefaultTitle;	//var config string DefaultTitle;
	UPROPERTY(config)		TArray<FAFilterRule>	Rules;			//var config array<AFilterRule> Rules;

	void Created();
	void CancelChanges();
	void InitializeRules();
	bool SetTitle(FString NewTitle);
	bool SetActive(bool NewActive);
	void SetRules(TArray<FCurrentFilter> NewRules);
	FString GetTitle();
	bool IsActive();
	void GetQueryRules(TArray<FAFilterRule>& OutRules);
	void GetRules(TArray<FAFilterRule>& OutRules);
	void Save(bool bForceSave);
	int32 Count();
	bool FindRule(FAFilterRule& Rule, FString ItemName, FString Value);
	bool GetRule(int32 Index, FAFilterRule& Rule);
	int32 FindRuleIndex(FString ItemName, FString Value);
	int32 FindItemIndex(FString ItemName, int32 ItemIndex);
	int32 FindLastIndex(FString ItemName);
	int32 FindInnerIndex(FString ItemName, FString Value);
	FString GetRuleKey(int32 Index);
	FString GetRuleType(int32 Index);
	FString GetRuleQueryType(int32 Index);
	TArray<FString> GetRuleValues(int32 Index);
	TArray<FCurrentFilter> GetRuleSet(FString ItemName);
	TArray<FCurrentFilter> GetRuleSetAt(int32 Index);
	void PostEdit(FString NewTitle, TArray<FAFilterRule> NewRules);
	float AddRule(FString NewName, FString NewKey, FString NewValue, EQueryType QType, EDataType DType);
	bool RemoveRule(FString ItemName);
	bool RemoveRuleAt(int32 Index);
	void ImportFilter(UCustomFilter* ImportFrom);
	void ResetRules();
	bool ChangeRule(int32 Index, FString NewTag, FString NewValue, EQueryType NewType);
	bool ValidIndex(int32 Index);
	EDataType GetDataType(FString dt);
	FString GetDataTypeString(EDataType Type);
	FString GetQueryString(EQueryType QT);
	EQueryType GetQueryType(FString QT);
	FAFilterRule StaticGenerateRule(FString FriendlyName, FString ItemName, FString ItemVal, EDataType ItemDataType, EQueryType ItemQueryType);
	FString GetUniqueName(FString Test, int32 Index);
	void ChopClass(FString& FullName);
};
