// All the original content belonged to the US Army

#include "AA29/Object/CustomFilter/CustomFilter.h"

UCustomFilter::UCustomFilter()
{

}

void UCustomFilter::Created()
{
	CancelChanges();
}

void UCustomFilter::CancelChanges()
{
	Title = DefaultTitle;
	bEnabled = Active;
	InitializeRules();
	bDirty = false;
}

void UCustomFilter::InitializeRules()
{
	int32 i = 0;
	/*
	if (AllRules.Num() > 0)
	{
		AllRules.RemoveAt(0, AllRules.Num());
	}
	for (i = 0; i < Rules.Num(); i++)
	{
		AddRule(Rules[i].ItemName, Rules[i].FilterItem.Key, Rules[i].FilterItem.Value, Rules[i].FilterItem.QueryType, Rules[i].FilterType);
	}
	*/
}

bool UCustomFilter::SetTitle(FString NewTitle)
{
	bDirty = bDirty || NewTitle != Title;
	Title = NewTitle;
	return true;
}

bool UCustomFilter::SetActive(bool NewActive)
{
	bDirty = bDirty || NewActive != bEnabled;
	bEnabled = NewActive;
	return true;
}

void UCustomFilter::SetRules(TArray<FCurrentFilter> NewRules)
{
	AllRules = NewRules;
	bDirty = true;
}

FString UCustomFilter::GetTitle()
{
	return Title;
}

bool UCustomFilter::IsActive()
{
	return bEnabled;
}

void UCustomFilter::GetQueryRules(TArray<FAFilterRule>& OutRules)
{
	Save(false);
	OutRules = Rules;
}

void UCustomFilter::GetRules(TArray<FAFilterRule>& OutRules)
{
	//OutRules = AllRules;
}

void UCustomFilter::Save(bool bForceSave)
{
	int32 i = 0;
	if (bDirty || bForceSave)
	{
		DefaultTitle = Title;
		Active = bEnabled;
		if (Rules.Num() > 0)
		{
			//Rules.RemoveAt(0, Rules.Num());
		}
		for (i = 0; i < AllRules.Num(); i++)
		{
			Rules[Rules.Num()] = AllRules[i].Item;
		}
		SaveConfig();
	}
	bDirty = false;
}

int32 UCustomFilter::Count()
{
	return AllRules.Num();
}

bool UCustomFilter::FindRule(FAFilterRule& Rule, FString ItemName, FString Value)
{
	int32 i = 0;
	i = FindRuleIndex(ItemName, Value);
	return GetRule(i, Rule);
}

bool UCustomFilter::GetRule(int32 Index, FAFilterRule& Rule)
{
	if (ValidIndex(Index))
	{
		Rule = AllRules[Index].Item;
		return true;
	}
	return false;
}

int32 UCustomFilter::FindRuleIndex(FString ItemName, FString Value)
{
	int32 i = 0;
	int32 j = 0;
	/*
	j = InStr(ItemName, ".");
	if (j != -1)
	{
		ItemName = Mid(ItemName, j + 1);
	}
	for (i = 0; i < AllRules.Num(); i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName)
		{
			if (Value == "" || Value != "" && Value ~= AllRules[i].Item.FilterItem.Value)
			{
				return i;
			}
		}
	}
	*/
	return -1;
}

int32 UCustomFilter::FindItemIndex(FString ItemName, int32 ItemIndex)
{
	int32 i = 0;
	/*
	for (i = 0; i < AllRules.Num(); i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName && AllRules[i].ItemIndex == ItemIndex)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 UCustomFilter::FindLastIndex(FString ItemName)
{
	int32 i=0;
	int32 j=0;
	j = -1;
	/*
	for (i = 0; i < AllRules.Num(); i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName && AllRules[i].ItemIndex > j)
		{
			j = AllRules[i].ItemIndex;
		}
	}
	*/
	return j;
}

int32 UCustomFilter::FindInnerIndex(FString ItemName, FString Value)
{
	int32 i = 0;
	int32 j = 0;
	/*
	j = InStr(ItemName, ".");
	if (j != -1)
	{
		ItemName = Mid(ItemName, j + 1);
	}
	for (i = 0; i < AllRules.Num(); i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName && AllRules[i].Item.FilterItem.Value ~= Value)
		{
			return AllRules[i].ItemIndex;
		}
	}
	*/
	return -1;
}

FString UCustomFilter::GetRuleKey(int32 Index)
{
	/*
	if (ValidIndex(Index))
	{
		return AllRules[Index].Item.FilterItem.Key;
	}
	*/
	return "";
}

FString UCustomFilter::GetRuleType(int32 Index)
{
	/*
	if (ValidIndex(Index))
	{
		return GetDataTypeString(AllRules[Index].Item.FilterType);
	}
	*/
	return "";
}

FString UCustomFilter::GetRuleQueryType(int32 Index)
{
	/*
	if (ValidIndex(Index))
	{
		return GetEnum(Enum'EQueryType', AllRules[Index].Item.FilterItem.QueryType);
	}
	*/
	return "";
}

TArray<FString> UCustomFilter::GetRuleValues(int32 Index)
{
	int32 i=0;
	TArray<FString> Ar = {};
	TArray<FCurrentFilter> Subset = {};
	/*
	Subset = GetRuleSetAt(Index);
	for (i = 0; i < Subset.Num(); i++)
	{
		Ar[i] = Subset[i].Item.FilterItem.Value;
	}
	*/
	return Ar;
}

TArray<FCurrentFilter> UCustomFilter::GetRuleSet(FString ItemName)
{
	int32 i=0;
	TArray<FCurrentFilter> RuleAr = {};
	/*
	ChopClass(ItemName);
	for (i = 0; i < AllRules.Num(); i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName)
		{
			RuleAr[RuleAr.Num()] = AllRules[i];
		}
	}
	*/
	return RuleAr;
}

TArray<FCurrentFilter> UCustomFilter::GetRuleSetAt(int32 Index)
{
	TArray<FCurrentFilter> RuleAr = {};
	/*
	if (ValidIndex(Index))
	{
		RuleAr = GetRuleSet(AllRules[Index].Item.FilterItem.Key);
	}
	*/
	return RuleAr;
}

void UCustomFilter::PostEdit(FString NewTitle, TArray<FAFilterRule> NewRules)
{
	int32 i = 0;
	/*
	AllRules.RemoveAt(0, AllRules.Num());
	Title = NewTitle;
	for (i = 0; i < NewRules.Num(); i++)
	{
		AddRule(NewRules[i].ItemName, NewRules[i].FilterItem.Key, NewRules[i].FilterItem.Value, NewRules[i].FilterItem.QueryType, NewRules[i].FilterType);
	}
	bDirty = true;
	Save();
	*/
}

float UCustomFilter::AddRule(FString NewName, FString NewKey, FString NewValue, EQueryType QType, EDataType DType)
{
	int32 i = 0;
	int32 j = 0;
	FCurrentFilter NewRule;
	FAFilterRule NewItem;
	FQueryData KeyPair;
	/*
	j = FindLastIndex(NewKey);
	NewRule.ItemIndex = (j + 1);
	i = AllRules.Num();
	KeyPair.Key = NewKey;
	KeyPair.Value = NewValue;
	KeyPair.QueryType = QType;
	NewItem.ItemName = NewName;
	NewItem.FilterItem = KeyPair;
	NewItem.FilterType = DType;
	NewRule.Item = NewItem;
	AllRules[i] = NewRule;
	*/
	bDirty = true;
	return float(i);
}

bool UCustomFilter::RemoveRule(FString ItemName)
{
	bool bSuccess=false;
	int32 i=0;
	/*
	for (i = AllRules.Num() - 1; i >= 0; i--)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName)
		{
			bDirty = true;
			bSuccess = true;
			AllRules.RemoveAt(i--, 1);
		}
	}
	*/
	return bSuccess;
}

bool UCustomFilter::RemoveRuleAt(int32 Index)
{
	if (ValidIndex(Index))
	{
		//return RemoveRule(AllRules[Index].Item.FilterItem.Key);
	}
	return false;
}

void UCustomFilter::ImportFilter(UCustomFilter* ImportFrom)
{
	SetTitle(ImportFrom->GetTitle());
	SetActive(ImportFrom->IsActive());
	//ImportFrom->GetRules(AllRules);
	bDirty = true;
}

void UCustomFilter::ResetRules()
{
	CancelChanges();
}

bool UCustomFilter::ChangeRule(int32 Index, FString NewTag, FString NewValue, EQueryType NewType)
{
	if (!ValidIndex(Index))
	{
		return false;
	}
	AllRules[Index].Item.ItemName = NewTag;
	AllRules[Index].Item.FilterItem.Value = NewValue;
	AllRules[Index].Item.FilterItem.QueryType = NewType;
	bDirty = true;
	return true;
}

bool UCustomFilter::ValidIndex(int32 Index)
{
	return Index >= 0 && Index < AllRules.Num();
}

EDataType UCustomFilter::GetDataType(FString dt)
{
	if (dt == "DT_Multiple")
	{
		return EDataType::DT_Multiple;
	}
	if (dt == "DT_Ranged")
	{
		return EDataType::DT_Ranged;
	}
	return EDataType::DT_Unique;
}

FString UCustomFilter::GetDataTypeString(EDataType Type)
{
	if (Type == EDataType::DT_Unique)
	{
		return "DT_Unique";
	}
	if (Type == EDataType::DT_Ranged)
	{
		return "DT_Ranged";
	}
	if (Type == EDataType::DT_Multiple)
	{
		return "DT_Multiple";
	}
	return "";
}

FString UCustomFilter::GetQueryString(EQueryType QT)
{
	switch(QT)
	{
		case EQueryType::QT_Equals:
			return "QT_Equals";
		case EQueryType::QT_NotEquals:
			return "QT_NotEquals";
		case EQueryType::QT_LessThan:
			return "QT_LessThan";
		case EQueryType::QT_LessThanEquals:
			return "QT_LessThanEquals";
		case EQueryType::QT_GreaterThan:
			return "QT_GreaterThan";
		case EQueryType::QT_GreaterThanEquals:
			return "QT_GreaterThanEquals";
		default:
			return "QT_Disabled";
	}
}

EQueryType UCustomFilter::GetQueryType(FString QT)
{
	if(QT == "QT_Equals")
	{
		return EQueryType::QT_Equals;
	}
	if(QT == "QT_NotEquals")
	{
		return EQueryType::QT_NotEquals;
	}
	if(QT == "QT_LessThan")
	{
		return EQueryType::QT_LessThan;
	}
	if(QT == "QT_LessThanEquals")
	{
		return EQueryType::QT_LessThanEquals;
	}
	if(QT == "QT_GreaterThan")
	{
		return EQueryType::QT_GreaterThan;
	}
	if (QT == "QT_GreaterThanEquals")
	{
		return EQueryType::QT_GreaterThanEquals;
	}
	return EQueryType::QT_Disabled;
}

FAFilterRule UCustomFilter::StaticGenerateRule(FString FriendlyName, FString ItemName, FString ItemVal, EDataType ItemDataType, EQueryType ItemQueryType)
{
	FAFilterRule NewItem;
	FQueryData KeyPair;
	KeyPair.Key = ItemName;
	KeyPair.Value = ItemVal;
	KeyPair.QueryType = ItemQueryType;
	NewItem.ItemName = FriendlyName;
	NewItem.FilterItem = KeyPair;
	NewItem.FilterType = ItemDataType;
	return NewItem;
}

FString UCustomFilter::GetUniqueName(FString Test, int32 Index)
{
	int32 i = 0;
	int32 j = 0;
	FString S = "";
	for (i = 0; i < AllRules.Num(); i++)
	{
		/*
		if ((AllRules[i].ItemIndex == Index) && (AllRules[i].Item.ItemName ~= Test + S))
		{
			S = " " + FString::FromInt((++j));
			i = -1;
		}
		*/
	}
	return Test + S;
}

void UCustomFilter::ChopClass(FString& FullName)
{
	/*
	int32 i = 0;
	i = InStr(FullName, ".");
	if (i >= 0)
	{
		FullName = Mid(FullName, i + 1);
		i = InStr(FullName, ".");
	}
	*/
}
